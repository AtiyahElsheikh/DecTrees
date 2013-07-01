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
 * \file MenuDymOpt.cpp
 * \copydoc MenuDymOpt.h 
 */ 


#include "MenuDymOpt.h" 
#include "CondFlgVal.h"
#include "CondOr.h"

MenuConfiguration* 
MenuDymOpt::_MENUCONF = 0;

Condition*
MenuDymOpt::_COND_OSLM = (Condition *) 0; 

Condition*
MenuDymOpt::_COND_MDSS = (Condition *) 0; 

Condition*
MenuDymOpt::_COND_MDMS = (Condition *) 0; 

Condition*
MenuDymOpt::_COND_MDMC = (Condition *) 0; 

Condition*
MenuDymOpt::_COND_MDMSMC = (Condition *) 0; 


#include "CondDyn.h"


/**
 *
 */ 
void MenuDymOpt::specify() { 

  assert(_MENUCONF == 0); 

  _MENUCONF = 
    new MenuConfiguration((Condition *) 0,false);
  
  cout << "Configuration Menu : ";
  _MENUCONF->printFlags();

  _MENUDYM  = 
    new MenuDymola((Condition *) 0,false);
  
  cout << "Dymola Menu        : ";
  _MENUDYM->printFlags();


  _COND_OSLM = new CondDyn(&MenuDymOpt::isOptSoftLevMar);
  _MENULEVMAR 
    = new MenuLevMar(_COND_OSLM,
		     false);
  cout << "LevMar Menu        : ";
  _MENULEVMAR->printFlags();

  _MENUDATA =
    new MenuData((Condition *) 0,false);
  cout << "Data Menu          : ";
  _MENUDATA->printFlags();


  _COND_MDSS = 
    new CondFlgVal(FlgMode::getObject(),//&_MENUCONF->FLG_MODE,
		   std::string(FlagFuns::CAND_MODE[0]));
    
  _COND_MDMS = //new CondDyn(&MenuDymOpt::isModeMultiOrMonte);
    new CondFlgVal(FlgMode::getObject(),
		   std::string(FlagFuns::CAND_MODE[1]));

  _COND_MDMC = new CondDyn(&MenuDymOpt::isModeMonte);

  _COND_MDMSMC = new CondOr(_COND_MDMC,_COND_MDMS);

  _MENUMULTI = 
    new MenuMultiStart(_COND_MDMSMC,
		       false);
  cout << "Multi Menu          : ";
  _MENUMULTI->printFlags();

  _MENUMONTE = 
    new MenuMonteCarlo(_COND_MDMC,
		       false);

  cout << "MONTE Menu          : ";
  _MENUMONTE->printFlags();

 


  // MenuDymRegVars automatically creates a MenuDymExpVars 
  // as a father  
  _MENUREGV = SingMenuDymRegVars::getMenu();
  cout << "DymVars MENU        : ";
  SingMenuDymExpVars::getMenu()->printFlags();


  _MENUREGP = SingMenuDymRegPars::getMenu(); 

  // MenuFixedPars is automatically the 
  // child of SingMenuDymRegPars
  _MENUFIXP = SingMenuFixedPars::getMenu();
  
  // MenuStartVals is automatically 
  // the child of SingMenuDymRegPars and the father MenuRegStartVal
  _MENURSVSS  
     = new MenuRegExtList<double>
           (SingMenuStartVals::getMenu(),
	    (RegListFlag *)FlgRegPars::getObject(),
	    MenuConstants::SECRSV,
	    _COND_MDSS,
	    false); 


  // MenuStValsBound is automatically 
  // the child of SingMenuDymRegPars and the father MenuRegStValBound
  _MENURSVBMS  
    = new MenuRegExtList<double>
          (SingMenuStValsBound::getMenu(),
	   (RegListFlag *)FlgRegPars::getObject(),
	   MenuConstants::SECRSVB,
	   _COND_MDMSMC,
	   false); 
  
  cout << "DymPars MENU        : ";
  SingMenuDymExpPars::getMenu()->printFlags();

  
  _MENUREGV->insertChild(SingMenuDymExpPars::getMenu());
  
  _MENUMULTI->insertChild(_MENUMONTE);

  _MENUDATA->insertChild(_MENUMULTI); 

  // regular variables need start val file
  //_MENUDATA->insertChild(_MENUREGV);
  
  _MENUDATA->insertChild(SingMenuDymExpVars::getMenu());

  _MENUCONF->insertChild(_MENUDYM);
  
  _MENUCONF->insertChild(_MENULEVMAR); 
  
  _MENUCONF->insertChild(_MENUDATA);
   
  //_MENUMULTI->insertChild(_MENUREGP); 
 
  //_MENUMONTE->insertChild(_MENUREGP); 

  insertChild(_MENUCONF); 

  cout << "Dymola Opt Menu : " << "\n"; 
  this->printFlags();
}


/**
 *
 */ 
bool MenuDymOpt::isOptSoftLevMar() { 
  return _MENUCONF->FLG_OPTSOFT.flagValue() == 
    MenuConfiguration::CAND_OPTSOFT[0] ; 
}


/**
 *
 */ 
bool MenuDymOpt::isModeMultiOrMonte() { 
  return (((DiscreteFlag<string,string*>*)FlgMode::getObject())->flagValue()
	  == FlagFuns::CAND_MODE[1]) || isModeMonte(); 
}


/**
 *
 */ 
bool MenuDymOpt::isModeMonte() { 
  return ( ((DiscreteFlag<string,string*>*)FlgMode::getObject())->flagValue()
	  == FlagFuns::CAND_MODE[2]); 
}
