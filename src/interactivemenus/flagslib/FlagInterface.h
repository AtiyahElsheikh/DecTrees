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
 * \file  FlagInterface.h
 * \interface FlagInterface Interface representing basic functionalities of a flag   
 * 
 * @author      Atiyah Elsheikh 
 * 
 */


#ifndef FLAGINTERFACE_H
#define FLAGINTERFACE_H

#include "DecisionNode.h"
#include <string>
#include "eoParam.h"
//#include <eo>
 
using namespace std; 

class FlagInterface:public DecisionNode { 

 private:
 
 protected:
  
  /**
   * insert possible values to the description of the flag  
   */ 
  //virtual void updateDescription() = 0; 

 public:

  /**
   * Cor
   */ 
 FlagInterface(Condition* cond,
	       bool optional)
   : DecisionNode(cond,optional)
   { } 


  /**
   * Copy Cor
   */ 
  FlagInterface(const FlagInterface& flag)
   : DecisionNode(flag._condition,flag.isOptional())
   { } 


  /**
   * DCor 
   */ 
  virtual ~FlagInterface() { 
#ifdef DEBUG
    cout << "FlagInterface::~ called\n";
#endif 

#ifdef DEBUG
    cout << "FlagInterface::~ succ. called\n";
#endif 
  }

  /**
   * Key of the flag 
   */ 
  virtual string flagKey() const = 0;

  /**
   * whether a flag is given by the user (eg. --flag=val)
   */ 
  virtual bool flagExist()const  = 0; 

  /**
   *
   */ 
  virtual void* value() = 0; 

  /**
   * return the value of the flag as a string 
   */
  virtual string getValueAsStr() const = 0; 

  /**
   *
   */ 
  virtual eoParam* getEOParam()=0;

  /**
   * set the value 
   */ 
  virtual void setValue(const string& val)=0; 


  /**
   *
   */ 
  virtual bool isProcessed() const = 0;
  /**
   * The section where flag get processed 
   */ 
  /* inline const string& getSection() { 
    return _section; 
    }*/

  /**
   * The section where flag get processed
   */ 
  /*inline void setSection(const string& str) { 
    _section = str; 
    }*/
};

#endif
