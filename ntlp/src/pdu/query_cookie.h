/// ----------------------------------------*- mode: C++; -*--
/// @file query_cookie.h
/// GIST Query Cookie
/// ----------------------------------------------------------
/// $Id: query_cookie.h 5998 2011-03-09 09:02:34Z bless $
/// $HeadURL: https://svn.tm.kit.edu/nsis/ntlp/branches/20091014-autotools/src/pdu/query_cookie.h $
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
#include "ntlp_object.h"
#include "address.h"
#include "protlib_types.h"


#ifndef _NTLP__QUERYCOOKIE_H_
#define _NTLP__QUERYCOOKIE_H_


namespace ntlp {
    using namespace protlib;


class querycookie : public known_ntlp_object {


/***** inherited from IE ****/
public:
	virtual querycookie* new_instance() const;
	virtual querycookie* copy() const;
	virtual querycookie* deserialize(NetMsg& msg, coding_t cod, IEErrorList& errorlist, uint32& bread, bool skip = true);
	querycookie* deserializeNoHead(NetMsg& msg, coding_t cod, IEErrorList& errorlist, uint32& bread, bool skip = true);
	virtual void serialize(NetMsg& msg, coding_t cod, uint32& wbytes) const;
	virtual void serializeNoHead(NetMsg& msg, coding_t cod, uint32& wbytes) const;
	virtual void serializeEXT(NetMsg& msg, coding_t cod, uint32& wbytes, bool header) const;
	virtual bool check() const;
	virtual size_t get_serialized_size(coding_t coding) const;
	virtual bool operator==(const IE& ie) const;
	virtual const char* get_ie_name() const;
	virtual ostream& print(ostream& os, uint32 level, const uint32 indent, const char* name = NULL) const;
	virtual istream& input(istream& is, bool istty, uint32 level, const uint32 indent, const char* name = NULL);
/***** new members *****/


 private:
	///buffer for data
	uchar *buf;
	///buffer length
	uint32 buf_length;
    
  static const char* const iename;
  static const size_t contlen;    
  querycookie* deserializeEXT(NetMsg& msg, coding_t cod, IEErrorList& errorlist, uint32& bread, bool skip = true, bool header = true);
	

public:    

/// stupid constructor, still, it is needed by NTLP_IE's "new_instance()" method, for deserialization (??)
inline querycookie() :
	known_ntlp_object(QueryCookie, Mandatory), buf_length(0)
{
	buf = NULL;
};


/// Returns a handle to the buffer containing the cookie
inline
    uchar* get_buffer() const {
    return buf;
}

/// Returns buffer length
inline
    uint32 get_size() {
    return buf_length;
}


/// This is the one mighty constructor, via which the object SHOULD be built programmatically!
inline querycookie(const uchar *buffer, uint32 l) :
	known_ntlp_object(QueryCookie, Mandatory),
	buf_length(l)
{
	buf = new(nothrow) uchar[l];
	if (!buf)
		throw NetMsgError(NetMsgError::ERROR_NO_MEM);
	if (buffer)
		memcpy(buf, buffer, l);
	else
		throw NetMsgError(NetMsgError::ERROR_NULL_POINTER); 
};



/// copy constructor
inline
    querycookie(const querycookie& n): 
    known_ntlp_object(QueryCookie, Mandatory)
    {
	

	buf_length=n.buf_length;
	
	if (buf_length > 0)
	{
	    buf = new(nothrow) uchar[buf_length];
	    if (!buf) throw NetMsgError(NetMsgError::ERROR_NO_MEM);
	    if (buf) {
		if (n.buf) {
		    memcpy(buf,n.buf,buf_length);
		} else {
		    ERRCLog("querycookie", "Buffer in Object to copy points to NULL!!");
		    throw NetMsgError(NetMsgError::ERROR_NULL_POINTER); 
		}
	    } else {
		ERRCLog("querycookie", "Local Buffer points to NULL!!"); 
	    }
	} else {
	    buf = NULL;
	}
    };



virtual
inline
    ~querycookie()
    {
	if (buf) delete[] buf;
    }

};

}

#endif
