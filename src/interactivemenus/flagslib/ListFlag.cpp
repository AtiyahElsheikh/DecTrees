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
 * \file     ListFlag.cpp
 * \copydoc  ListFlag.h
 * 
 */



#include <algorithm>
#include "ListFlag.h"
#include "myutil.h"

#ifndef LISTFLAG_CPP
#define LISTFLAG_CPP



/**
 *
 */ 
template<typename T> 
void ListFlag::flagValues(T& values) const { 
  string val = ConfigFlag<string>::flagValue(); 
  Myutil::Tokenize(val,values,","); 
}

/**
 *
 */ 
template<typename T>
void ListFlag::setValues(const T& vals) {  
  string val = ""; 
  if(!vals.empty()) { 
    typename T::iterator it; 
    it = vals.begin(); 
    val = *it; 
    it++; 
    for(;it != vals.end();it++)
      val = val + "," + *it; 
  }
  ConfigFlag<string>::setValue(val);
}

/**
 *
 */ 
template<typename T>
void ListFlag::addValues(const T& vals) { 

  if(!vals.empty()) { 
    typename T::iterator it; 
    it = vals.begin(); 
    string val = *it; 
    it++; 
    for(;it != vals.end();it++)
      val = val + "," + *it; 

    string org = ConfigFlag<string>::flagValue();

    ConfigFlag<string>::setValue(org + "," + val);
  }

}


/**
 *
 */ 
template<typename T>
void ListFlag::diffValues(const T& vals) { 

  vector<string>::iterator itend; 
  
  set<string> varsset; 
  this->flagValues(varsset); 

  vector<string> temp(varsset.size());

  itend = set_difference(varsset.begin(),varsset.end(),
			 vals.begin(),vals.end(),
			 temp.begin()); 
  
  set<string> vars_invars(temp.begin(),itend);
 
  this->setValues(vars_invars);
} 


#endif
