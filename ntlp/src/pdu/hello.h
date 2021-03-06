/// ----------------------------------------*- mode: C++; -*--
/// @file hello.h
/// GIST Hello PDU
/// ----------------------------------------------------------
/// $Id: hello.h 5716 2010-10-13 20:15:05Z bless $
/// $HeadURL: https://svn.ipv6.tm.uka.de/nsis/ntlp/branches/20091014-autotools/src/pdu/hello.h $
// ===========================================================
//                      
// Copyright (C) 2005-2010, all rights reserved by
// - Institute of Telematics, Karlsruhe Institute of Technology
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
#include <ntlp_pdu.h>
#include <ntlp_object.h>
#include <helloid.h>


#ifndef NTLP_HELLO_H
#define NTLP_HELLO_H


namespace ntlp {
    using namespace protlib;

/// NTLP Request
class hello : public known_ntlp_pdu {
public:
/***** inherited from IE *****/
	virtual hello* new_instance() const;
	virtual hello* copy() const;
	virtual bool check() const;
	virtual bool operator==(const IE& ie) const;
	virtual const char* get_ie_name() const;
	virtual ostream& print(ostream& os, uint32 level, const uint32 indent, const char* name = NULL) const;
	virtual istream& input(istream& is, bool istty, uint32 level, const uint32 indent, const char* name = NULL);
	virtual void clear_pointers();
/***** inherited from ntlp_pdu *****/
protected:
	virtual deser_error_t accept_type_and_subtype(uint8 t);
	virtual bool accept_object(known_ntlp_object* o, uint32& position, IEErrorList& errorlist);
	virtual bool deser_end(IEErrorList& errorlist);
/***** new members *****/
public:
	// @{
	/// constructor
	hello();
	hello(helloid *id);
	// @}
	/// copy constructor
	hello(const hello& n);
	/// assignment
	hello& operator=(const hello& n);
	// @{
       	// @}
private:	
	/// PDU fields

	static const char* const iename;
	/// default number of objects
	static const uint32 numobj;
	/// deserialization state
	enum deser_state_t {
	    initial,
	    deser_done
	} state;
}; // end class hello

}

#endif
