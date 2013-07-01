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
 * \file  MenuLevMar.h
 * \class MenuLevMar provides basic flags for the optimization 
 *                   software LEVMAR 
 *                    
 * 
 *
 * @author      Atiyah Elsheikh 
 */


#ifndef MENULEVMAR_H
#define MENULEVMAR_H

#include <eo>
#include "Menu.h"
#include "MenuConstants.h"
#include "BoundedFlag.h"
#include "DiscreteFlag.h"
#include "CommonFlags.h"


using namespace std;



class MenuLevMar:public Menu { 


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
 MenuLevMar(Condition* cond,
	    bool optional) 
   : Menu(MenuConstants::SECOPTM,cond,optional) {
    specify();
  } 
  
  /**
   * Copy Cor 
   */ 
 MenuLevMar(const MenuLevMar& menu)
   : Menu(MenuConstants::SECOPTM,menu._condition,menu.isOptional()) { }  
  
  
  /**
   * DCor
   */ 
  virtual ~MenuLevMar() { 
#ifdef DEBUG
    cout << "MenuLevMar::~ called\n";
#endif

    delete _FLG_PSCALING; _FLG_PSCALING = 0; 
    delete _FLG_MAXITER; _FLG_MAXITER  = 0;
    delete _FLG_LAMBDA;  _FLG_LAMBDA   = 0; 
    delete _FLG_STOP_JE; _FLG_STOP_JE  = 0; 
    delete _FLG_STOP_DP; _FLG_STOP_DP  = 0; 
    delete _FLG_STOP_E;  _FLG_STOP_E   = 0;
    // FlgAnaDer::finalize(); call FlagFuns::finalize();
  } 


  /// candiate values of optsoft flag 
  static string CAND_PSCALING[]; 
  
  ///
  /// Flags 
  ///

  /// flag for optimization software 
  DiscreteFlag<string,string*>* _FLG_PSCALING; 
  
  /// max. number of iterations 
  ConfigFlag<int>*      _FLG_MAXITER;

  /// start lambda of LM 
  ConfigFlag<double>*   _FLG_LAMBDA;

  /// stop criteria ||J^T * e||_{inf} : change in the goal function 
  ConfigFlag<double>*   _FLG_STOP_JE; 

  /// stop criteria || D * p || : change in the scaled optimization variables 
  ConfigFlag<double>*   _FLG_STOP_DP; 

  /// stop criteria || e || : value of the goal function  
  ConfigFlag<double>*   _FLG_STOP_E; 

};

#endif
