
#include <algorithm>

#include <qmap.h>
#include <qpair.h>
#include <qvariant.h>

#include "interval.h"
#include "qvariantcmp.h"

#include "supermodel.h"

#include <stdio.h>
#include <typeinfo>


ModelTreeBuilder::ModelTreeBuilder( SuperModel * parent )
: QObject( parent )
, mModel( parent )
, mLoadingNode( 0 )
{
}

ModelTreeBuilder::~ModelTreeBuilder()
{
	foreach( ModelDataTranslator * trans, mTranslators )
		delete trans;
}

bool ModelTreeBuilder::hasChildren( const QModelIndex &, SuperModel *  )
{
	return false;
}

void ModelTreeBuilder::loadChildren( const QModelIndex & parentIndex, SuperModel * model )
{
	Q_UNUSED(parentIndex);
	Q_UNUSED(model);
}

int ModelTreeBuilder::compare( const QModelIndex & a, const QModelIndex & b, QList<int> columns, bool asc )
{
	Q_UNUSED(asc);
	foreach( int col, columns ) {
		int result = qVariantCmp( a.sibling(a.row(),col).data(Qt::DisplayRole), b.sibling(b.row(),col).data(Qt::DisplayRole) );
		if( result != 0 ) return result;
	}
	return 0;
}

void ModelTreeBuilder::_loadChildren( const QModelIndex & parentIndex, SuperModel * model, ModelNode * node )
{
	ModelNode * previousLoadingNode = mLoadingNode;
	mLoadingNode = node;
	node->setTranslator(defaultTranslator());
	loadChildren(parentIndex,model);
	mLoadingNode = previousLoadingNode;
}

void ModelTreeBuilder::setTranslator( ModelDataTranslator * trans )
{
	if( mLoadingNode && !mLoadingNode->translator() ) mLoadingNode->setTranslator(trans);
}

ModelDataTranslator * ModelTreeBuilder::defaultTranslator()
{
	if( !mTranslators.isEmpty() ) return mTranslators[0];
	return 0;
}

void ModelTreeBuilder::addTranslator(ModelDataTranslator * trans)
{
	mTranslators += trans;
}

// builder takes ownership of this
ModelDataTranslator::ModelDataTranslator( ModelTreeBuilder * builder )
: mBuilder( builder )
{
	builder->addTranslator(this);
}

QModelIndex ModelDataTranslator::insert( int row, const QModelIndex & parent )
{
	return model()->insert(parent,row,this);
}

QModelIndex ModelDataTranslator::append( const QModelIndex & parent )
{
	return model()->append(parent,this);
}

void * ModelDataTranslator::dataPtr( const QModelIndex & idx )
{ return idx.isValid() ? ((SuperModel*)idx.model())->indexToNode(idx)->itemData(idx) : 0; }

ModelDataTranslator * ModelDataTranslator::translator( const QModelIndex & idx )
{ return idx.isValid() ? ((SuperModel*)idx.model())->translator(idx) : 0; }

int ItemBase::compare( const QModelIndex & idx, const QModelIndex & idx2, int column, bool  ) const
{ 
	Q_UNUSED(column);
	return qVariantCmp(idx.data(Qt::DisplayRole),idx2.data(Qt::DisplayRole)); 
}

int StandardItem::findItem(int column, int role ) const {
	for( int i=0; i < mData.size(); ++i ) {
		const DataItem & item = mData[i];
		if( item.column == column && item.role == role )
			return i;
	}
	return -1;
}
QVariant StandardItem::modelData( const QModelIndex & idx, int role ) const
{
	int i = findItem(idx.column(),role);
	return i>=0 ? mData[i].data : QVariant();
}
bool StandardItem::setModelData( const QModelIndex & idx, const QVariant & value, int role )
{
	int i = findItem(idx.column(),role);
	if( i < 0 ) {
		i = mData.size();
		DataItem item;
		item.role = role;
		item.column = idx.column();
		mData.append( item );
	}
	mData[i].data = value;
	return true;
}


inline QModelIndex SuperModel::nodeToIndex( int row, int column, ModelNode * node )
{
	return createIndex( row, column, node );
}

