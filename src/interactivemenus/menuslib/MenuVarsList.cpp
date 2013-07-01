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
 * \file    MenuVarsList.cpp
 * \copydoc MenuVarsList.h 
 *
 */ 


#include "MenuVarsList.h"
#include <set>
#include "myutil.h"
using namespace std; 

///  
string MenuVarsList::DEF_ALL    = "all";


/**
 *
 */ 
void MenuVarsList::specify() { 
  
  _inActiveFlag->insertChild(_activeFlag);
  _activeFlag->insertChild(_candFlag); 
  addFlag(_inActiveFlag); 
 

}


/**
 * 
 */ 
bool MenuVarsList::process(void *data) { 
  
  bool ret = Menu::process(data); 
  refresh();
  return ret; 
}


/**
 *
 */ 
/*template<typename T>
void MenuVarsList::addToActiveFlag(const T& varsset) { 
  
  _activeFlag.addValues(varsset); 

  } */



/**
 *
 */ 
/*template<typename T>
void MenuVarsList::addToInActiveFlag(const T& varsset) { 

  _inActiveFlag.addValues(varsset); 

  }*/

/**
 *
 */ 
void MenuVarsList::refresh() { 

  //
  // set1 <- all variable names 
  //

  vector<string> allvars = allids(); //_getAllIDs(NULL);
  set<string> allvarsset(allvars.begin(),allvars.end());

  //
  // invarsset <- Inactive Variables 
  //

  
  string invarsValue = _inActiveFlag->flagValue();
  set<string> invarsset; 

  if(invarsValue == DEF_ALL) { 

    set<string> s(allvars.begin(),allvars.end());
    invarsset = allvarsset; 
    _inActiveFlag->setValues(invarsset);

  } else {   // get parameters list
    
    _inActiveFlag->flagValues(invarsset); 

  }  
  

  //
  // Active Variable List 
  // varslist <- reference variables --vars  
  // 
 
  string varsValue = _activeFlag->flagValue(); 
  set<string> varsset; 
  
  if(varsValue==DEF_ALL) {
    varsset = allvarsset;
  } else {   // get variables list 
    _activeFlag->flagValues(varsset);
  }
 
  //
  // Recompute Active List  
  //

  
  _activeFlag->diffValues(invarsset); 

 

  //
  // Compute Rest Candidates  
  //

  _candFlag->setValues(allvarsset);
  _candFlag->diffValues(varsset); 
  _candFlag->diffValues(invarsset); 

 
}






