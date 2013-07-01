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
 * \file  DiscreteFlag.h
 * \class DiscreteFlag represents a flag whose values are known and discrete
 * 
 * @author      Atiyah Elsheikh 
 * 
 */


#ifndef DISCRETEFLAG_H
#define DISCRETEFLAG_H 

#include <set>
//#include <iterator> 
#include "SpecifiedFlag.h"
using namespace std; 


template<typename T,
  typename myiterator> 
class DiscreteFlag:public SpecifiedFlag<T> { 

 private:

  /// set of possible candidates 
  set<T> _candidate; 


 public:


  /**
   * Cor. 
   * 
   * @param the flag 
   * @param condition to process this flag
   * @param ptr to start of an array,vector,.. etc.
   * @param ptr to end   of an array,vector,.. etc.
   */ 
 DiscreteFlag(const eoValueParam<T>& flag,
	      Condition* condition,
	      myiterator beg,
	      myiterator end)
    : SpecifiedFlag<T>(flag,condition) 
    { 
      for(myiterator it = beg;it < end;it++) { 
	_candidate.insert(*it);
	//cout << *it << "\n"; 
      }
     
    }


  /**
   * Copy Cor 
   */ 
 DiscreteFlag(const DiscreteFlag<T,myiterator>& param)
   : SpecifiedFlag<T>( (SpecifiedFlag<T>) param) ,
    _candidate(param._candidate) { }

  /**
   * DCor 
   */ 
  virtual ~DiscreteFlag() { }


  /**
   *
   */
  virtual bool isValid() const;

}; 

#include "DiscreteFlag.cpp"

#endif
