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
 * \file  SingMenuDymExpVars.h
 * \class SingMenuDymExpVars a unique menu for reference variables of dymola variables 
 * 
 *
 * @author      Atiyah Elsheikh 
 * 
 * 
 */


#ifndef SINGDYMEXPVARS_H
#define SINGDYMEXPVARS_H


#include "SingltonTemplate.h"
#include "ListFlag.h"
#include "MenuDymExpVars.h"

using namespace std; 


class SingMenuDymExpVars; 

class SingMenuDymExpVars : public SingltonTemplate<MenuDymExpVars> { 


 private:

  /// flag for vars 
  static ListFlag*  FLG_VARS;
  
  /// flag for invars
  static ListFlag*  FLG_INVARS;
  
  /// flag for vars candidate 
  static ListFlag*  FLG_VCAND;
  
 

 protected:


  /**
   * protected Cor to ensure that the menu is declared only with create() 
   */ 
  SingMenuDymExpVars() { }


  /**
   *
   */
  virtual ~SingMenuDymExpVars() {

#ifdef DEBUG
    cout << "~SingMenuDymExpVars :: called \n" ; 
#endif

    delete FLG_INVARS;        FLG_INVARS = 0; 
    delete FLG_VARS;          FLG_VARS   = 0; 
    delete FLG_VCAND;         FLG_VCAND  = 0;
  }



 public:

 
  /**
   * @overwrite 
   */ 
  static void create(); 

  

  /**
   * get pointer to the menu instance 
   * @todo create if not yet created 
   */
  inline static MenuDymExpVars* getMenu() { 
    if(!isCreated()) create(); 
    return _object; 
  }
 

  /**
   * get active parameters 
   * @return vecotrs of parameters 
   */ 
  inline static void getRefVars(vector<string>& ans) { 
    FLG_VARS->flagValues(ans);
  }

}; 


#endif 
