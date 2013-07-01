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
 * \file  MenuMultiStart.cpp 
 * \class MenuMultiStart
 */ 


#ifndef MENUMULTISTART_CPP
#define MENUMULTISTART_CPP

#include "MenuMultiStart.h"


/// 
int MenuMultiStart::DEF_NSTARTS = 8; 


/**
 *
 */ 
void MenuMultiStart::specify() { 


  ///
  _FLG_SVSEED = 
    new ConfigFlag<int>(eoValueParam<int>(
			  0,
			  "svseed",
			  "seed for start values, 0 : totally random",
			  0,
			  false),
			(Condition *) 0);

  ///
  _FLG_NSTARTS = 
    new ConfigFlag<int>(eoValueParam<int>(
			  DEF_NSTARTS,
			  "nstarts",
			  "# of start points",
			  0,
			  true),
			(Condition *) 0);


 /// 
  _FLG_SVUPPB = (ConfigFlag<double>*) FlgSvUppBd::getObject(); 
   /*new ConfigFlag<double>(eoValueParam<double>(
			    1.5,
			    "svuppb",
			    "upper range for start values > 1",
			    0,
			    false),
			    (Condition *) 0);*/


 /// 
  _FLG_SVLOWB = (ConfigFlag<double>*) FlgSvLowBd::getObject();
   /* new ConfigFlag<double>(eoValueParam<double>(
			    0.5,
			    "svlowb",
			    "lower range for start values < 1",
			    0,
			    false),
			    (Condition *) 0);*/


  addFlag(_FLG_NSTARTS);
  addFlag(_FLG_SVLOWB);
  addFlag(_FLG_SVUPPB);
  addFlag(_FLG_SVSEED);

}

#endif 
