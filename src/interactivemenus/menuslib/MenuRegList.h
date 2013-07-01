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
 * \file  MenuRegList.h
 * \class MenuRegList provides a menu for specifying 2 lists of variables 
 *                    expressed as regular variables. The 2 lists are 
 *                    1- Inactive Variables with higher priority  
 *                    2- Active Variables   
 * 
 *
 * the regular list of inactive/active variables influence a corresponding 
 * list of explict active/inactive variables 
 * 
 * @author      Atiyah Elsheikh 
 * 
 */


#ifndef MENUREGLIST_H
#define MENUREGLIST_H

//#include <eo>
#include "Menu.h"
#include "RegListFlag.h"
#include "MenuVarsList.h"

using namespace std;

class MenuRegList:public Menu{ 


 private:

  /// List of inactive variables flags (eg. --invars=v1,v2,v3,...)  
  RegListFlag* _inActiveRegFlag; 

  /// List of active variables flags   
  RegListFlag* _activeRegFlag; 

  /// A pointer to an explicit variable menu of type MenuVarsList 
  MenuVarsList* _expVarsMenu; 

 protected:
  
  /**
   *
   */ 
  virtual void specify();

  /**
   *
   */ 
  virtual bool process(void *data);

 public:


  /**
   * 
   * @param Flag of Inactive Identity List (--inregvars=regex1,regexp2,..)
   * @param Flags of Active Identity List 
   * @param A pointer to associated explict list
   * @param section in which this menu get specified 
   * @param condition to process this node 
   * @param optional whether succissful processing 
   *        for the menu is optional for overall success
   */ 
 MenuRegList(RegListFlag* inactive,
	     RegListFlag* active,
	     MenuVarsList* menu,
	     const string& section,
	     Condition* cond,
	     bool option) 
   : Menu(section,cond,option),
    _inActiveRegFlag(inactive),
    _activeRegFlag(active),
    _expVarsMenu(menu)
    { 
      specify();
    }
 
   
  /**
   * Copy Cor 
   */ 
  MenuRegList(const MenuRegList& menu)
    : Menu(menu._section,menu._condition,menu.isOptional()),
    _inActiveRegFlag(menu._inActiveRegFlag),
    _activeRegFlag(menu._activeRegFlag),
    _expVarsMenu(menu._expVarsMenu)
      { 
	specify();
      }  


  /**
   * DCor
   */ 
  virtual ~MenuRegList() { 
#ifdef DEBUG
    cout << "MenuRegList::~ called\n";
#endif
  }
 

  /**
   * @overwrite explore() of DecisionNode
   */ 
  virtual bool explore(void* data); 
};

#endif
