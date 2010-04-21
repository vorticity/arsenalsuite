
#include <qlayout.h>
#include <qtoolbar.h>

#include "database.h"
#include "freezercore.h"
#include "process.h"

#include "recordtreeview.h"
#include "viewcolors.h"

#include "afcommon.h"
#include "assfreezermenus.h"
#include "batchsubmitdialog.h"
#include "hostlistwidget.h"
#include "hostservice.h"
#include "items.h"
#include "joblistwidget.h"
#include "mainwindow.h"
#include "remotetailwindow.h"
#include "remotetailwidget.h"
#include "threadtasks.h"

bool HostListWidget::mStaticDataRetrieved = false;
ServiceList HostListWidget::mServiceList;

HostListWidget::HostListWidget( QWidget * parent )
: AssfreezerView( parent )
, mHostTree(0)
, mHostTaskRunning( false )
, mQueuedHostRefresh( false )
, mToolBar( 0 )
, mHostMenu( 0 )
, mTailServiceLogMenu( 0 )
, mHostServiceFilterMenu( 0 )
, mCannedBatchJobMenu( 0 )
{
	RefreshHostsAction = new QAction( "Refresh Hosts", this );
	RefreshHostsAction->setIcon( QIcon( ":/images/refresh" ) );
	HostOnlineAction = new QAction( "Set Host(s) Status to Online", this );
	HostOnlineAction->setIcon( QIcon( ":/images/host_online" ) );
	HostOfflineAction = new QAction( "Set Host(s) Status to Offline", this );
	HostOfflineAction->setIcon( QIcon( ":/images/host_offline" ) );
	HostRestartAction = new QAction( "Restart Host(s) Now", this );
	HostRestartAction->setIcon( QIcon( ":/images/host_restart" ) );
	HostRestartWhenDoneAction = new QAction( "Restart Host(s) When Done", this );
	HostRestartWhenDoneAction->setIcon( QIcon( ":/images/host_restart" ) );

	HostRebootAction = new QAction( "Reboot Host(s) Now", this );
	HostRebootAction->setIcon( QIcon( ":/images/host_reboot" ) );
	HostRebootWhenDoneAction = new QAction( "Reboot Host(s) When Done", this );
	HostRebootWhenDoneAction->setIcon( QIcon( ":/images/host_reboot" ) );

	VNCHostsAction = new QAction( "VNC Hosts", this );
	VNCHostsAction->setIcon( QIcon( ":/images/vnc_hosts.png" ) );
	ClientUpdateAction = new QAction( "Client Update", this );
	ClientUpdateAction->setIcon( QIcon( ":/images/client_update.png" ) );

	SubmitBatchJobAction = new QAction( "Assign Batch Job", this );
	ShowHostInfoAction = new QAction( "Host Info...", this );
	ClearHostErrorsSetOfflineAction = new QAction( "Clear All Errors From Host and Set It Offline", this );
	ClearHostErrorsAction = new QAction( "Clear All Errors From Host", this );
	ShowHostErrorsAction = new QAction( "Show Host Errors", this );
	ShowJobsAction = new QAction( "Show Assigned Jobs", this );

	connect( RefreshHostsAction, SIGNAL( triggered(bool) ), SLOT( refresh() ) );
	connect( HostOnlineAction, SIGNAL( triggered(bool) ), SLOT( setHostsOnline() ) );
	connect( HostOfflineAction, SIGNAL( triggered(bool) ), SLOT( setHostsOffline() ) );
	connect( HostRestartAction, SIGNAL( triggered(bool) ), SLOT( setHostsRestart() ) );
	connect( HostRestartWhenDoneAction, SIGNAL( triggered(bool) ), SLOT( setHostsRestartWhenDone() ) );
	connect( HostRebootAction, SIGNAL( triggered(bool) ), SLOT( setHostsReboot() ) );
	connect( HostRebootWhenDoneAction, SIGNAL( triggered(bool) ), SLOT( setHostsRebootWhenDone() ) );
	connect( ClientUpdateAction, SIGNAL( triggered(bool) ), SLOT( setHostsClientUpdate() ) );
	connect( VNCHostsAction, SIGNAL( triggered(bool) ), SLOT( vncHosts() ) );
	connect( ShowJobsAction, SIGNAL(triggered(bool)), SLOT( showAssignedJobs() ) );

	mHostTree = new RecordTreeView(this);
	QLayout * hbox = new QHBoxLayout(this);
	hbox->setMargin(0);
	hbox->addWidget(mHostTree);

	/* ListView connections */
	connect( mHostTree, SIGNAL( selectionChanged(RecordList) ), SLOT( hostListSelectionChanged() ) );

	mHostTree->setContextMenuPolicy( Qt::CustomContextMenu );
	connect( mHostTree, SIGNAL( customContextMenuRequested( const QPoint & ) ), SLOT( showHostPopup( const QPoint & ) ) );
	//connect( mHostTree, SIGNAL( itemDoubleClicked( QTreeWidgetItem *, int ) ), SLOT( vncHosts() ) );

	RecordSuperModel * hm = new RecordSuperModel(mHostTree);
	new HostTranslator( hm->treeBuilder() );
	hm->setAutoSort( true );
	mHostTree->setModel( hm );

	mTailServiceLogMenu = new TailServiceLogMenu( this );
	mHostServiceFilterMenu = new HostServiceFilterMenu( this );
	mCannedBatchJobMenu = new CannedBatchJobMenu( this );

	IniConfig temp;
	restore(temp);

	FreezerCore::addTask( new StaticHostListDataTask( this ) );
}

