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
 * \file  MenuDymola.h
 * \class MenuDymola provides basic configuration flags for simulating a Dymola program.  
 * 
 *
 * @author      Atiyah Elsheikh 
 */


#ifndef MENUDYMOLA_H
#define MENUDYMOLA_H

#include <eo>
#include "Menu.h"
#include "MenuConstants.h"
#include "BoundedFlag.h"
#include "ConfigFlag.h"

using namespace std;

class MenuDymola:public Menu { 


 private:
  

 protected:
  
  /**
   *
   */ 
  virtual void specify();

 public:


  /**
   * 
   * @param argc number of arguments 
   * @param argv online arguments 
   * @param output file
   * @param condition to process this node 
   * @param optional whether succissful processing 
   *        for the menu is necessary for overall success
   */ 
 MenuDymola(Condition* cond,
	    bool optional) 
   : Menu(MenuConstants::SECDYML,cond,optional) {
    specify();
  } 

  /**
   * Copy Cor 
   */ 
 MenuDymola(const MenuDymola& menu)
   : Menu(MenuConstants::SECDYML,menu._condition,menu.isOptional()) { }  


  /**
   * DCor
   */ 
  virtual ~MenuDymola() { 
#ifdef DEBUG
    cout << "MenuDymola::~ called\n";
#endif
  } 

  /// Default start time 
  static double DEF_TOLERANCE;

  /// Default start time 
  static double DEF_STARTTIME;

  ///
  static double DEF_STOPTIME; 

  /// Default start time 
  static int DEF_ALGORITHM;

  /// Default increment 
  static double DEF_INCREMENT; 

  ///  flag for starttime 
  static ConfigFlag<double>  FLG_STARTTIME;
  
  ///  flag for starttime 
  static ConfigFlag<double>  FLG_STOPTIME;

  /// the used ODE Solver --algorithm
  static BoundedFlag<int>     FLG_ALGORITHM;

  /// output points --increment 
  static ConfigFlag<double>  FLG_INCREMENT;

  /// output points --increment 
  static ConfigFlag<double>  FLG_TOLERANCE;

  /// flag for 

  /// a consistency routine for data 
  static bool stoptimeValid(void* data);

  /// @todo *Valid(); for the rest of the flags  

  
};

#endif
