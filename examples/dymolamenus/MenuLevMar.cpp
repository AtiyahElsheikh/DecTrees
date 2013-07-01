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
 * \file  MenuLevMar.cpp 
 * \class MenuLevMar
 */ 


#ifndef MENULEVMAR_CPP
#define MENULEVMAR_CPP

#include "MenuLevMar.h"
#include "MenuConfiguration.h"

///
string MenuLevMar::CAND_PSCALING[] = 
  {"none","log","plog","unity","dynunity"}; 


/**
 *
 */ 
void MenuLevMar::specify() { 

  /// 
  _FLG_PSCALING 
    = new DiscreteFlag<string,string*>(
       eoValueParam<string>(
	 CAND_PSCALING[0],
	 "pscaling",
	 "parameter scaling type : [none,log,plog,unity,dynunity]",
	 0,
	 false),
       (Condition *) 0,
       CAND_PSCALING,
       CAND_PSCALING+sizeof CAND_PSCALING/sizeof(string));  


  _FLG_MAXITER 
    = new ConfigFlag<int>(eoValueParam<int>(
			    50,
			    "maxiter",
			    "maximum number of iterations",
			    0,
			    false),
			  (Condition *) 0);

  _FLG_LAMBDA 
    = new ConfigFlag<double>(eoValueParam<double>(
			       10.0,
			       "lambda",
			       "start lambda for Levenberg-Marquardt",
			       0,
			       false),
			  (Condition *) 0);
			  
  _FLG_STOP_JE
    = new ConfigFlag<double>(eoValueParam<double>(
			       1e-20,
			       "stop_Je",
			       "stop criteria ||J^T e||_{inf} < ?",
			       0,
			       false),
			  (Condition *) 0);

  _FLG_STOP_DP = 	    
    new ConfigFlag<double>(eoValueParam<double>(
                             1e-20,
			     "stop_Dp",
			     "stop criteria change in the scaled opt. variables ||Dp|| < ",
			     0,
			     false),
			  (Condition *) 0);

  _FLG_STOP_E = 
    new ConfigFlag<double>(eoValueParam<double>(
			     0.0,
			     "stop_e",
			     "stop criteria value of the goal function ||e|| < ",
			     0,
			     false),
			  (Condition *) 0);


  addFlag(_FLG_MAXITER);
  addFlag(_FLG_LAMBDA);
  addFlag(_FLG_PSCALING);
  addFlag(_FLG_STOP_JE);
  addFlag(_FLG_STOP_DP);
  addFlag(_FLG_STOP_E);
  FlgAnaDer::getObject()->insertChild(FlgFDStep::getObject());
  addFlag(FlgAnaDer::getObject());
  
}






#endif 
