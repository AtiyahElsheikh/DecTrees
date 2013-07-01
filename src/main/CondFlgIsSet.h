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
 * \file CondFlgIsSet.h
 * \class CondFlgIsSet check for a flag value 
 * 
 * 
 * @author      Atiyah Elsheikh 
 */

#ifndef CONDFLGISSET_H
#define CONDFLGISSET_H 

#include "Condition.h"
#include "FlagInterface.h"

class CondFlgIsSet : public Condition { 

 private:

  /// 
  FlagInterface* _flag; 

 
 protected:

  /**
   * Disallow default constructor 
   */ 
  CondFlgIsSet() { } 

 public:
 
  /**
   * Cor.
   * @param cond true or false condition 
   */ 
 CondFlgIsSet(FlagInterface* flg)
   : _flag(flg) {} 
  
  /**
   * Copy Constructor
   */ 
 CondFlgIsSet(const CondFlgIsSet& C)
   : _flag(C._flag) { } 

  /**
   *
   */
  virtual ~CondFlgIsSet() {}

  /**
   * Evaluate the condition 
   */ 
  virtual bool evaluate() const { 
    if(!_flag->isProcessed()) { 
      cerr << _flag->flagKey() << " not yet processed \n";  
      assert(_flag->isProcessed());
    }    
    return _flag->flagExist(); 
  } 

}; 
