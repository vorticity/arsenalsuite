/*
 *
 * Copyright 2007 Blur Studio Inc.
 *
 * This file is part of the Resin software package.
 *
 * Resin is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Resin is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Resin; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifdef HEADER_FILES
#endif

#ifdef CLASS_FUNCTIONS
	
	/// Pulse column is updated to the current database datetime.
	bool pulse();

	/// Automatically enables this host service if the following conditions are met
	/// 1. Service.enabled is true
	/// 2. No other HostService record with same service is enabled
	/// returns true if this hostservice.enabled is true(whether set or existing)
	bool enableUnique();

#endif
