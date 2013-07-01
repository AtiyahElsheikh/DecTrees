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


#include "SingMenuExtList.h"
#include "MenuVarsList.h"
#include "MenuDymParsVals.h"
#include "SingMenuDymRegPars.h"
#include "CommonFlags.h"

#ifndef SINGMENUEXTLIST_CPP
#define SINGMENUEXTLIST_CPP

///
template<MenuExtendedList<double>* func()>
string
SingMenuExtList<func>::_postfix   = ""; 


///
template<MenuExtendedList<double>* func()>
ListFlag*
SingMenuExtList<func>::_listflag   = (ListFlag*) 0; 


///
template<MenuExtendedList<double>* func()>
MenuExtendedList<double>* 
SingMenuExtList<func>::_object = (MenuExtendedList<double>*)0;


///
template<MenuExtendedList<double>* func()>
bool SingMenuExtList<func>::_created = false;


///
template<MenuExtendedList<double>* func()>
SingMenuExtList<func>*
SingMenuExtList<func>::_singlton = 0;


/**
 *
 */ 
template<MenuExtendedList<double>* func()>
void
SingMenuExtList<func>::create() {  

  if(!isCreated()) { 
    _created = true; 
    _singlton = new SingMenuExtList(); 
    _object = func();   
  }

}


/**
 *
 */ 
template<MenuExtendedList<double>* func()>
void 
SingMenuExtList<func>::finalize() { 
  if(isCreated()) delete _singlton; 
}

/**
 *
 */ 
template<MenuExtendedList<double>* func()>
bool 
SingMenuExtList<func>::isCreated() { 
  return _created; 
}


/**
 *
 */ 
template<MenuExtendedList<double>* func()>
SingMenuExtList<func>*
SingMenuExtList<func>::getSinglton() { 
  return _singlton; 
}

/**
 *
 */ 
template<MenuExtendedList<double>* func()>
MenuExtendedList<double>* 
SingMenuExtList<func>::getObject()  { 
  if(!isCreated()) create();
  return _object;
}


#endif