ModelNode::ModelNode( ModelNode * parent, int parentRow )
: mRowCount( 0 )
, mTranslator( 0 )
, mParent( parent )
, mParentRow( parentRow )
{
	if( mParent && !mTranslator ) mTranslator = mParent->mTranslator;
}

ModelNode::~ModelNode()
{
	clear();
}

void ModelNode::clear()
{
	for( int i=rowCount()-1; i>=0; i-- ) {
		ItemInfo ii = rowToItemInfo(i);
		mTranslator->deleteData( _itemData(ii.dataOffset) );
		if( ii.index < (uint)mChildren.size() ) {
			ModelNode * child = mChildren[ii.index];
			if( child && child != (ModelNode*)1 )
				delete child;
		}
	}
	mNoChildrenArray.clear();
	mChildren.clear();

	mItemInfoVector.clear();

	mRowCount = 0;
	mItemData.clear();
}

void ModelNode::setTranslator( ModelDataTranslator * translator )
{
	mTranslator = translator;
}

bool ModelNode::insertChildren( int index, int count, ModelDataTranslator * translator )
{
	if( index > mRowCount || index < 0 ) return false;

	if( translator == 0 )
		translator = mTranslator;

	int translatorIdx = 0;
	if( mTranslator != translator ) {
		if( mTranslator == 0 ) 
			mTranslator = translator;
		else {
			translatorIdx = mTranslatorList.indexOf(translator);
			if( translatorIdx == -1 ) {
				if( mTranslatorList.isEmpty() ) mTranslatorList.append( mTranslator );
				translatorIdx = mTranslatorList.size();
				mTranslatorList.append(translator);
			}
		}
	}
		
	int dataSize = translator->dataSize();

	// Extend item data
	// TODO: Reuse storage from deleted items
	// TODO: We may want to keep things aligned if size >= 4 bytes
	int startDataOffset = mItemData.size(), startIndex = mNoChildrenArray.size();
	mItemData.resize( mItemData.size() + count * dataSize );

	QVector<int> dataOffsets(count), indexes(count);

	mItemInfoVector.insert( index, count, ItemInfo() );
	mNoChildrenArray.resize( startIndex + count );

	for( int i = count-1; i >= 0; --i ) {
		ItemInfo & ii = mItemInfoVector[index+i];
		ii.index = startIndex + i;
		ii.dataOffset = startDataOffset + i * dataSize;
		ii.translatorIndex = translatorIdx;
		translator->constructData( _itemData(ii.dataOffset) );
	}

	mRowCount += count;
	return true;
}

// Tree Builder is responsible for clearing the data
// before calling removeChildren
bool ModelNode::removeChildren( int index, int count )
{
	if( count < 0 || index < 0 || index + count > mRowCount ) return false;

	for( int i = index + count - 1; i >= index; --i ) {
		ItemInfo ii = rowToItemInfo(i);
		// Destruct the data
		mTranslator->deleteData( _itemData( ii.dataOffset ) );
		if( ii.index < (uint)mChildren.size() ) {
			ModelNode * children = mChildren[ii.index];
			if( children && children != (ModelNode*)1 )
				delete children;
			mChildren[ii.index] = 0;
		}
	}
	mItemInfoVector.remove(index,count);
	mRowCount -= count;
	return true;
}

bool ModelNode::hasChildren( const QModelIndex & idx, bool insert ) {
	int index = rowToItemInfo(idx.row()).index;
	if( mNoChildrenArray.at(index) ) {
		if( insert ) mNoChildrenArray.clearBit(index);
		else return false;
	}
	if( insert || mChildren.size() <= index || mChildren.at(index) == 0 ) {
		if( !insert ) {
			bool hasChildren = model(idx)->treeBuilder()->hasChildren(idx,model(idx)); // TODO Fetch From Tree Builder
			if( !hasChildren ) {
				mNoChildrenArray.setBit( index, true );
				return false;
			}
		}
		
		if( mChildren.size() <= index )
			mChildren.resize(index + 1);
		if( !mChildren[index] )
			mChildren[index] = (ModelNode*)1;
		return true;
	}
	if( mChildren.size() > index ) {
		ModelNode * node = mChildren.at(index);
		if( node && node != (ModelNode*)1 ) return node->rowCount();
	}
	return true;
}

