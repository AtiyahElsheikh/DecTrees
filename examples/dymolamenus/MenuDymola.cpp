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
 * \file MenuDymola.cpp
 * \copydoc MenuDymola.h
 * 
 */ 


#include "MenuDymola.h"
#include "MenuConstants.h"
#include "myconstants.h"


using namespace std; 


/// starttime 
double MenuDymola::DEF_STARTTIME = myconstants::KEYS_DEF_VAL[0].second; 

/// stoptime 
double MenuDymola::DEF_STOPTIME  = myconstants::KEYS_DEF_VAL[1].second;  

/// Increment 
double MenuDymola::DEF_INCREMENT = myconstants::KEYS_DEF_VAL[2].second;

/// Increment 
double MenuDymola::DEF_TOLERANCE = myconstants::KEYS_DEF_VAL[4].second;

/// Algorithm  
int MenuDymola::DEF_ALGORITHM    = myconstants::KEYS_DEF_VAL[6].second;


///
/// @todo this way of declaration may lead to error, 
/// since DEF_TOLERANCE may have not instantiated yet  	      
///
ConfigFlag<double>
MenuDymola::FLG_TOLERANCE(eoValueParam<double>(
			    DEF_TOLERANCE,
			    "tolerance",
			    "solver tolerance of results : [1e-8]",
			    0,
			    false),
			  NULL);

///
ConfigFlag<double>
MenuDymola::FLG_INCREMENT(eoValueParam<double>(
			    DEF_INCREMENT,
			    "increment",
			    "increment of results : [0.2]",
			    0,
			    false),
			  (Condition *) 0);
	
///   
BoundedFlag<int>
MenuDymola::FLG_ALGORITHM(eoValueParam<int>(
                            DEF_ALGORITHM,
			    "algorithm",
			    "DAE Algorithm : [1-14]",
			    0,
			    false),
			  (Condition *) 0,
			  1,14);

///
ConfigFlag<double>  
MenuDymola::FLG_STARTTIME(eoValueParam<double>(  
			      DEF_STARTTIME,
			      "starttime",
			      "simulation start time [0] ",
			      0,
			      false),
			  (Condition *) 0); 

///
ConfigFlag<double>  
MenuDymola::FLG_STOPTIME(eoValueParam<double>(  
			      DEF_STOPTIME,
			      "stoptime",
			      "simulation stop time [1.0] ",
			      0,
			      false),
			 (Condition *) 0); //""); 


/**
 * A consistency routine for stoptime flag 
 */ 
bool MenuDymola::stoptimeValid(void* data) { 

  if( MenuDymola::FLG_STOPTIME.flagValue() <= 
      MenuDymola::FLG_STARTTIME.flagValue() )
    cerr << "stoptime < starttime ???\n"; 

  return MenuDymola::FLG_STOPTIME.flagValue() >= 
    MenuDymola::FLG_STARTTIME.flagValue(); 

}


/**
 *
 */ 
void MenuDymola::specify() { 


  FLG_STOPTIME.setProccessFunc(&stoptimeValid);
  FLG_STARTTIME.insertChild(&FLG_STOPTIME);
  
  addFlag(&FLG_STARTTIME);
  addFlag(&FLG_INCREMENT);
  addFlag(&FLG_ALGORITHM);
  addFlag(&FLG_TOLERANCE); 
  
}


