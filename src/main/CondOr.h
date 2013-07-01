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
 * \file CondOr.h
 * \class CondOr check whethre 1 of 2 conditions is satisified 
 * 
 * 
 * @author      Atiyah Elsheikh 
 */

#ifndef CONDAND_H
#define CONDAND_H 

#include "Condition.h"

class CondOr : public Condition{ 

 private:

  /// 
  Condition* _cond1;

  ///
  Condition* _cond2;

 
 protected:

  /**
   * Disallow default constructor 
   */ 
  CondOr() { } 

 public:
 
  /**
   * Cor.
   * @param cond true or false condition 
   */ 
 CondOr(Condition* cond1,Condition* cond2)
   : _cond1(cond1),_cond2(cond2) {
  } 
  
  /**
   * Copy Constructor
   */ 
 CondOr(const CondOr& C)
   : _cond1(C._cond1),_cond2(C._cond2) { } 

  /**
   *
   */
  virtual ~CondOr() {}

  /**
   * Evaluate the condition 
   */ 
  virtual bool evaluate() const {     
    return _cond1->evaluate() || _cond2->evaluate(); 
  } 

}; 

#endif
