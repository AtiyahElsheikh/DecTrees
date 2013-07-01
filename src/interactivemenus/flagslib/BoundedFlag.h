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
 * \file  BoundedFlag.h
 * \class BoundedFlag represents a flag whose values are known and bounded
 * 
 * @author      Atiyah Elsheikh 
 * 
 */


#ifndef BOUNDEDFLAG_H
#define BOUNDEDFLAG_H 

#include <set>
#include "SpecifiedFlag.h"
using namespace std; 


template<typename T>
class BoundedFlag:public SpecifiedFlag<T> { 

 private:

  /// upper bound for the value of the flag
  T _upper;

  /// lower bound for the value of the flag 
  T _lower; 


 public:


  /**
   * Cor. 
   * 
   * @param the flag 
   * @param condition to process this flag
   * @param ptr to start of an array,vector,.. etc.
   * @param ptr to end   of an array,vector,.. etc.
   */ 
 BoundedFlag(const eoValueParam<T>& flag,
	     Condition* condition,
	     T lower,
	     T upper)
   : SpecifiedFlag<T>(flag,condition),
    _upper(upper),
    _lower(lower)
    { 
      assert(lower <= upper);
    }


  /**
   * Copy Cor 
   */ 
 BoundedFlag(const BoundedFlag<T>& param)
   : SpecifiedFlag<T>( (SpecifiedFlag<T>) param) ,
    _upper(param._upper),
    _lower(param._lower) { }

  /**
   * DCor 
   */ 
  virtual ~BoundedFlag() { }


  /**
   *
   */
  virtual bool isValid() const;

}; 

#include "BoundedFlag.cpp"

#endif
