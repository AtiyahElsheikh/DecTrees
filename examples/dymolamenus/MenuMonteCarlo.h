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
 * \file  MenuMonteCarlo.h
 * \class MenuMonteCarlo provides basic flags controling a 
 *                       MonteCarlo Simulation   
 *                                       
 * @author      Atiyah Elsheikh 
 */


#ifndef MENUMONTECARLO_H
#define MENUMONTECARLO_H

#include <eo>
#include "Menu.h"
#include "MenuConstants.h"
#include "ConfigFlag.h"



using namespace std;



class MenuMonteCarlo:public Menu { 


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
 MenuMonteCarlo(Condition* cond,
		bool optional) 
   : Menu(MenuConstants::SECMONT,
	  cond,
	  optional) {
    specify();
  } 
  
  /**
   * Copy Cor 
   */ 
 MenuMonteCarlo(const MenuMonteCarlo& menu)
   : Menu(MenuConstants::SECMONT,
	  menu._condition,
	  menu.isOptional()) { }  
  
  
  /**
   * DCor
   */ 
  virtual ~MenuMonteCarlo() { 
#ifdef DEBUG
    cout << "MenuMonteCarlo::~ called\n";
#endif

    delete _FLG_MCSTDDIV;   _FLG_MCSTDDIV   = 0; 
    delete _FLG_NMONTS;     _FLG_NMONTS     = 0; 
    delete _FLG_MCSEED;     _FLG_MCSEED     = 0; 
  } 

  
  ///
  /// Defaults
  /// 

  static int DEF_NMONTS; 

  ///
  /// Flags 
  ///
  
  /// lower bound of start values 
  ConfigFlag<double>*    _FLG_MCSTDDIV;

  /// upper bound of start values 
  ConfigFlag<int>*    _FLG_NMONTS;

  /// # of start points  
  ConfigFlag<int>*       _FLG_MCSEED;

};

#endif
