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
 * \file  MenuRegExtList.h
 * \class MenuRegExtList Menu for extended flags accoarding to the 
 *  the value of a ListFlag.  
 * 
 *
 * 
 * @author      Atiyah Elsheikh 
 * 
 * eg. for a --listflag=x1,x2,x3,... the menu explores the following flags:
 * --x1_{postfix}=<val>
 * --x2_{postfix}=<val> ... 
 */


#ifndef MENUREGEXTLIST_H
#define MENUREGEXTLIST_H


#include "MenuExtendedList.h"
#include "RegListFlag.h" 


using namespace std; 


template <typename T> 
class MenuRegExtList:public MenuExtendedList<T> { 


 private: 

  /// a menu for extended list 
  MenuExtendedList<T>* _menu; 


 protected:

  /**
   * 
   */ 
  virtual void specify(); 

  

  /**
   *
   */ 
  virtual vector<T> defaults();
  
 public: 

  /**
   * Cor.
   */ 
 MenuRegExtList(MenuExtendedList<T>* menu,
		RegListFlag* list,
		const string& section,
		Condition* cond,
		bool optional) 
   : MenuExtendedList<T>(list,menu->getPostfix(),section,cond,optional),
    _menu(menu) { 
      _menu->insertChild(this);
    }
  
  /**
   * CopyCor 
   */ 
  MenuRegExtList(const MenuRegExtList& menu)
    : MenuExtendedList<T>(menu._listflag,
			  menu._postfix,
			  menu._section,
			  menu._condition,
			  menu.isOptional()),
    _menu(menu._menu) {
    _menu->insertChild(this);
  }
  

  /**
   * DCor 
   */ 
  virtual ~MenuRegExtList() { 
#ifdef DEBUG
    cout << "MenuRegExtList::~ called\n";
#endif
  } 


  /**
   *
   */ 
  virtual bool explore(void* data);

}; 


#include "MenuRegExtList.cpp"

#endif 


