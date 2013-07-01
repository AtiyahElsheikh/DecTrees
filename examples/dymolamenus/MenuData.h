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
 * \file  MenuData.h
 * \class MenuData provides basic flags for specifying the data 
 *                    
 * 
 * @author      Atiyah Elsheikh 
 *
 */


#ifndef MENUDATA_H
#define MENUDATA_H

#include <eo>
#include "Menu.h"
#include "MenuConstants.h"
#include "ConfigFlag.h"
using namespace std;

class MenuData:public Menu { 


 private:

 protected:
  
  /**
   *
   */ 
  virtual void specify();

 
 public:


  /**
   * Cor
   * @param condition to process this node 
   * @param optional whether succissful processing 
   *        for the menu is necessary for overall success
   */ 
 MenuData(Condition* cond,
	  bool optional) 
   : Menu(MenuConstants::SECDATA,cond,optional) {
    specify();
  } 
  
  /**
   * Copy Cor 
   */ 
 MenuData(const MenuData& menu)
   : Menu(MenuConstants::SECDATA,
	  menu._condition,
	  menu.isOptional()) { }  
  
  
  /**
   * DCor
   */ 
  virtual ~MenuData() { 
#ifdef DEBUG
    cout << "MenuData::~ called\n";
#endif

    delete _FLG_DATAFILE; _FLG_DATAFILE = 0; 
    delete _FLG_DSEED;    _FLG_DSEED=0;
    delete _FLG_DSTDDIV;  _FLG_DSTDDIV=0;
  } 


  ///  
  static string DEF_DATAFILE; 
  
  ///  
  ConfigFlag<string>*   _FLG_DATAFILE; 

  ///
  ConfigFlag<int>*      _FLG_DSEED;

  ///
  ConfigFlag<double>*   _FLG_DSTDDIV;

};

#endif
