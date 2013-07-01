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
 * \file  MenuDymParsVals.h
 * \class MenuDymParsVals specifying values of parameters 
 * 
 *
 * @author      Atiyah Elsheikh a.elsheikh@fz-juelich.de 
 * 
 * eg. for a --listflag=x1,x2,x3,... the menu explores the following flags:
 * --x1_{postfix}=<val>
 * --x2_{postfix}=<val> ... 
 */


#ifndef MENUDYMPARSVALS_H
#define MENUDYMPARSVALS_H


#include "MenuExtendedList.h"
using namespace std; 


class MenuDymParsVals : public MenuExtendedList<double> { 

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
 MenuDymParsVals(ListFlag* list,
		 const string& postfix,
		 const string& section,
		 Condition* cond,
		 bool optional) 
   : MenuExtendedList<double>(list,postfix,section,cond,optional)
    { 
      // specify(); 
    }
  
  
  /**
   * Cor.
   */ 
 MenuDymParsVals(ListFlag* list,
		 const vector<string>& postfix,
		 const string& section,
		 Condition* cond,
		 bool optional) 
   : MenuExtendedList<double>(list,postfix,section,cond,optional)
    { 
      // specify(); 
    }

  /**
   * Cor.
   */ 
 MenuDymParsVals(ListFlag* list,
		 const vector<string>& postfix,
		 const vector<ConfigFlag<double>*>& facflags,
		 const string& section,
		 Condition* cond,
		 bool optional) 
   : MenuExtendedList<double>(list,postfix,facflags,
			      section,cond,optional)
    { 
      // specify(); 
    }


  /**
   * CopyCor 
   */ 
 MenuDymParsVals(const MenuDymParsVals& menu)
   : MenuExtendedList<double>(menu._listflag,menu._postfix,
			      menu._section,
			      menu._condition,
			      menu.isOptional())
    { 
      // specify(); 
    }


  /**
   * DCor 
   */ 
  virtual ~MenuDymParsVals() { } 
  
};

#endif 
