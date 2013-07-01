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
 * \file  MenuMultiStart.h
 * \class MenuMultiStart provides basic flags controling a multistart strategy  
 *                   
 *                    
 *
 * @author      Atiyah Elsheikh 
 */


#ifndef MENUMULTISTART_H
#define MENUMULTISTART_H

#include <eo>
#include "Menu.h"
#include "MenuConstants.h"
#include "ConfigFlag.h"
#include "CommonFlags.h"


using namespace std;



class MenuMultiStart:public Menu { 


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
 MenuMultiStart(Condition* cond,
		bool optional) 
   : Menu(MenuConstants::SECMULT,
	  cond,
	  optional) {
    specify();
  } 
  
  /**
   * Copy Cor 
   */ 
 MenuMultiStart(const MenuMultiStart& menu)
   : Menu(MenuConstants::SECMULT,
	  menu._condition,
	  menu.isOptional()) { }  
  
  
  /**
   * DCor
   */ 
  virtual ~MenuMultiStart() { 
#ifdef DEBUG
    cout << "MenuMultiStart::~ called\n";
#endif

    //delete _FLG_SVLOWB;   _FLG_SVLOWB   = 0; 
    //delete _FLG_SVUPPB;   _FLG_SVUPPB   = 0; 
    delete _FLG_NSTARTS;  _FLG_NSTARTS  = 0; 
    delete _FLG_SVSEED;   _FLG_SVSEED   = 0; 
    FlgSvUppBd::finalize();
    FlgSvLowBd::finalize();
  } 

  
  ///
  /// Defaults
  /// 

  static int DEF_NSTARTS; 

  ///
  /// Flags 
  ///

  
  /// lower bound of start values 
  ConfigFlag<double>*    _FLG_SVLOWB;

  /// upper bound of start values 
  ConfigFlag<double>*    _FLG_SVUPPB;

  /// # of start points  
  ConfigFlag<int>*       _FLG_NSTARTS;

  /// start values seed
  ConfigFlag<int>*       _FLG_SVSEED; 

};

#endif