ModelNode * ModelNode::child( const QModelIndex & idx, bool insert )
{
	if( !hasChildren(idx,insert) ) return 0;
	// If hasChildren returns true, then we at least have a spot in mChildren
	int index = rowToItemInfo(idx.row()).index;
	ModelNode * node = mChildren[index];
	if( node == (ModelNode*)1 ) {
		node = new ModelNode(this,idx.row());
		mChildren[index] = node;
		// Should we give the treebuilder a chance to load children
		// if insert has been called but these children were never
		// asked for, therefore never given a chance to be loaded
		// by treeBuilder?  That at least means the caller of insert
		// has not even called rowCount, so they are inserting at row 0
		if( !insert )
			model(idx)->treeBuilder()->_loadChildren(idx,model(idx),node);
		return node;
	}
	return node;
}

bool ModelNode::childrenLoaded( const QModelIndex & idx ) {
	int index = rowToItemInfo(idx.row()).index;
	if( mNoChildrenArray.at(index) )
		return true;
	if( index < mChildren.size() ) {
		ModelNode * node = mChildren.at(index);
		if( node == 0 || node == (ModelNode*)1 ) return false;
		return true;
	}
	return false;
}

void ModelNode::clearChildren( const QModelIndex & idx ) {
	int index = rowToItemInfo(idx.row()).index;
	if( mNoChildrenArray.at(index) ) {
		return;
	}
	if( index < mChildren.size() ) {
		ModelNode * child = mChildren.at(index);
		delete child;
		mChildren[index] = 0;
	}
}

void ModelNode::swap( const QModelIndex & a, const QModelIndex & b )
{
	ItemInfo & info_a = rowToItemInfo(a.row()), & info_b = rowToItemInfo(b.row());
	ItemInfo copy = info_a;
	info_a = info_b;
	info_b = copy;
	SuperModel * sm = model(a);
	QModelIndexList from, to;
	for( int i=sm->columnCount(a)-1; i>=0; i--) {
		from << a.sibling(a.row(), i);
		to << a.sibling(b.row(), i);

		from << a.sibling(b.row(), i);
		to << a.sibling(a.row(), i);
	}
	sm->changePersistentIndexList(from,to);
}

int ModelNode::rowCount()
{
	return mRowCount;
}

inline ModelNode::ItemInfo & ModelNode::rowToItemInfo(int row)
{
	return mItemInfoVector[row];
}

inline ModelDataTranslator * ModelNode::_translator(int translatorIndex) const
{
	if( translatorIndex == 0 ) return mTranslator;
	return mTranslatorList[translatorIndex];
}

ModelDataTranslator * ModelNode::translator(const QModelIndex & idx)
{
	if( idx.internalPointer() == this && idx.row() >= 0 && idx.row() < mRowCount )
		return _translator(rowToItemInfo(idx.row()).translatorIndex);
	return 0;
}

inline void * ModelNode::_itemData( int dataOffset )
{
	return &mItemData.data()[dataOffset];
}

QVariant ModelNode::data( const QModelIndex & idx, int role ) {
	ItemInfo ii = rowToItemInfo(idx.row());
	return _translator(ii.translatorIndex)->modelData( _itemData(ii.dataOffset), idx, role );
}

bool ModelNode::setData( const QModelIndex & idx, const QVariant & value, int role ) {
	ItemInfo ii = rowToItemInfo(idx.row());
	return _translator(ii.translatorIndex)->setModelData( _itemData(ii.dataOffset), idx, value, role );
}

Qt::ItemFlags ModelNode::flags( const QModelIndex & idx ) {
	ItemInfo ii = rowToItemInfo(idx.row());
	return _translator(ii.translatorIndex)->modelFlags( _itemData(ii.dataOffset), idx );
}

SuperModel * ModelNode::model(const QModelIndex &idx)
{
	return const_cast<SuperModel*>(reinterpret_cast<const SuperModel*>(idx.model()));
}

void * ModelNode::itemData( const QModelIndex & idx )
{
	if( idx.internalPointer() == this ) return _itemData(rowToItemInfo(idx.row()).dataOffset);
	return 0;
}

