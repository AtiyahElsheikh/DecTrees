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
 * \file Condition.h
 * \class Condition expresses a condition and evaluate it 
 * 
 * A condition is static and consturcted by passing a boolean condition
 *
 * @author      Atiyah Elsheikh 
 *
 *
 */

#ifndef CONDITION_H
#define CONDITION_H 

class Condition { 

 private:

  /// 
  bool _cond;

  /// 
  // bool (*_boolfun)(); 

 protected:

  /**
   * Disallow default constructor 
   */ 
  Condition() { } 

 public:
 
  /**
   * Cor.
   * @param cond true or false condition 
   */ 
 Condition(bool cond):_cond(cond) {} 
  
  /**
   *
   */ 
  //Condition(bool (*boolfun)()):_boolfun(boolfun) { }  


  /**
   * Copy Constructor
   */ 
  Condition(const Condition& C)
    :_cond(C._cond) { }
    //  _boolfun(C._boolfun) {

  /**
   *
   */
  virtual ~Condition() {}

  /**
   * Evaluate the condition 
   */ 
  virtual bool evaluate() const;  

}; 

#endif
