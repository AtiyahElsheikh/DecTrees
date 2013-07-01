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
 * \file ConfigFlag.cpp
 * \copydoc ConfigFlag.h
 */ 


#ifndef CONFIGFLAG_CPP
#define CONFIGFLAG_CPP

//#include <eo>
#include "ConfigFlag.h"
#include "ParserSinglton.h"
#include <sstream>

using namespace std; 



/**
 *
 */ 
template<typename T>
ConfigFlag<T>::ConfigFlag(const eoValueParam<T>& flag,
			  Condition* condition)
  : FlagInterface(condition,!flag.required()), 
    _flag(flag.value(),
	  flag.longName(),
	  flag.description(),
	  flag.shortName(),
	  flag.required()) { 
  _processed = false; 
} 


/**
 *
 */
/*template<typename T> 
ConfigFlag<T>::ConfigFlag(const ConfigFlag<T>& param)
  : FlagInterface(param._condition,param.isOptional()),
    _flag(param._flag),
    _processed(param._processed)
    { }*/ 
template<typename T> 
ConfigFlag<T>::ConfigFlag(const ConfigFlag<T>& param)
  : FlagInterface(param._condition,param.isOptional()),
    _flag(param._flag.value(),
	  param._flag.longName(),
	  param._flag.description(),
	  param._flag.shortName(),
	  param._flag.required()),
    _processed(param._processed)
{ }  


/**
 *
 */
/*template<typename T>
void
ConfigFlag<T>::updateDescription() { 
  string& desc = _flag.description(); 
  desc = desc + " : [" + flagValue() + "]" ; 
  }*/

/**
 *
 */ 
template<typename T>
ConfigFlag<T>::~ConfigFlag() { 

#ifdef DEBUG
  cout << "ConfigFlag::~ of " << flagKey() <<" called\n";
#endif 

#ifdef DEBUG
  cout << "ConfigFlag::~ of " << flagKey() << " succ. called\n";
#endif 
}


/**
 *  
 */ 
template<typename T>
bool ConfigFlag<T>::process(void* data) { 

#ifdef DEBUG
  cout << "ConfigFlag<T>::process called\n";
#endif 

  if(isProcessed()) { 
    cerr << "cannot process the same flag twice, meaningless\n";
    assert(false);
  } 

  _processed = true; 

  bool ret = true;
  
  
  const string& section = data == 0? "" : *((string *) data);//getSection(); 
  ParserSinglton::processParam(&_flag,section);

  if(_flag.required() && !ConfigFlag<T>::flagExist()) {
    cout << "Specify : --" << ConfigFlag<T>::flagKey() << "\n";  
    ret = false;
  }

  /// additional processing 
  if(!isProcessFuncNull())  { 
    //if(data == NULL)
    bool temp = applyProcessFunc(this);
    ret = ret && temp;
    /*else 
      ret = ret && applyProcessFunc(data);*/
  }

#ifdef DEBUG 
  cout << "processing " << flagKey() << " " << ret << "\n";  
#endif 
  return ret ; 
}


/**
 *
 */ 
template<typename T>
string ConfigFlag<T>::flagKey() const { 
  return _flag.longName();
}


/**
 *
 */ 
template<typename T>
T ConfigFlag<T>::flagValue() const {
  //assert(isExplored()); 
  return _flag.value();
}


/**
 *
 */ 
template<typename T>
bool ConfigFlag<T>::flagExist() const { 
  //assert(isExplored());
  eoParser* parser = ParserSinglton::getObject();
  eoParam* ptr =(eoParam*)&_flag; 
  return parser->isItThere(*ptr);
}


/**
 *
 */ 
template<typename T>
void* ConfigFlag<T>::value() { 
  _val = flagValue(); 
  void* ptr = (void *)&_val; 
  return ptr;
}


/**
 * set the value of the flag 
 */  
template<typename T>
void ConfigFlag<T>::setValue(const string& val) { 
  _flag.setValue(val);
  _val = _flag.value();
} 


/**
 *
 */ 
template<typename T>
eoParam* ConfigFlag<T>::getEOParam() { 
  return &_flag; 
}


/**
 * return the value of the flag as a string 
 */
template<typename T>
string ConfigFlag<T>::getValueAsStr() const { 
  ostringstream s;
  s << flagValue();
  return s.str();
}

#endif
