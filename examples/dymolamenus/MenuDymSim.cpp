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


#include "MenuDymSim.h" 
#include "CondFlgVal.h"
#include "CondOr.h"

MenuConfiguration* 
MenuDymSim::_MENUCONF = 0;


/**
 *
 */ 
void MenuDymSim::specify() { 

  assert(_MENUCONF == 0); 

  _MENUCONF = 
    new MenuConfiguration((Condition *) 0,false);
  
  cout << "Configuration Menu : ";
  _MENUCONF->printFlags();

  _MENUDYM  = 
    new MenuDymola((Condition *) 0,false);
  
  cout << "Dymola Menu        : ";
  _MENUDYM->printFlags();


  /* _COND_MDSS = 
    new CondFlgVal(FlgMode::getObject(),//&_MENUCONF->FLG_MODE,
    std::string(FlagFuns::CAND_MODE[0]));*/
    

  // MenuDymRegVars automatically creates a MenuDymExpVars 
  // as a father  
  _MENUREGV = SingMenuDymRegVars::getMenu();
  cout << "DymVars MENU        : ";
  SingMenuDymExpVars::getMenu()->printFlags();

  
  _MENUREGP = SingMenuDymRegPars::getMenu(); 
  cout << "DymPars MENU        : ";
  SingMenuDymExpPars::getMenu()->printFlags();

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
	    (Condition*) 0,
	    false); 


  // regular variables need start val file
  //_MENUDATA->insertChild(_MENUREGV);
  
  _MENUCONF->insertChild(SingMenuDymExpVars::getMenu());

  _MENUCONF->insertChild(_MENUDYM);

  _MENUCONF->insertChild(SingMenuDymExpPars::getMenu());

  insertChild(_MENUCONF); 

  cout << "Dymola Opt Menu : " << "\n"; 
  this->printFlags();
}