int ModelNode::compare( const QModelIndex & idx1, const QModelIndex & idx2, const QList<int> & columns, bool asc )
{
	ItemInfo ii1 = rowToItemInfo(idx1.row()), ii2 = rowToItemInfo(idx2.row());
	// To compare 2 rows of the same type, we use the translator to compare
	if( ii1.translatorIndex == ii2.translatorIndex ) {
		void * ptr1 = _itemData(ii1.dataOffset), * ptr2 = _itemData(ii2.dataOffset);
		ModelDataTranslator * trans = _translator(ii1.translatorIndex);
		foreach( int column, columns ) {
			int result = trans->compare( ptr1, ptr2, idx1.sibling(idx1.row(),column), idx2.sibling(idx2.row(),column), column, asc );
			// Compare pointers if the items are equal in other respects
			if( result != 0 )
				return result;
		}
		return (ptr1 > ptr2 ? 1 : -1);
	}
	// Two rows of different types are compared through the tree builder
	else {
		SuperModel * mdl = model(idx1);
		return mdl->treeBuilder()->compare( idx1, idx2, columns, asc );
	}
	return 0;
}

struct ModelNode::NodeSorter
{
	NodeSorter( ModelNode * node, const QList<int> & columns, bool asc, const QModelIndex & parent ) : mNode(node), mColumns(columns), mAsc( asc ), mParent(parent) {}
	bool operator()( int row1, int row2 ) {
		int result = mNode->compare( mParent.child( row1, 0 ), mParent.child( row2, 0 ), mColumns, mAsc );
		return (result > 0) == mAsc;
	}
	ModelNode * mNode;
	const QList<int> & mColumns;
	bool mAsc;
	QModelIndex mParent;
};

void ModelNode::sort ( const QList<int> & columns, bool asc, bool recursive, const QModelIndex & parent, int start, int end )
{
	if( rowCount() <= 0 ) return;

	start = qMax(0,start);
	if( end == -1 ) end = rowCount() - 1;
	end = qMin(rowCount() - 1,end);
	
	if( end <= start ) return;

	QVector<int> sortVector(rowCount());
	for( int i = rowCount()-1; i>=0; --i )
		sortVector[i] = i;

	// Sort it
	std::stable_sort( 
		&sortVector[start],
		&sortVector[end] + 1,
		NodeSorter( this, columns, asc, parent )
	);

	QVector<ItemInfo> newItemInfoVector(mItemInfoVector.size());
	QModelIndexList from, to;
	SuperModel * sm = model(parent);
	QModelIndexList persist = sm->persistentIndexList();
	// Marks which columns we need to report persistent index changes
	int cc = sm->columnCount(sm->index(0,0,parent));
	QBitArray needColumnPIC(cc);
	int pic_last = 0;
	foreach( QModelIndex i, persist ) {
		QModelIndex par = i.parent();
		if( par == parent || (!par.isValid() && !parent.isValid()) ) {
			int col = i.column();
			if( col >= 0 && !needColumnPIC[col] ) {
				needColumnPIC[col] = true;
				pic_last = qMax(pic_last,col+1);
			}
		}
	}
	for( int i = rowCount() - 1; i>=0; --i ) {
		int fromIndex = sortVector[i];
		if( fromIndex != i ) {
			for( int c = 0; c < pic_last; ++c ) {
				if( needColumnPIC[c] ) {
					from.append( sm->nodeToIndex(fromIndex,c,this) );
					to.append( sm->nodeToIndex(i,c,this) );
				}
			}
		}
		newItemInfoVector[i] = mItemInfoVector[fromIndex];
		if( (uint)mChildren.size() > newItemInfoVector[i].index ) {
			ModelNode * child = mChildren[newItemInfoVector[i].index];
			if( child && child != (ModelNode*)1 )
				child->mParentRow = i;
		}
	}
	sm->changePersistentIndexList(from,to);

	mItemInfoVector = newItemInfoVector;

	if( recursive ) {
		for( int i=start; i<=end; i++ ) {
			QModelIndex idx = parent.child(i,0);
			if( idx.isValid() && childrenLoaded(idx) ) {
				ModelNode * _child = child(idx);
				if( _child )
					_child->sort( columns, asc, true, idx, 0, -1 );
			}
		}
	}
}

SuperModel::SuperModel( QObject * parent )
: QAbstractItemModel( parent )
, mRootNode( 0 )
, mTreeBuilder( 0 )
, mInsertClosureNode( 0 )
, mBlockInsertNots( false )
, mSortOrder( Qt::DescendingOrder )
, mAutoSort( false )
, mAssumeChildren( false )
, mDisableChildLoading( false )
{
	
}

