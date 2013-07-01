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
 * \file SingMenuDymExpPars.cpp
 * \copydoc SingMenuDymExpPars.h 
 */ 


#include "SingMenuDymExpPars.h"
#include "MenuVarsList.h"
#include "MenuDymExpPars.h"


///
ListFlag*
SingMenuDymExpPars::FLG_PARS   = (ListFlag*) 0; 

///
ListFlag*
SingMenuDymExpPars::FLG_INPARS = (ListFlag*) 0; 


///
ListFlag*
SingMenuDymExpPars::FLG_PCAND  = (ListFlag*) 0; 



/**
 *
 */ 
void
SingMenuDymExpPars::create() { 

  if(!isCreated()) {

    _singlton = new SingMenuDymExpPars(); 

    _created = true;
      
    FLG_PARS  = (ListFlag*) FlgActPars::getObject();     

    FLG_INPARS = new ListFlag(eoValueParam<string>(
			        "",
				"inpars",
				"inactive parameters",
				0,
				false), 
			      NULL);   

    FLG_PCAND = (ListFlag*) FlgParCand::getObject();

    _object = new MenuDymExpPars(FLG_INPARS,
				 FLG_PARS,
				 FLG_PCAND,
				 MenuConstants::SECPARS,
				 NULL,
				 false);

    
  } 
			 
}
