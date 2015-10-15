/// ----------------------------------------*- mode: C++; -*--
/// @file readnl.h
/// Read netlink socket
/// ----------------------------------------------------------
/// $Id: readnl.h 5876 2011-02-15 22:52:35Z bless $
/// $HeadURL: https://svn.ipv6.tm.uka.de/nsis/protlib/branches/20091014-autotools/include/readnl.h $
// ===========================================================
//                      
// Copyright (C) 2005-2007, all rights reserved by
// - Institute of Telematics, Universitaet Karlsruhe (TH)
//
// More information and contact:
// https://projekte.tm.uka.de/trac/NSIS
//                      
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; version 2 of the License
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
// ===========================================================
#ifndef READNL_H
#define READNL_H

#define NL_BUFSIZE 8192
namespace protlib {

	namespace util {
		int readnl(int sock, char *buf);
	}
}
#endif
