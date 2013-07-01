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
 * \file  SingltonFlag.h
 * \class SingltonFlag represents a unique Flag used 
 *                     throughout multiple menus
 * 
 * @author      Atiyah Elsheikh 
 */


#ifndef SINGLTONFLAG_H
#define SINGLTONFLAG_H

//#include <eo>
#include "FlagInterface.h"
#include "ListFlag.h"
using namespace std; 



template<FlagInterface* flagfun()>
class SingltonFlag  { 


  /// configuration files parser
  static FlagInterface* _object; 

  /// whetehr the unique parser already created
  static bool _created; 

  /// the singlton 
  static SingltonFlag* _singlton; 


 protected:
  
  /**
   * DCor
   */ 
  virtual ~SingltonFlag() { 
    if(_object != 0) { 
      delete _object->getCondition();
      delete _object; 
      _object = 0;
    }
    _created = false; 
  } 


  /**
   * Cor 
   */ 
  SingltonFlag() { } 


 public:
  
  /** */ 
  static void create();
  
  /**
   * get the unique eoParser
   */ 
  static FlagInterface* getObject();

  
  /**
   * get the created object / created it if not created yet
   * @ret the object 
   */ 
  static SingltonFlag* getSinglton();

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



#include "SingltonFlag.cpp"



#endif 

