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
 * \file  RegListFlag.h
 * \class RegListFlag a flag representing a list of regular expressions   
 * 
 * @author      Atiyah Elsheikh 
 */


#ifndef NOREGEX_H

#ifndef REGLISTFLAG_H
#define REGLISTFLAG_H 

#include "ListFlag.h"
#include <vector>
#include <set>
using namespace std; 


class RegListFlag:public ListFlag { 

 private:
  


 public:

  /**
   * Cor. 
   * 
   * @param the flag  
   * @param condition to process this flag 
   */ 
 RegListFlag(const eoValueParam<string>& flag,
	     Condition* condition)
   : ListFlag(flag,condition) { } 

  /**
   * Copy Cor 
   */ 
 RegListFlag(const RegListFlag& param)
   : ListFlag( (ListFlag) param) { }

  /**
   * DCor 
   */ 
  virtual ~RegListFlag() { }

  /**
   * the values of the flag 
   * @param output argument: list of values specified by the flag of type set<string> or vector<string>
   */
  template<typename T>
  void flagValues(T& values) const; 

 
  /**
   * match the regular expressions to given lists of ids 
   * @param input ids 
   * @param output arg: set/vector of matched ids 
   */ 
  template<typename T>
  void match(const vector<string>& allvars,
	     T& regvarsset) ;
    
  
  /**
   * the values and regular tokens of the flag 
   * @param output arg: list of regular expressions, after use, must be freed with regfree(&regex_t) 
   * @param output arg: set/vector of values specified by the flag of type set<string> or vector<string>
   */
  template<typename T>
    void flagValues(vector<regex_t>& regvars,
		    T& regvartoks ) const; 

}; 

#include "RegListFlag.cpp"

#endif
#endif