HostListWidget::~HostListWidget()
{
}

QString HostListWidget::viewType() const
{
	return "HostList";
}

void HostListWidget::save( IniConfig & ini )
{
	ini.writeString("ViewType","HostList");
	ini.writeString("ServiceFilter", mServiceFilter);
	saveHostView(mHostTree,ini);
	AssfreezerView::save(ini);
}

void HostListWidget::restore( IniConfig & ini )
{
	setupHostView(mHostTree,ini);
	AssfreezerView::restore(ini);
}

void HostListWidget::customEvent( QEvent * evt )
{
	if( ((ThreadTask*)evt)->mCancel )
		return;
		
	switch( evt->type() ) {
		case HOST_LIST:
		{
			LOG_5( "Updating host view items" );
			QTime t;
			t.start();
			HostList updated = ((HostListTask*)evt)->mReturn;
			LOG_5( "updated "+ QString::number(updated.size()) + " hosts from db" );
			mHostTree->model()->updateRecords( updated );

			LOG_5( "Enabling updates took " + QString::number( t.elapsed() ) + " ms" );

			mHostTaskRunning = false;
			if( mQueuedHostRefresh ) {
				mQueuedHostRefresh = false;
				refresh();
			} else
				clearStatusBar();
			break;
		}
		case STATIC_HOST_LIST_DATA:
		{
			mStaticDataRetrieved = true;
			StaticHostListDataTask * sdt = (StaticHostListDataTask*)evt;
			mServiceList = sdt->mServices;
			IniConfig & ini = userConfig();
			ini.pushSection( "View_" + viewName() );
			// Show All Services by default
			mServiceFilter = verifyKeyList( ini.readString( "ServiceFilter", mServiceList.keyString() ), Service::table() );
			ini.popSection();
			if( mQueuedHostRefresh ) {
				mQueuedHostRefresh = false;
				doRefresh();
			}
			break;
		}
		case UPDATE_HOST_LIST:
		{
			HostList hl = ((UpdateHostListTask*)evt)->mReturn;
			mHostTree->model()->updated(hl);
            refresh();
			break;
		}
		default:
			break;
	}
}

void HostListWidget::doRefresh()
{
	AssfreezerView::doRefresh();
	bool needStatusBarMsg = false, needHostListTask = false;

	if( !mStaticDataRetrieved )
		needStatusBarMsg = mQueuedHostRefresh = true;
	else if( mHostTaskRunning )
		mQueuedHostRefresh = true;
	else
		needStatusBarMsg = needHostListTask = true;

	if( needStatusBarMsg )
		setStatusBarMessage( "Refreshing Host List..." );

	if( needHostListTask ) {
		mHostTaskRunning = true;
		FreezerCore::addTask( new HostListTask( this, mServiceFilter, !mHostTree->isColumnHidden(15) /*Services Column*/ ) );
		FreezerCore::wakeup();
	}
}

void HostListWidget::hostListSelectionChanged()
{
	HostList hosts = mHostTree->selection();
	if( hosts.size() == 1 ) {
		setStatusBarMessage( hosts[0].name() + " Selected" );
	} else if( hosts.size() )
		setStatusBarMessage( QString::number( hosts.size() ) + " Hosts Selected" );
	else
		clearStatusBar();
}

void HostListWidget::selectHosts( HostList hosts )
{
	mHostTree->setSelection( hosts );
	mHostTree->scrollTo( hosts );
}

QToolBar * HostListWidget::toolBar( QMainWindow * mw )
{
	if( !mToolBar ) {
		mToolBar = new QToolBar( mw );
		mToolBar->addAction( RefreshHostsAction );
		mToolBar->addSeparator();
		mToolBar->addAction( HostOnlineAction );
		mToolBar->addAction( HostOfflineAction );
		mToolBar->addAction( HostRestartAction );
		mToolBar->addAction( VNCHostsAction );
	}
	return mToolBar;
}

