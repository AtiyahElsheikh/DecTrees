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
 * \file  SingMenuExtList.h
 * \class SingMenuExtList
 * 
 *
 * @author      Atiyah Elsheikh 
 * 
 */


#ifndef SINGMENUEXTLIST_H
#define SINGMENUEXTLIST_H


#include "ListFlag.h"
#include "MenuExtendedList.h"


using namespace std; 

/**
 * \tparam <func> a function that creats a specific menu of type MenuExtendedList<double> and return its adress  
 */ 
template<MenuExtendedList<double>* func()>
class SingMenuExtList {  

 private:

  /// initialized by the template parameter 
  static string _postfix; 

  /// initialized by the template parameter  
  static ListFlag* _listflag; 

   /// configuration files parser
  static MenuExtendedList<double>* _object; 

  /// whetehr the unique parser already created
  static bool _created; 

  /// the singlton 
  static SingMenuExtList* _singlton; 


  /**
   * protected Cor to ensure that the menu is declared only with create() 
   */ 
  SingMenuExtList() { }   
  
  /**
   * 
   */
  virtual ~SingMenuExtList() { 
    delete _object; 
    _created = false; 
  }



 public:


  /**
   * 
   */ 
  static void create(); 
  
  /**
   * get the unique eoParser
   */ 
  static MenuExtendedList<double>* getObject();

  /**
   *
   */
  static inline MenuExtendedList<double>* getMenu() { 
    return getObject();
  }

  /**
   * get the created object / created it if not created yet
   * @ret the object 
   */ 
  static SingMenuExtList* getSinglton();

  /**
   * whether the unique instance is created 
   * @ret 
   */ 
  static bool isCreated();
  
  /**
   *
   */ 
  static void finalize();

  /**
   * @param {output] the values of the flags
   */
  inline static void getExtListVals(vector< vector<double> >& ans) { 
    _object->getExtListVals(ans);
  }


 
}; 


#include "SingMenuExtList.cpp"
#include "MenuExtListFactory.h"


/** 
 * \class SingMenuFixedPars is a specialization of the class SingMenuExtList 
 * by the function MenuExtListFactory::MenuFixedPars. 
 * 
 * provides a singlton menu for fixed parameter values 
 */
typedef SingMenuExtList<MenuExtListFactory::MenuFixedPars> 
SingMenuFixedPars;

 
/**
 * \class SingMenuStartVals is a specialization of the class SingMenuExtList
 * specialized by the function MenuExtListFactory::MenuStartVals
 * 
 * provides a singlton menu for start values of active parameters 
 */  
typedef SingMenuExtList<MenuExtListFactory::MenuStartVals>
SingMenuStartVals;



/**
 * \class SingMenuStValsBound is a specialization of the 
 * class SingMenuExtList
 * specialized by the function MenuExtListFactory::MenuStValsBound
 * 
 * provides a singlton menu for boundaries start values of active parameters 
 */  
typedef SingMenuExtList<MenuExtListFactory::MenuStValsBound>
SingMenuStValsBound;


#endif
