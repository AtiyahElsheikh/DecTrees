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
 * 
 * \file    MenuRegList.cpp
 * \copydoc MenuRegList.h
 *
 */ 


#include "MenuRegList.h"

using namespace std; 


/**
 *
 */ 
void MenuRegList::specify() { 

  addFlag(_inActiveRegFlag); 
  addFlag(_activeRegFlag); 
  _expVarsMenu->insertChild(this);
  //this->insertChild(_expVarsMenu);
}


/**
 * 
 */ 
bool MenuRegList::process(void *data) { 
  
  bool ret = Menu::process(data);

  //
  // 1. get all variables
  // 2. match all variables with the input regular expressions   
  // 

  vector<string> allvars =  _expVarsMenu->allids();  
  
  set<string> reginvars; 
  _inActiveRegFlag->match(allvars,reginvars);

  set<string> regvars;
  _activeRegFlag->match(allvars,regvars);

  //
  // 1 ... 
  // 2. set --vars , --invars 
  // 

  _expVarsMenu->addToActiveFlag(regvars);
  _expVarsMenu->addToInActiveFlag(reginvars);
  _expVarsMenu->refresh();

  return ret; 
}

/**
 * @overwrite
 */ 
bool
MenuRegList::explore(void *data) {
  bool ret;
  
  if(!_expVarsMenu->isExplored()) { 
    return _expVarsMenu->explore(data);
  } else { 
    bool ret = Menu::explore(data);
    return ret;
  }

}
