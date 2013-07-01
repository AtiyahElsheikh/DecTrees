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
 * \file MenuConfguration.cpp
 * \copydoc MenuConfguration.h 
 */ 

#include "MenuConfiguration.h"
#include "MenuConstants.h"
#include "myconstants.h"



using namespace std; 


/// candiate values of optsoft flag 
string   MenuConfiguration::CAND_OPTSOFT[]={"LEVMAR",
					    "IPOPT",
					    "PARADISEO"}; 

/// Default Optimization Software
string   MenuConfiguration::DEF_OPTSOFT = CAND_OPTSOFT[0];

///
string   MenuConfiguration::DEF_STVALF  = "dsin.start.txt";

///
ConfigFlag<string>* MenuConfiguration::FLG_SIMDIR = 0;

///
ConfigFlag<string>  
MenuConfiguration::FLG_STVALF(eoValueParam<string>(
				DEF_STVALF,
				"startvalfile",
				"Start Val File",
				0,
				true),
			      NULL);

///
DiscreteFlag<string,string*>
MenuConfiguration::FLG_OPTSOFT(eoValueParam<string>(
			        DEF_OPTSOFT,
				"optsoft",
				"The optimization software:[LEVMAR|IPOPT|NLOPT|PARADISEO]",
				0,
				false),
			       NULL,
			       CAND_OPTSOFT,
			       CAND_OPTSOFT+sizeof CAND_OPTSOFT/sizeof(string));    

///
BoundedFlag<int>
MenuConfiguration::FLG_OPTIMIZE(eoValueParam<int>(
				 0,
				 "optimize",
				 "Whether to run optimization if conf. complete [0/1]",
				 0,
				 true),
			      NULL,
			      0,
			      1);



/**
 *
 */ 
void MenuConfiguration::specify() { 

#ifdef DEBUG
  cout << "MenuConfiguration::Specify() called \n"; 
#endif

  /*  cout << " sizeof CAND_MODE : " << sizeof CAND_MODE << "\n";
  cout << " sizeof CAND_MODE[0] : " << sizeof CAND_MODE[0] << "\n";
  cout << " sizeof CAND_MODE : " << sizeof(string) << "\n";*/
  
 
  FLG_SIMDIR = (ConfigFlag<string>*)FlgSimDir::getObject();
  addFlag(FLG_SIMDIR);
  addFlag(&FLG_OPTSOFT); 
  addFlag(FlgMode::getObject());
  addFlag(&FLG_OPTIMIZE);
  addFlag(&FLG_STVALF);

#ifdef DEBUG  
  cout << "MenuConfiguration::Specify() succ. called \n"; 
#endif
}


