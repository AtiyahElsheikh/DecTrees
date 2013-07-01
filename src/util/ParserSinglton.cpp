/*    
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
 *  \file    ParserSinglton.cpp
 *  \copydoc DecisionNode.h 
 */


#include "ParserSinglton.h"
#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;


/// output file for the processed parser
const string ParserSinglton::_OUTFILE = "current_param.conf"; 

/**
 *
 */ 
ParserSinglton::ParserSinglton(int argc,
			       char** argv,
			       const string& fname) { 

  assert(!isCreated()); 
  _object = new eoParser(argc,argv,fname); 
  _created = true;

}



/**
 *
 */ 
ParserSinglton::~ParserSinglton() {

#ifdef DEBUG
  cout << "ParserSinglton::~ParserSinglton() called\n";
#endif 

 

#ifdef DEBUG
  cout << "ParserSinglton::~ParserSinglton() succ called\n";
#endif 

}


/**
 *
 */ 
void ParserSinglton::create(int argc,
			    char** argv,
			    const string& fname) {

  if(isCreated()) return ; 
  _singlton = new ParserSinglton(argc,argv,fname); 


}

/**
 * process parameter in the given section
 */ 
void ParserSinglton::processParam(eoParam* param,
				  const string& section) { 
  if(!isCreated()) create();
  _object->processParam(*param,section); 
}


/**
 *
 */
void ParserSinglton::generateConfFile() { 

  assert(isCreated());

  std::ofstream os;
  os.open(_OUTFILE.c_str());

  if(!os.is_open()) {
    throw std::runtime_error(_OUTFILE + " cannot be created!");
  }

  os << *_object;

  os.close();

} 
