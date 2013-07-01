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

using namespace std;

#include "mytypes.h"
#include "regex.h"
#include "myutil.h"
#include <eo>
#include <cstdio>
#include <unistd.h>


//#include "SingMenuDymExpVars.h"
//#include "SingMenuDymRegVars.h"
#include "SingMenuExtList.h"
//#include "MenuDymExpVars.h"
#include "CommonFlags.h"
#include "SingMenuDymExpPars.h"
//#include "SingMenuDymRegPars.h"
#include "MenuDymExpPars.h"
#include "StdDymSimSinglton.h"
//#include "MenuExtListFactory.h"
//#include "RegListFlag.h"
#include "MenuDymOpt.h"
#include "MenuRegExtList.h"


/**
 * simulate the dymola model 
 */
string masterid = ".master"; 


/**
 *
 */
int main(int argc, char** argv) { 

  cout << "Parser\n"; 
  ParserSinglton::create(argc,argv,"current_param.conf"); 
  eoParser* parser = ParserSinglton::getObject();

  ConfigFlag<string>* simdir = 
    (ConfigFlag<string>*) FlgSimDir::getObject();
  simdir->explore(NULL);
 
  StdDymSimSinglton::create("dsres.txt",
			    "dsin.txt",  
			    masterid,
			    simdir->flagValue()); 
  
  MenuDymOpt dymoptmenu; 
  bool res = dymoptmenu.explore(NULL);
  cout << "Exploring : " << res << "\n";  
  
 

  cout << "ConfFile \n"; 
  ParserSinglton::generateConfFile();

  cout << "finalize \n"; 
  ParserSinglton::finalize();  
  StdDymSimSinglton::finalize();
  FlagFuns::finalize();
  cout << "main finish\n";
 
}

