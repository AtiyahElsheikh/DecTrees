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
 * \file  MenuParsVals.h
 * \class MenuParsVals  Menu for specifying values of parameters 
 * 
 *
 * @author      Atiyah Elsheikh  
 * 
 * eg. for a --listflag=x1,x2,x3,... the menu explores the following flags:
 * --x1_{postfix}=<val>
 * --x2_{postfix}=<val> ... 
 */


#ifndef MENUPARSVALS_H
#define MENUPARSVALS_H


#include "MenuExtendedList.h"
using namespace std; 


class MenuParsVals : public MenuExtendedList<double> { 

 private:

  

 protected:

  /**
   * default values of unspecified parameters 
   */ 
  virtual vector<double> defaults(); 


  /**
   * extra flag for start val file ?
   */ 
  // protected specify(); 
 
 public:

   /**
   * Cor.
   */ 
 MenuParsVals(ListFlag* list,
	      const string& postfix,
	      const string& section,
	      const Condition& cond,
	      bool optional) 
   : Menu(section,cond,optional),
    _listflag(list),
    _postfix(postfix) { 
      // specify(); 
    }


  /**
   * CopyCor 
   */ 
  MenuParsVals(const MenuParsVals& menu)
    : Menu(menu._section,menu._condition,menu.isOptional()),
    _listflag(menu._listflag),
    _postfix(menu._postfix) { 
    //specify(); 
  }


  /**
   * DCor 
   */ 
  ~MenuParsVals() { } 
 
  
  
};

#endif 
