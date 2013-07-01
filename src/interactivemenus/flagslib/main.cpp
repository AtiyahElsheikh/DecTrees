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
 * @version     1.0
 */ 

//#include <eo>
#include "ParserSinglton.h"
#include "ConfigFlag.h"
#include <cstdlib>
#include <iostream> 
#include "CondDyn.h"


bool falseCondition(); 

bool f1Is2(); 

ConfigFlag<int>* flag1; 

///
void testConditions(); 

///
void testFlags(int,char**);

///
void testDymMenu(int,char**); 

using namespace std; 
int main(int argc, char** argv) { 

  // testConditions();
  testFlags(argc,argv);
  // testDymMenu(argc,argv);

}


bool f1Is2(){ 
  cout << "&flag1 : " << flag1 << " = " << flag1->flagValue() << "\n" ;
  bool ret = flag1->flagValue() == 2; 
  return ret;
}


bool falseCondition() { 
  return false; 
}


void testConditions() { 
  Condition c1(true); 
  cout << c1.evaluate() << "\n";

  bool (*foo)() = &falseCondition; 
  CondDyn c2(foo);
  cout << c2.evaluate() << "\n";

  CondDyn c3(&falseCondition); 
  cout << c3.evaluate() << "\n";
}


void testFlags(int argc,char** argv) { 
  ParserSinglton::create(argc,argv,"current_param.conf"); 
  eoParser* parser = ParserSinglton::getObject();

  eoValueParam<int> *f1 = 
    new eoValueParam<int>(3,
			  "flag1",
			  "first flag [2,3]",
			  0,
			  true);
 
  flag1  = new ConfigFlag<int>(*f1,NULL);
 
  eoValueParam<int> *f2 = 
    new eoValueParam<int>(2,
			  "flag2",
			  "2nd flag [2,3]",
			  0,
			  true);

  bool (*foo2)() = &f1Is2 ; 
  cout << "foo2 declared \n"; //<< foo2 << "\n";
  CondDyn cond2(foo2); 
  cout << "cond2 declared \n"; 
  ConfigFlag<int> flag2(*f2,
			&cond2);
  cout << "flag2 declared : " << &flag2 <<"\n";

  eoValueParam<int> *f3 = new eoValueParam<int>(3,
						"flag3",
						"3rd flag [2,3]",
						0,
						true);
  
  ConfigFlag<int> flag3(*f3,NULL);//,"1. Section");
  cout << "flag 3 declared : " << &flag3 << "\n"; 

  flag1->insertChild(&flag2);
  cout << "flag2 child of flag1 \n";
  flag2.insertChild(&flag3);
  cout << "flag3 child of flag2 \n";

  cout << "Exploring : "  << "\n";
  flag1->explore(NULL); 
 
  ParserSinglton::generateConfFile();
  ParserSinglton::finalize(); 

  delete f1; 
  delete f2;
  delete f3;
  delete flag1;

  cout << "flag 1 deleted\n";
 
  cout << "Parsers finalized \n";

}

/**
 *
 */ 
void testDymMenu(int argc,char** argv) { 
  ParserSinglton::create(argc,argv,"current_param.conf"); 
  eoParser* parser = ParserSinglton::getObject();
 
 
  ParserSinglton::generateConfFile();
  ParserSinglton::finalize(); 
}

