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


#ifndef MENUDYMOPT_H
#define MENUDYMOPT_H

#include <eo>
#include "Menu.h"
#include "MenuConfiguration.h"
#include "MenuDymola.h"
#include "MenuLevMar.h"
#include "MenuData.h"
#include "MenuMultiStart.h"
#include "MenuMonteCarlo.h"
#include "SingMenuDymRegVars.h"
#include "SingMenuDymRegPars.h"
#include "MenuDymExpVars.h"
#include "MenuDymExpPars.h"
#include "SingMenuExtList.h"
#include "CondDyn.h"
#include "MenuRegExtList.h"


using namespace std;

class MenuDymOpt:public Menu { 


 private:
  
  /// whether Optimization Software is Levenberg Marq. 
  static Condition* _COND_OSLM;

  /// whether mode is Single Start 
  static Condition* _COND_MDSS;

  /// whether mode is Multi Start 
  static Condition* _COND_MDMS;

  /// whether mode is Monte Carlo 
  static Condition* _COND_MDMC; 

  /// whether mode is MonteCarlo or MultiStart 
  static Condition* _COND_MDMSMC;

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
 MenuDymOpt()    
   : Menu("",NULL,false) {
    specify();
  } 

  /**
   * Copy Cor 
   */ 
 MenuDymOpt(const MenuDymOpt& menu)
   : Menu("",NULL,false) { 
      assert(false);
    }  


  /**
   * DCor
   */ 
  virtual ~MenuDymOpt() { 
#ifdef DEBUG
    cout << "MenuDymOpt::~ called\n";
#endif
    delete _MENUCONF;    _MENUCONF   = 0; 
    delete _MENUDYM;     _MENUDYM    = 0; 
    delete _MENULEVMAR;  _MENULEVMAR = 0;
    delete _MENUDATA;    _MENUDATA   = 0; 
    delete _MENUMULTI;   _MENUMULTI  = 0;
    delete _MENUMONTE;   _MENUMONTE  = 0;
    delete _MENURSVSS;   _MENURSVSS  = 0;
    delete _MENURSVBMS;  _MENURSVBMS = 0;
    delete _COND_OSLM;   _COND_OSLM  = 0; 
    delete _COND_MDSS;   _COND_MDSS  = 0;
    delete _COND_MDMC;   _COND_MDMC  = 0; 
    delete _COND_MDMS;   _COND_MDMS  = 0; 
    delete _COND_MDMSMC; _COND_MDMSMC= 0;
    
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

  /// Levenberg-Marquardt Menu
  MenuLevMar*        _MENULEVMAR; 

  /// Data Menu
  MenuData*          _MENUDATA;

  /// Multi Menu 
  MenuMultiStart*    _MENUMULTI;

  ///
  MenuMonteCarlo*    _MENUMONTE; 

  ///
  MenuDymRegVars*    _MENUREGV;

  ///
  MenuDymRegPars*    _MENUREGP;

  ///
  MenuExtendedList<double>*  _MENUFIXP; 

  /// Menu for regular start values of a single start 
  MenuRegExtList<double>*    _MENURSVSS;

  /// Menu for regular start values of a single start 
  MenuRegExtList<double>*    _MENURSVBMS;  

  //
  // Access Menu flags 
  //
  


  /**
   * whethr the choosen optimization software is LEVMAR
   */ 
  static bool isOptSoftLevMar();

  /**
   * whether the mode is multistart or montecarlo 
   */ 
  static bool isModeMultiOrMonte();

  /**
   * whether the mode is montecarlo 
   */ 
  static bool isModeMonte();


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
   * @param specified start values for SingleStart 
   */ 
  inline static void getP0(vector<double>& ans) { 
    vector< vector<double> > vec; 
    SingMenuStartVals::getExtListVals(vec);
    assert(vec.size() == 1); 
    ans = vec[0];
  }

  /**
   * @return specified min Parameter Values for Multistart  
   */ 
  inline static void getSVBound(
		   vector<double>& min,
                   vector<double>& max) { 
    vector< vector<double> > vec;
    SingMenuStValsBound::getExtListVals(vec);
    assert(vec.size() == 2); 
    min = vec[0];
    max = vec[1];
  }

};

#endif
