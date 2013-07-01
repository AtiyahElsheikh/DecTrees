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
 * \file  ParserSinglton.h
 * \class ParserSinglton generates a unique parser which will be 
 *        used throughout the whole program   
 * 
 * @author      Atiyah Elsheikh 
 * @version     1.0
 */


#ifndef PARSERSINGLTON_H
#define PARSERSINGLTON_H

//#include <eo>
#include "SingltonTemplate.h"
#include "eoParser.h"
using namespace std; 

class ParserSinglton; 

class ParserSinglton: public SingltonTemplate<eoParser> { 


 private:


  /// output file for the processed parser
  static const string _OUTFILE; 


 protected:

  /**
   * Empty Constructor 
   */ 
  ParserSinglton() { }

  
  /**
   * DCor
   */ 
  virtual ~ParserSinglton(); 

  
  /**
   * Constructor called by create to prpduce a unique eoParser initialized
   * using usually online arguments 
   * 
   * @param number of argumetns in argv
   * @param arguments 
   * @param filename to produce the output 
   */ 
  ParserSinglton(int argc,
		 char** argv,
		 const string& fname);

 public:

  /**
   * @todo create() without arguments 
   * Constructor called by create to prpduce a unique eoParser initialized
   * using usually online arguments 
   * 
   * @param number of argumetns in argv
   * @param arguments 
   * @param filename to produce the output 
   */ 
  static void create(int argc,char** argv,const string& fname);


  /**
   *
   */ 
  inline static void create() { 
    assert(false);
  }

  /**
   * process parameter in the given section
   * @param parameter flag
   * @param section 
   */ 
  static void processParam(eoParam* param,const string& section);


  
  /**
   *
   */ 
  static void generateConfFile(); 

}; 


#endif 

