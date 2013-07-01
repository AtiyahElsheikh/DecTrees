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
 * \file  ListFlag.h
 * \class ListFlag a flag representing a list --list=v1,v2,...   
 * 
 * @author      Atiyah Elsheikh 
 * 
 */



#ifndef LISTFLAG_H
#define LISTFLAG_H 

#include "ConfigFlag.h"
#include <vector>
#include <set>
using namespace std; 


class ListFlag:public ConfigFlag<string> { 

 private:


 protected:

 
 public:

  /**
   * Cor. 
   * 
   * @param the flag  
   * @param condition to process this flag 
   */ 
 ListFlag(const eoValueParam<string>& flag,
	  Condition* condition)
   : ConfigFlag<string>(flag,condition) { } 

  /**
   * Copy Cor 
   */ 
 ListFlag(const ListFlag& param)
   : ConfigFlag<string>( (ConfigFlag<string>) param) { }

  /**
   * DCor 
   */ 
  virtual ~ListFlag() { }


  /**
   * the values of the flag 
   * @param output argument: list of values specified by the flag of type set<string> or vector<string>
   */
  template<typename T>
  void flagValues(T& values) const; 

 

  /**
   * set the flag values -list=v[0],v[1],... 
   * @param set<string> or vector<string>
   */ 
  template<typename T>
  void setValues(const T& vals);
  

  /**
   * insert additional values to the flag 
   * @param vector<string> or set<string> of values
   */ 
  template<typename T>
  void addValues(const T& vals); 

  
  /**
   * subtract the flag values from vals
   * @param sorted list of values to be removed
   */ 
  template<typename T>
  void diffValues(const T& vals);
    
 

}; 

#include "ListFlag.cpp"

#endif





