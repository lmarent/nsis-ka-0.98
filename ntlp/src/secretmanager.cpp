/// ----------------------------------------*- mode: C++; -*--
/// @file secretmanager.cpp
/// Secret managing entity (manages changing/roll-over) of secrets
/// ----------------------------------------------------------
/// $Id: secretmanager.cpp 5857 2011-02-04 15:21:17Z bless $
/// $HeadURL: https://svn.ipv6.tm.uka.de/nsis/ntlp/branches/20091014-autotools/src/secretmanager.cpp $
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
#include <secretmanager.h>
#include <openssl/rand.h>
#include <iostream>
#include <iomanip>


namespace ntlp {
    
using namespace protlib;
using namespace protlib::log;
  
/// initially fill the table with set secret count, initialize generation_number
ntlp::secretmanager::secretmanager(uint32 tablesize, uint32 secretsize) : 
		tablesize(tablesize),
		secretsize(secretsize)
{
	DLog("GIST secrets", color[blue] <<  "Initially filling random seed, "
		<< tablesize << " secrets of length " << secretsize << "bit" << color[off]);

	// clear
	secrets.clear();
	secrets.reserve(tablesize);
	gen_numbers.clear();
	gen_numbers.reserve(tablesize);

	srand(time(NULL));
	// initialize generation_number
	generation_number= rand();

	// we should start at position 0 because we fill the vector with push_back
	generation_number= generation_number - generation_number % tablesize -1;

	// add 
	for (uint32 i = 0; i < tablesize; i++) {
		uchar* tmp = new uchar[secretsize / 8];

		if (!RAND_bytes(tmp, secretsize / 8)) {
			ERRCLog("GIST secrets", "OpenSSL Random number generator could not get random number");
			abort();
		}

		generation_number++;

		DLog("GIST secrets", color[blue]
			<< "Filling secret table entry " << (generation_number % tablesize)
			<< " Generation number 0x" << hex << generation_number << dec << color[off]);

		secrets.push_back(tmp);

		delete [] tmp;

		gen_numbers.push_back(generation_number);
	}
}
  
  
/// go to next secret generation
void 
ntlp::secretmanager::forward() 
{
	generation_number++;

	// fill in new secret
	uchar* tmp = new uchar[secretsize/8];

	if (!RAND_bytes(tmp, secretsize/8)) {
		ERRCLog("GIST secrets", "OpenSSL Random number generator could not get random number");
		abort();
	}

	gen_numbers[generation_number%tablesize]= generation_number;
	secrets[generation_number%tablesize] = tmp;

	delete [] tmp;

	DLog("GIST secrets", color[magenta]
		<< "Secret number: " << dec << (int) generation_number % tablesize << " replaced."
		<< " New Generation Number: 0x" << hex << (int) generation_number
		<< " Secret length: " << dec << secretsize << " Bit" << color[off]); 	
}

// destruct
ntlp::secretmanager::~secretmanager() {}

}
