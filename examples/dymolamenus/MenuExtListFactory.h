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
 * \file  MenuExtListFactory.h
 * \class MenuExtListFactory
 * 
 *
 * @author      Atiyah Elsheikh 
 * 
 */


#include "SingMenuExtList.h"
#include "MenuExtendedList.h"
#include "Condition.h"
#include <vector>

#ifndef MENUEXTLISTFACTORY_H
#define MENUEXTLISTFACTORY_H 

class MenuExtListFactory { 

 private:

  /** */
  static vector<Condition*> CONDITIONS; 

 public:

  /**
   * delete all created objects 
   */ 
  static void finalize();

  /**
   * creates a menu for list of extended parameters 
   * @ret the menu 
   */ 
  static MenuExtendedList<double>* MenuFixedPars(); 

  /**
   * creates a menu for a regular and explicit list of start vals
   * @ret the menu 
   */ 
  static MenuExtendedList<double>* MenuStartVals(); 


  /**
   * creates a menu for a regular and explicit list of start vals
   * @ret the menu 
   */ 
  static MenuExtendedList<double>* MenuStValsBound(); 
  


};

#endif