SuperModel::~SuperModel()
{
	delete mRootNode;
}

ModelTreeBuilder * SuperModel::treeBuilder()
{
	if( !mTreeBuilder ) mTreeBuilder = new ModelTreeBuilder(this);
	return mTreeBuilder;
}

void SuperModel::setTreeBuilder( ModelTreeBuilder * treeBuilder )
{
	mTreeBuilder = treeBuilder;
}

ModelNode * SuperModel::rootNode() const
{
	if( !mRootNode ) {
		mRootNode = new ModelNode(0,0);
		mTreeBuilder->_loadChildren( QModelIndex(), const_cast<SuperModel*>(this), mRootNode );
	}
	return mRootNode;
}

QModelIndex SuperModel::parent( const QModelIndex & idx ) const
{
	if( !idx.isValid() ) return QModelIndex();
	ModelNode * node = indexToNode(idx);
	if( node->mParent ) return createIndex( node->mParentRow, 0, node->mParent );
	return QModelIndex();
}

QModelIndex SuperModel::sibling( int row, int column, const QModelIndex & idx ) const
{
	if( !idx.isValid() || row < 0 ) return QModelIndex();
	ModelNode * node = indexToNode(idx);
	if( row >= node->rowCount() ) return QModelIndex();
	return createIndex( row, column, node );
}

QModelIndex SuperModel::index( int row, int column, const QModelIndex & parent ) const
{
	if( row < 0 || column < 0 ) return QModelIndex();
	ModelNode * childNode = 0;
	bool restoreBlockInsertNots = mBlockInsertNots;
	mBlockInsertNots = true;
	if( parent.isValid() ) {
		ModelNode * node = indexToNode(parent);
		childNode = node->child(parent);
	} else
		childNode = rootNode();
	QModelIndex ret;
	if( childNode && row < childNode->rowCount() )
		ret = createIndex( row, column, childNode );
	mBlockInsertNots = restoreBlockInsertNots;
	return ret;
}

int SuperModel::rowCount( const QModelIndex & parent ) const
{
	if( !parent.isValid() ) return rootNode() ? rootNode()->rowCount() : 0;
	ModelNode * node = indexToNode(parent);
	bool restoreBlockInsertNots = mBlockInsertNots;
	mBlockInsertNots = true;
	ModelNode * childNode = node->child(parent);
	int ret = (childNode ? childNode->rowCount() : 0);
	mBlockInsertNots = restoreBlockInsertNots;
	return ret;
}

bool SuperModel::hasChildren( const QModelIndex & parent ) const
{
	if( !parent.isValid() ) return rootNode()->rowCount() > 0;
	ModelNode * node = indexToNode(parent);
	return node->hasChildren(parent);
}

bool SuperModel::childrenLoaded( const QModelIndex & parent )
{
	if( !parent.isValid() ) return bool(rootNode());
	ModelNode * node = indexToNode(parent);
	return node->childrenLoaded(parent);
}

int SuperModel::columnCount( const QModelIndex & ) const
{
	return mHeaderData.size();
}

QVariant SuperModel::data ( const QModelIndex & index, int role ) const
{
	if( !index.isValid() ) return QVariant();
	QVariant ret = indexToNode(index)->data(index, role);
	// Convert Interval types to strings
	if( ret.userType() == qMetaTypeId<Interval>() )
		return qvariant_cast<Interval>(ret).toDisplayString();
	return ret;
}

bool SuperModel::setData ( const QModelIndex & index, const QVariant & value, int role )
{
	if( !index.isValid() ) return false;
	bool set = indexToNode(index)->setData(index, value, role);
	if( set )
		emit dataChanged(index,index);
	return set;
}

bool SuperModel::dropMimeData( const QMimeData *, Qt::DropAction , int , int, const QModelIndex & )
{
	return false;
}

Qt::ItemFlags SuperModel::flags ( const QModelIndex & index ) const
{
	if( !index.isValid() ) return Qt::ItemFlags(0);
	return indexToNode(index)->flags(index);
}

