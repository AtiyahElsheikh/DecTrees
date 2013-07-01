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
 * \file MenuSingDymExpVars.cpp
 * \copydoc MenuSingDymExpVars.h 
 */ 


#include "SingMenuDymExpVars.h"
#include "MenuVarsList.h"
#include "MenuDymExpVars.h"

///
ListFlag*
SingMenuDymExpVars::FLG_VARS   = (ListFlag*) 0; 

///
ListFlag*
SingMenuDymExpVars::FLG_INVARS = (ListFlag*) 0; 


///
ListFlag*
SingMenuDymExpVars::FLG_VCAND  = (ListFlag*) 0; 



/**
 *
 */ 
void
SingMenuDymExpVars::create() { 

  if(!isCreated()) {

    _singlton = new SingMenuDymExpVars(); 

    _created = true;
      
    FLG_VARS  = new ListFlag(eoValueParam<string>(
			      "",
			      "vars",
			      "Reference Variables, default: all variable requiring start values",
			      0,
			      true),               
			    (Condition *) 0);    


    FLG_INVARS = new ListFlag(eoValueParam<string>(
			        "",
				"invars",
				"Inactive variables",
				0,
				false), 
			     (Condition *) 0);   

    FLG_VCAND  = new ListFlag(eoValueParam<string>(
			       MenuVarsList::DEF_ALL,
			       "vcand",
			       "Reference Variables Candidates",
			       0,
			       false),
			     (Condition *) 0);    


    _object = new MenuDymExpVars(FLG_INVARS,
				 FLG_VARS,
				 FLG_VCAND,
				 MenuConstants::SECVARS,
				 (Condition *) 0,
				 false);

    
  } 
			 
}
