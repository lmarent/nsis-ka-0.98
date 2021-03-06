/// ----------------------------------------*- mode: C++; -*--
/// @file query.h
/// GIST Query PDU
/// ----------------------------------------------------------
/// $Id: query.h 5716 2010-10-13 20:15:05Z bless $
/// $HeadURL: https://svn.ipv6.tm.uka.de/nsis/ntlp/branches/20091014-autotools/src/pdu/query.h $
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
#include <mri_pc.h>
#include <stackprop.h>
#include <stackconf.h>
#include <nli.h>
#include <sessionid.h>
#include <nslpdata.h>
#include <query_cookie.h>


#ifndef NTLP_QUERY_H
#define NTLP_QUERY_H

namespace ntlp {
    using namespace protlib;

/// NTLP Request
class query : public known_ntlp_pdu {
public:
/***** inherited from IE *****/
	virtual query* new_instance() const;
	virtual query* copy() const;
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
	query();
      	query(mri* mr, sessionid* sid, nli* nl, querycookie* qucookie, stackprop* stckprop, stack_conf_data* stckconf, nslpdata* nslpdata);
	// @}
	/// copy constructor
	query(const query& n);
	/// assignment
	query& operator=(const query& n);
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
	    wait_mri,
	    deser_done,
	    wait_sessionid,
	    wait_nli,
	    wait_querycookie,
	    wait_stackprop,
	    wait_stackconf,
	    wait_nslpdata
	} state;
}; // end class query

}

#endif
