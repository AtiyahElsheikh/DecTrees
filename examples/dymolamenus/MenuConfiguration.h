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
 * \file  MenuConfiguration.h
 * \class MenuConfiguration provides basic configuration flags  
 * 
 *
 * @author      Atiyah Elsheikh 
 * 
 * @todo repair the declaration , no static members 
 */


#ifndef MENUCONFIGURATION_H
#define MENUCONFIGURATION_H

#include <eo>
#include "Menu.h"
#include "MenuConstants.h"
#include "BoundedFlag.h"
#include "DiscreteFlag.h"
#include "CommonFlags.h"

using namespace std;

class MenuConfiguration:public Menu { 


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
 MenuConfiguration(Condition* cond,
		   bool optional) 
   : Menu(MenuConstants::SECCONF,cond,optional) {
    specify();
  } 

  /**
   * Copy Cor 
   */ 
 MenuConfiguration(const MenuConfiguration& menu)
   : Menu(MenuConstants::SECCONF,menu._condition,menu.isOptional()) { }  
   //: Menu( (Menu) menu) { }

  /**
   * DCor
   */ 
  virtual ~MenuConfiguration() { 
#ifdef DEBUG
    cout << "MenuConfiguration::~ called\n";
#endif
    FlgSimDir::finalize();
    FlgMode::finalize();
  } 

  ///
  /// Default values of flags 
  ///

  /// Default Optimization Software
  static string   DEF_OPTSOFT;

  /// Default start value file
  static string   DEF_STVALF;

  /// Default Optimization Software
  //static string   DEF_MODE;

  /// candiate values of optsoft flag 
  static string CAND_OPTSOFT[]; 

  /// candiate values of mode flag 
  //static string CAND_MODE[]; 
  
  ///
  /// Flags 
  ///

  /// flag for simulation directory 
  static ConfigFlag<string>* FLG_SIMDIR; 

  /// flag for specifying start values information out of a dymola input file (eg. dsin.start.txt)
  static ConfigFlag<string> FLG_STVALF; 

  /// flag for optimization software 
  static DiscreteFlag<string,string*> FLG_OPTSOFT; 

  /// flag for mode 
  //static DiscreteFlag<string,string*> FLG_MODE;
  
  /// 
  static BoundedFlag<int>    FLG_OPTIMIZE;


};

#endif
