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
 * \file  SpecifiedFlag.h
 * \class SpecifiedFlag represents a flag whose values are known
 * 
 * @author      Atiyah Elsheikh 
 * 
 */


#ifndef SPECIFIEDFLAG_H
#define SPECIFIEDFLAG_H 

#include "ConfigFlag.h"
using namespace std; 


template<typename T> 
class SpecifiedFlag:public ConfigFlag<T> { 


 public:

  /**
   * Cor. 
   * 
   * @param the flag  
   * @param condition to process this flag 
   */ 
  SpecifiedFlag(const eoValueParam<T>& flag,
		Condition* condition)
    : ConfigFlag<T>(flag,condition) { } 

  /**
   * Copy Cor 
   */ 
 SpecifiedFlag(const SpecifiedFlag<T>& param)
   : ConfigFlag<T>( (ConfigFlag<T>) param) { }

  /**
   * DCor 
   */ 
  virtual ~SpecifiedFlag() { }

  /**
   * whether the processed flag is valid 
   */ 
  virtual bool isValid() const = 0; 

  
  /**
   * process the flag 
   */ 
  virtual bool process(void *data); 

}; 

#include "SpecifiedFlag.cpp"
#endif
