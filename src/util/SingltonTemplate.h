/*    
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
 * \file  SingltonTemplate.h
 * \class SingltonTemplate generates a unique object which will be 
 *        used throughout other classes   
 * 
 * @author      Atiyah Elsheikh 
 */


#ifndef SINGLTONTEMPLATE_H
#define SINGLTONTEMPLATE_H

//#include <eo>
using namespace std; 

/**
 * @param T instance for each type 
 * @param ID generates several instances of the same type
 */ 
template<typename T>
class SingltonTemplate { 


 protected:

  /// configuration files parser
  static T* _object; 

  /// whetehr the unique parser already created
  static bool _created; 

  /// the singlton 
 static SingltonTemplate<T>* _singlton; 

  /**
   * Empty Constructor 
   */ 
  SingltonTemplate() { }

  
  
  /**
   * DCor
   */ 
  virtual ~SingltonTemplate(); 

 

 public:


  /**
   *
   */ 
  static void create();


  /**
   * get the unique eoParser
   */ 
  static T* getObject();

  
  /**
   * get the created object / created it if not created yet
   * @ret the object 
   */ 
  static SingltonTemplate* getSinglton();

  /**
   * whether the unique instance is created 
   * @ret 
   */ 
  static bool isCreated();
  

  /**
   *
   */ 
  static void finalize();


}; 


#include "SingltonTemplate.cpp"

#endif 

