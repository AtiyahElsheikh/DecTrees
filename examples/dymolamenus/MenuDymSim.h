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
 * \file  MenuDymOpt.h
 * \class MenuDymOpt provides basic configuration flags  
 * 
 *
 * @author      Atiyah Elsheikh 
 * 
 * @todo generalization
 * 1-  to consider other simulators than dymola (eg. specific C++ class) 
 *     add a flag in the configuration specifying the simulation. 
 * 2-  flag for the name of an optimization menu for any 
 *     optimization software
 *
 */


#ifndef MENUDYMSIM_H
#define MENUDYMSIM_H

#include <eo>
#include "Menu.h"
#include "MenuConfiguration.h"
#include "MenuDymola.h"
#include "SingMenuDymRegVars.h"
#include "SingMenuDymRegPars.h"
#include "MenuDymExpVars.h"
#include "MenuDymExpPars.h"
#include "SingMenuExtList.h"
#include "CondDyn.h"
#include "MenuRegExtList.h"


using namespace std;

class MenuDymSim:public Menu { 


 private:
  
  /// gradient or normal simulator
  // static Condition* _COND_JSIM;


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
 MenuDymSim()    
   : Menu("",NULL,false) {
    specify();
  } 

  /**
   * Copy Cor 
   */ 
 MenuDymSim(const MenuDymSim& menu)
   : Menu("",NULL,false) { 
      assert(false);
  }  


  /**
   * DCor
   */ 
  virtual ~MenuDymSim() { 
#ifdef DEBUG
    cout << "MenuDymSim::~ called\n";
#endif
    delete _MENUCONF;    _MENUCONF   = 0; 
    delete _MENUDYM;     _MENUDYM    = 0; 

    delete _MENURSVSS;   _MENURSVSS  = 0;
    
    
    MenuExtListFactory::finalize();
    SingMenuDymExpVars::finalize();
    SingMenuDymExpPars::finalize();
    SingMenuDymRegVars::finalize();
    SingMenuDymRegPars::finalize();
    SingMenuFixedPars::finalize();
    SingMenuStartVals::finalize();
    SingMenuStValsBound::finalize();
    FlgRegPars::finalize();
    FlgMode::finalize();

  } 

  /// Configuration Menu
  static MenuConfiguration* _MENUCONF;

  /// Dymola Menu 
  MenuDymola*        _MENUDYM;

  ///
  MenuDymRegVars*    _MENUREGV;

  ///
  MenuDymRegPars*    _MENUREGP;

  ///
  MenuExtendedList<double>*  _MENUFIXP; 

  /// Menu for regular start values of a single start 
  MenuRegExtList<double>*    _MENURSVSS;

  //
  // Access Menu flags 
  //


  /**
   * @param the specified active parameters 
   */ 
  inline static void getActPars(vector<string>& ans) { 
    return  SingMenuDymExpPars::getActPars(ans);
  }

  /**
   * @param the specified reference variables
   */ 
  inline static void getRefVars(vector<string>& ans) {
    return SingMenuDymExpVars::getRefVars(ans);
  } 

  /**
   * @param specified parameter values  
   */ 
  inline static void getP0(vector<double>& ans) { 
    vector< vector<double> > vec; 
    SingMenuStartVals::getExtListVals(vec);
    assert(vec.size() == 1); 
    ans = vec[0];
  }

  /**
   *
   */
  inline double starttimeValue() { 
    return _MENUDYM->FLG_STARTTIME.flagValue(); 
  }

  /**
   *
   */
  inline double stoptimeValue() { 
    return _MENUDYM->FLG_STOPTIME.flagValue(); 
  }

  /**
   *
   */
  inline double incrementValue() { 
    return _MENUDYM->FLG_INCREMENT.flagValue(); 
  }

  /**
   *
   */
  inline int algorithmValue() { 
    return _MENUDYM->FLG_ALGORITHM.flagValue(); 
  }

  /**
   *
   */
  inline double toleranceValue() { 
    return _MENUDYM->FLG_TOLERANCE.flagValue(); 
  }

  /**
   *
   */
  inline int optimizeValue() { 
    return _MENUCONF->FLG_OPTIMIZE.flagValue(); 
  }
};

#endif