QModelIndex SuperModel::insert( const QModelIndex & par, int row, ModelDataTranslator * trans )
{
	QList<QModelIndex> ret = insert( par, row, 1, trans );
	return ret.isEmpty() ? QModelIndex() : ret[0];
}

QModelIndexList SuperModel::insert( const QModelIndex & par, int row, int count, ModelDataTranslator * trans )
{
	QModelIndexList ret;
	if( count < 1 || row > rowCount(par) || row < 0 ) {
		if( mInsertClosureNode && mInsertClosureNode->state == 0 )
			mInsertClosureNode->state = 2;
		return ret;
	}
	ModelNode * node = par.isValid() ? indexToNode(par)->child(par,true) : rootNode();
	if( node ) {
		if( !mBlockInsertNots )
			beginInsertRows( par, row, row + count - 1 );

		if( node->insertChildren( row, count, trans ) ) {
			for( int i = row; i < row + count; i++ )
				ret += createIndex( i, 0, node );
		}
		if( mInsertClosureNode && mInsertClosureNode->state == 0 ) {
			mInsertClosureNode->state = mBlockInsertNots ? 2 : 1;
			mInsertClosureNode->parent = par;
		} else {
			checkAutoSort(par,true);
			if( !mBlockInsertNots )
				endInsertRows();
		}
	}
	return ret;
}

bool SuperModel::removeRows( int start, int count, const QModelIndex & parent )
{
	if( start < 0 || count < 1 || start + count > rowCount(parent) ) return false;
	ModelNode * node = parent.isValid() ? indexToNode(parent)->child(parent) : rootNode();
	bool ret = false;
	if( node ) {
		beginRemoveRows( parent, start, start + count - 1 );
		ret = node->removeChildren( start, count );
		endRemoveRows();
	}
	return ret;
}

void SuperModel::clear()
{
	removeRows( 0, rowCount() );
}

void SuperModel::remove( const QModelIndex & i )
{
	removeRows( i.row(), 1, i.parent() );
}

/// Groups rows by parent index
/// Then removes from highest row to lowest, calling removeRows
/// for each continuous range.
void SuperModel::remove( QModelIndexList list )
{
	typedef QPair<QPersistentModelIndex,bool> PIV;
	typedef QMap<PIV, QList<int> > QML;
	QML rowsByParent;
	foreach( QModelIndex i, list ) {
		QModelIndex p = i.parent();
		rowsByParent[PIV(p,p.isValid())].append(i.row());
	}
	for( QML::iterator it = rowsByParent.begin(); it != rowsByParent.end(); ++it ) {
		PIV piv = it.key();
		QPersistentModelIndex pmi = piv.first;
		if( pmi.isValid() == piv.second ) {
			QList<int> & rl = it.value();
			qSort(rl);
			int first = -1, last = -1;
			for( int i=rl.size()-1; i>=0; i-- ) {
				int row = rl.at(i);
				if( first == -1 ) { first = last = row; }
				if( row < first - 1 ) {
					removeRows( first, last - first + 1, pmi );
					last = row;
				}
				first = row;
			}
			removeRows( first, last - first + 1, pmi );
		}
	}
}

void SuperModel::swap( const QModelIndex & a, const QModelIndex & b )
{
	bool simpleSwap = (a.parent() == b.parent() && abs(a.row() - b.row()) == 1);
	if( simpleSwap ) {
		ModelNode * node = indexToNode(a);
		node->swap(a,b);
	} else {
		ModelDataTranslator * a_trans = translator(a), * b_trans = translator(b);
		{
			QPersistentModelIndex a_p(a), b_p(b);
			QPersistentModelIndex a_ins = insert(b_p.parent(),b_p.row()+1,b_trans);
			QPersistentModelIndex b_ins = insert(a_p.parent(),a_p.row()+1,a_trans);
			a_trans->copyData(a_trans->dataPtr(a_ins), a_trans->dataPtr(a_p));
			b_trans->copyData(b_trans->dataPtr(b_ins), b_trans->dataPtr(b_p));
		}
		remove(a);
		remove(b);
	}
}

// Inform the model that you have changed some of the data
void SuperModel::dataChange( const QModelIndex & topLeft, const QModelIndex & bottomRight )
{
	if( !topLeft.isValid() ) return;
	QModelIndex br(bottomRight);
	if( !br.isValid() ) br = topLeft;
	emit dataChanged( topLeft, br );
}

