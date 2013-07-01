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
 * \file  SingMenuDymExpPars.h
 * \class SingMenuDymExpPars a unique menu for active parameters of a modelica models 
 * 
 *
 * @author      Atiyah Elsheikh 
 * 
 */


#ifndef SINGDYMEXPPARS_H
#define SINGDYMEXPPARS_H


#include "SingltonTemplate.h"
#include "ListFlag.h"
#include "MenuDymExpPars.h"
#include "CommonFlags.h"
using namespace std; 


class SingMenuDymExpPars; 

class SingMenuDymExpPars : 
public SingltonTemplate<MenuDymExpPars> { 


 private:

  /// flag for Pars 
  static ListFlag*  FLG_PARS;
  
  /// flag for inPars
  static ListFlag*  FLG_INPARS;
  
  /// flag for Pars candidate 
  static ListFlag*  FLG_PCAND;
  
 

 protected:


  /**
   * protected Cor to ensure that the menu is declared only with create() 
   */ 
  SingMenuDymExpPars() { }


  /**
   *
   */
  virtual ~SingMenuDymExpPars() {

#ifdef DEBUG
    cout << "~SingMenuDymExpPars :: called \n" ; 
#endif

    delete FLG_INPARS;        FLG_INPARS = 0; 
    FlgActPars::finalize(); //delete FLG_PARS;          FLG_PARS   = 0; 
    FlgParCand::finalize();
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
  inline static MenuDymExpPars* getMenu() { 
    if(!isCreated()) create(); 
    return _object; 
  }
 
  /**
   * get active parameters 
   * @return vecotrs of parameters 
   */ 
  inline static void getActPars(vector<string>& ans) { 
    FLG_PARS->flagValues(ans);
  }

}; 


#endif 
