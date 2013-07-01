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
 * \file MenuDymExpVars.cpp
 * \copydoc MenuDymExpVars.h 
 */ 


#include "StdDymSimSinglton.h"
#include "MenuDymExpVars.h"



/**
 *
 */ 
MenuDymExpVars::MenuDymExpVars(ListFlag* invars,
		 ListFlag* vars,
		 ListFlag* cands,
		 const string& section,
		 Condition* cond,
		 bool optional)
    : MenuVarsList(invars,vars,cands,
		   section,cond,optional) { } 


/**
 *
 */ 
MenuDymExpVars::MenuDymExpVars(const MenuDymExpVars& menu)
   :  MenuVarsList(menu._inActiveFlag,
		menu._activeFlag,
		menu._candFlag,
		menu._section,
		menu._condition,
		menu.isOptional())
    { 
      assert(false); 
    }  

/**
 *
 */ 
vector<string> MenuDymExpVars::allids() { 
  return StdDymSimSinglton::getAllVars();  
}