void SuperModel::setHeaderLabels( const QStringList & labels )
{
	bool cntChange = (labels.size() != mHeaderData.size());
	mHeaderData = labels;
	if( cntChange )
		reset();
	else
		emit headerDataChanged( Qt::Horizontal, 0, labels.size() );
}

QStringList SuperModel::headerLabels() const
{
	return mHeaderData;
}

QVariant SuperModel::headerData ( int section, Qt::Orientation o, int role ) const
{
	if( role == Qt::DisplayRole ) {
		if( o == Qt::Vertical )
			return "";
		if( section >= 0 && section < mHeaderData.size() )
			return mHeaderData[section];
	}
	return QVariant();
}

void SuperModel::setAutoSort( bool as )
{
	mAutoSort = as;
}

void SuperModel::checkAutoSort( const QModelIndex & parent, bool quiet )
{
	if( mAutoSort )
		_sort( -1, mSortOrder, true, parent, 0, -1, quiet );
}

void SuperModel::resort()
{
	_sort( -1, mSortOrder, true, QModelIndex(), 0, -1, false );
}

void SuperModel::clearChildren( const QModelIndex & i )
{
	if( !i.isValid() ) {
		int rc = rowCount();
		beginRemoveRows(QModelIndex(),0,rc);
		mRootNode->clear();
		endRemoveRows();
		return;
	}
	ModelNode * node = indexToNode(i);
	int rc = node->rowCount();
	beginRemoveRows(i,0,rc);
	node->clearChildren(i);
	endRemoveRows();
}

void SuperModel::sort ( int column, Qt::SortOrder order, bool recursive, const QModelIndex & parentIn, int startRow, int endRow )
{
	_sort( column, order, recursive, parentIn, startRow, endRow, false );
}

void SuperModel::_sort ( int column, Qt::SortOrder order, bool recursive, const QModelIndex & parentIn, int startRow, int endRow, bool quiet )
{
	ModelNode * node = parentIn.isValid() ? indexToNode(parentIn)->child(parentIn) : rootNode();
	if( node ) {
		QModelIndex parent = parentIn.isValid() ? parentIn : createIndex(-1,-1,0);
		if( column >= 0 ) {
			mSortColumnOrder.removeAll(column);
			mSortColumnOrder.prepend(column);
		}
		if( mSortColumnOrder.isEmpty() )
			mSortColumnOrder.prepend(0);
		mSortOrder = order;
		if( !quiet )
			emit layoutAboutToBeChanged();
		node->sort(mSortColumnOrder,order == Qt::AscendingOrder,recursive,parent,startRow,endRow);
		if( !quiet )
			emit layoutChanged();
	}
}

void SuperModel::setSortColumns( const QList<int> & sortColumns, bool forceResort )
{
	if( mSortColumnOrder != sortColumns ) {
		mSortColumnOrder= sortColumns;
		if( forceResort )
			resort();
		else
			checkAutoSort();
	}
}

ModelDataTranslator * SuperModel::translator( const QModelIndex & idx ) const
{
	ModelNode * node = indexToNode(idx);
	return node ? node->translator(idx) : rootNode()->translator(idx);
}

SuperModel::InsertClosure::InsertClosure(SuperModel * model)
: mModel( model )
{
	model->openInsertClosure();
}

SuperModel::InsertClosure::~InsertClosure()
{
	mModel->closeInsertClosure();
}

void SuperModel::openInsertClosure()
{
	if( !mInsertClosureNode || mInsertClosureNode->state > 0 ) {
		InsertClosureNode * node = new InsertClosureNode;
		node->count = 0;
		node->state = 0;
		node->next = mInsertClosureNode;
		mInsertClosureNode = node;
	}
	mInsertClosureNode->count++;
}

void SuperModel::closeInsertClosure()
{
	if( mInsertClosureNode ) {
		mInsertClosureNode->count--;
		if( mInsertClosureNode->count == 0 ) {
			checkAutoSort(mInsertClosureNode->parent,true);
			if( mInsertClosureNode->state == 1 )
				endInsertRows();
			InsertClosureNode * node = mInsertClosureNode;
			mInsertClosureNode = node->next;
			delete node;
		}
	}
}