void HostListWidget::populateViewMenu( QMenu * viewMenu )
{
	viewMenu->addMenu( mHostServiceFilterMenu );
}

void HostListWidget::setHostsStatus(const QString & status)
{
    HostList hosts = mHostTree->selection();

    foreach( Host h, hosts )
        FreezerCore::addTask( new UpdateHostListTask( this, HostList(h), status ) );
    FreezerCore::wakeup();

    HostStatusList hsl = hosts.hostStatuses();
    hsl.setSlaveStatuses(status);
}

void HostListWidget::setHostsOnline()
{
	setHostsStatus("starting");
}

void HostListWidget::setHostsOffline()
{
	setHostsStatus("stopping");
}

void HostListWidget::setHostsRestart()
{
	setHostsStatus("restart");
}

void HostListWidget::setHostsRestartWhenDone()
{
	HostList hosts = mHostTree->selection();
	if( hosts.size()==0 )
		return;

	Database::current()->exec( "UPDATE HostStatus SET slaveStatus = 'restart-when-done' WHERE fkeyHost IN(" + hosts.keyString() + ");" );
}

void HostListWidget::setHostsReboot()
{
	setHostsStatus("reboot");
}

void HostListWidget::setHostsRebootWhenDone()
{
	HostList hosts = mHostTree->selection();
	if( hosts.size()==0 )
		return;

	Database::current()->exec( "UPDATE HostStatus SET slaveStatus = 'reboot-when-done' WHERE fkeyHost IN(" + hosts.keyString() + ");" );
}

void HostListWidget::setHostsClientUpdate()
{
	setHostsStatus("client-update");
}

void HostListWidget::vncHosts()
{
	foreach( Host h, mHostTree->selection() )
		vncHost( h.name() );
}

void HostListWidget::showAssignedJobs()
{
	MainWindow * mw = qobject_cast<MainWindow*>(window());
	if( mw ) {
		JobListWidget * jobList = new JobListWidget(mw);
		jobList->setJobList( Host::activeAssignments(mHostTree->selection()).jobs() );
		mw->insertView(jobList);
		mw->setCurrentView(jobList);
	}
}

void HostListWidget::applyOptions()
{
	options.mHostColors->apply(mHostTree);
	mHostTree->setFont( options.jobFont );

	QPalette p = mHostTree->palette();
	ColorOption * co = options.mHostColors->getColorOption("Default");
	p.setColor(QPalette::Active, QPalette::AlternateBase, co->bg.darker(120));
	p.setColor(QPalette::Inactive, QPalette::AlternateBase, co->bg.darker(120));
	mHostTree->setPalette( p );

	mHostTree->update();
}

QString jobErrorAsString( const JobError & je )
{
	QDateTime dt;
	dt.setTime_t(je.errorTime());
	return "[" + je.host().name() + "; " + dt.toString() + "; Frames " + je.frames() + "]\n" + je.message();
}

QString verifyKeyList( const QString & list, Table * table )
{
	QList<uint> keys;
	QStringList sl = list.split(',');
	foreach( QString key, sl )
		keys += key.toInt();
	return table->records(keys).keyString();
}

void clearHostErrorsAndSetOffline( HostList hosts, bool offline)
{
	if( hosts.isEmpty() ) return;

	QString subject = "Setting Hosts Offline for repair: " + hosts.names().join(",");
	QString body = subject + "\\nAll Current Errors have been cleared";
	foreach( Host h, hosts ) {
		body += h.name() + "\\n";
		JobErrorList errors = JobError::select("fkeyhost=? order by errortime desc limit 10", VarList() << h.key());
		if( !errors.isEmpty() ) {
			body += "\\n";
			foreach(JobError je, errors)
				body += jobErrorAsString(je).replace("\n","\\n").replace("'","") + "\\n";
		}
		body += "\\n\\n";
	}

	if (offline) {
		QString from = User::currentUser().name() + "@blur.com";
		sendEmail( QStringList() << "it@blur.com", subject, body, from );
	}

	Database::current()->beginTransaction();
	Database::current()->exec( "UPDATE JobError SET cleared=true WHERE fkeyhost IN (" + hosts.keyString() + ")" );
	if (offline) {
		HostStatusList hsl = hosts.hostStatuses();
		hsl.setSlaveStatuses( "offline" );
		hsl.commit();
	}
	Database::current()->commitTransaction();
}

void HostListWidget::showHostPopup(const QPoint & point)
{
	if( !mHostMenu ) mHostMenu = new AssfreezerHostMenu( this );
	mHostMenu->popup( mHostTree->mapToGlobal(point) );
}
