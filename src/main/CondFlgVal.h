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
 * \file CondFlgVal.h
 * \class CondFlgVal check for a flag value 
 * 
 *
 * @version     1.0
 *
 */

#ifndef CONDFLGVAL_H
#define CONDFLGVAL_H 

#include "Condition.h"
#include "FlagInterface.h"

class CondFlgVal : public Condition { 

 private:

  /// 
  FlagInterface* _flag; 

  /// required val
  string _val;

 protected:

  /**
   * Disallow default constructor 
   */ 
  CondFlgVal() { } 

 public:
 
  /**
   * Cor.
   * @param cond true or false condition 
   */ 
 CondFlgVal(FlagInterface* flg,const string& value)
   : _flag(flg),_val(value){} 
  
  /**
   * Copy Constructor
   */ 
 CondFlgVal(const CondFlgVal& C)
   : _flag(C._flag),_val(C._val) { } 

  /**
   *
   */
  virtual ~CondFlgVal() {}

  /**
   * Evaluate the condition 
   */ 
  virtual bool evaluate() const { 
    if(!_flag->isProcessed()) { 
      cerr << _flag->flagKey() << " not yet processed \n";  
      assert(_flag->isProcessed());
    }    
    return _flag->getValueAsStr() == _val; 
  } 

}; 


#endif
