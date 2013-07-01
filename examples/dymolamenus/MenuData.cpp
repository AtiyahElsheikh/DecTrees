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
 * \file  MenuData.cpp 
 * \class MenuData
 */ 


#ifndef MENUDATA_CPP
#define MENUDATA_CPP

#include "MenuData.h"



///
string MenuData::DEF_DATAFILE = "dsin.start.txt";



/**
 *
 */ 
void MenuData::specify() { 

  _FLG_DATAFILE 
    = new ConfigFlag<string>(eoValueParam<string>(
                               DEF_DATAFILE,
			       "datafile",
			       "input file for generating silico data default " + DEF_DATAFILE,
			       0,
			       true),
			     (Condition *) 0);


  _FLG_DSEED 
    = new ConfigFlag<int>(eoValueParam<int>(
			    0,
			    "dseed",
			    "seed for silico data generation [0]: totaly random",
			    0,
			    false),
			  (Condition *) 0);


  _FLG_DSTDDIV
    = new ConfigFlag<double>(eoValueParam<double>(
			       0.0,			       
			       "dstddiv",
			       "Std Div. for silico data [0]: Exact Data",
			       0,
			       false),
			     (Condition *) 0);
					 
  addFlag(_FLG_DATAFILE);
  addFlag(_FLG_DSEED);
  addFlag(_FLG_DSTDDIV);

}






#endif 
