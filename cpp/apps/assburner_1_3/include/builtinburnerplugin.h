
/*
 *
 * Copyright 2003 Blur Studio Inc.
 *
 * This file is part of RenderLine.
 *
 * RenderLine is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * RenderLine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RenderLine; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/*
 * $Id: builtinburnerplugin.h 8233 2009-05-13 06:26:17Z newellm $
 */

#ifndef BUILTIN_BURNER_PLUGIN_H
#define BUILTIN_BURNER_PLUGIN_H

#include "jobburnerplugin.h"

void registerBuiltinBurners();

class BuiltinBurnerPlugin : public JobBurnerPlugin
{
public:
	QStringList jobTypes();
	JobBurner * createBurner( const JobAssignment & jobAssignment, Slave * slave );
};

#endif // BUILTIN_BURNER_PLUGIN_H