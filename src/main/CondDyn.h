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
 * \file CondDyn.h
 * \class CondDyn expresses a dynamic condition that get evaluated at runtime
 * 
 * A CondDyn is constructed by passing a routine evaluated at run-time 
 *
 * @author      Atiyah Elsheikh 
 *
 *
 */

#ifndef CONDDYN_H
#define CONDDYN_H 

#include "Condition.h" 
#include <cassert>
using namespace std; 

class CondDyn : public Condition { 

 private:

  /// a pionter to a function return a boolean value 
  bool (*_boolfun)(); 


 protected:

  /**
   * Disallow default constructor 
   */ 
  CondDyn() { }


 public:
 
  
  /**
   *
   */ 
  CondDyn(bool (*boolfun)())
    :_boolfun(boolfun) { 
    assert(_boolfun != 0); 
  }  

  /**
   * Copy Constructor
   */ 
  CondDyn(const CondDyn& C)
    :  _boolfun(C._boolfun) {}

  /**
   *
   */
  virtual ~CondDyn() {}

  /**
   * Evaluate the CondDyn 
   */ 
  virtual bool evaluate() const;  

}; 

#endif
