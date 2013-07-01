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
 * \file main.cpp  a tutorial for the main components in the utility library
 *  
 * @author      Atiyah Elsheikh 
 */ 


#include "CommonFlags.h"
#include "SingltonFlag.h"
#include "ParserSinglton.h"
//#include <eo>

using namespace std; 
int main(int argc, char** argv) { 

  ParserSinglton::create(argc,argv,"current_param.conf");
  eoParser* parser = ParserSinglton::getObject();


  FlgSimDir::create(); 
  FlgAnaDer::create();
  FlgFDStep::create();

  cout << "explore : " << FlgSimDir::getObject() <<  "\n"  ; 
  FlgSimDir::getObject()->explore(NULL);
  FlgAnaDer::getObject()->explore(NULL);
  FlgFDStep::getObject()->explore(NULL);

  cout << "explore succ : \n" ; 

  ParserSinglton::generateConfFile();
  ParserSinglton::finalize();
  //	  FlgSimDir::finalize();
  FlagFuns::finalize();

}
