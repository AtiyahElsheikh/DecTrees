/**
    Copyright (C) Atiyah Elsheikh (Atiyah.Elsheikh@ait.ac.at,a.m.g.Elsheikh@gmail.com) 2010-2013, AIT Austrian Institute of Technology GmbH

    This file is part of the software DecTrees and InteractiveMneus

    Foobar is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>
*/ 

/**
 * 
 * \file     RegListFlag.cpp
 * \copydoc  RegListFlag.h
 * 
 */



#include "RegListFlag.h"
#include "myutil.h"
#include <regex.h>

#ifndef REGLISTFLAG_CPP
#define REGLISTFLAG_CPP




/**
 *
 */
template<typename T> 
void RegListFlag::flagValues(T& values) const { 
  ListFlag::flagValues(values);
}


/**
 *
 */
template<typename T>
void RegListFlag::flagValues(vector<regex_t>& regvars,
			     T& regvartoks ) const { 

  Myutil::Tokenize(ConfigFlag<string>::flagValue(),
		   regvars,
		   regvartoks,
		   ","); 
  
}


/**
 * 
 */ 
template<typename T>
void RegListFlag::match(const vector<string>& allvars,
			T& regvarsset) { 
  
  map<string,int> regvarsmap; 
  vector<regex_t> regvars; 
  vector<string> regvartoks;
  flagValues(regvars,regvartoks); 
  Myutil::match(regvars,
		allvars,
		regvarsset,
		regvarsmap);

  for(int i=0;i<regvars.size();i++) 
    regfree(&regvars[i]);

}

#endif
