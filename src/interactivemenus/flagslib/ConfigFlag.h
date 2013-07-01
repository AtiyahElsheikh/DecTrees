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
 * \file  ConfigFlag.h
 * \class ConfigFlag represents a flag and its dependencies accoarding to its value   
 * 
 * @author      Atiyah Elsheikh 
 * 
 */


#ifndef CONFIGFLAG_H
#define CONFIGFLAG_H 

//#include <eo>
#include "eoParam.h"
#include "FlagInterface.h"
using namespace std; 


template<typename T> 
class ConfigFlag:public FlagInterface { 

 private: 

  /// flag attribute 
  eoValueParam<T>  _flag; 

  /// the value of the flag  
  T _val;

  /// whether the flag has been processed 
  bool _processed; 
  
 protected:
 
  /**
   *
   */ 
  virtual bool process(void* data); 



 public:

 

  /**
   * Cor. 
   * 
   * @param the flag  
   * @param section of the flag 
   * @param condition to process this flag 
   */ 
  ConfigFlag(const eoValueParam<T>& flag,
	     Condition* condition);


  /**
   * Cor 
   * 
   * @param the identity of a flag 
   * @param true
   */ 
  //ConfigFlag(const string& flagid): 
  //ConfigFlag(eoValueParam<T>(0,flagid,"",0,true),Condition(true)) { }


  /**
   * copy construcor 
   */ 
  ConfigFlag(const ConfigFlag<T>& param);

  /**
   * Destructor 
   */ 
  virtual ~ConfigFlag();

  /**
   *
   */ 
  virtual string flagKey() const; 
 
  /**
   *
   */ 
  T flagValue() const;


  /**
   * return the value of the flag as a string 
   */
  virtual string getValueAsStr() const;
  

  /**
   *
   */ 
  virtual bool flagExist() const; 

  /**
   * the value of the flag 
   */
  virtual void* value();

  /**
   * set the value of the flag 
   */  
  virtual void setValue(const string& val); 

  /**
   *
   */ 
  virtual eoParam* getEOParam(); 

  /**
   * whether this flag has been processed 
   */ 
  inline bool isProcessed() const { 
    return _processed; 
  }

 
};

#include "ConfigFlag.cpp"

#endif
