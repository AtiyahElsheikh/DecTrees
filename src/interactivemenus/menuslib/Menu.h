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
 * \file Menu.h
 * \class Menu provides a menu of dependent flags and submenues  
 * 
 * @warning: by constructing a hierarchies of menus, grandmenus 
 * should be inserted as childs to thier father, and then 
 * and then childs should be inserted into thier parants .i.e. 
 * from bottom to top.
 *
 * @author      Atiyah Elsheikh 
 */


#ifndef MENU_H
#define MENU_H

#include "FlagInterface.h"
#include <map>
#include <string>
//#include <eo>


using namespace std; 
class Menu: public DecisionNode { 

 private:

  /// Root flags of the Menu 
  vector<FlagInterface*> _flags; 

  /// a map from flag keys (--flagkey) to corresponding FlagInterface 
  map<string,FlagInterface*>  _flagsmap; 


  /**
   * add the flag to _flagsmap
   */ 
  void addFlag2Map(FlagInterface* flag); 


 protected:


  /// section in which menu is specified 
  string _section; 

  
  /// a standard flag processor 
  static bool flagProcessor(void* data);


  /**
   * Assential Code for processing a menu
   */ 
  virtual bool process(void *data); 

  
  /**
   * specify a menu / called by a constructor 
   */ 
  virtual void specify()=0;


  

 public:


  

  /**
   * 
   * @param output file
   * @param condition to process this node 
   * @param optional whether succissful processing 
   *        for the menu is optional for overall success
   */ 
  Menu(const string& section, 
       Condition* cond,
       bool optional); 

  /**
   * Copy Cor 
   */ 
  Menu(const Menu& menu); 

  /**
   * DCor
   */ 
  virtual ~Menu(); 

  /**
   * add the flags of a menu into this menu
   */ 
  void addMenu(const Menu& menu);

 

  /**
   * add a flag into the menu
   */ 
  void addFlag(FlagInterface* flag); 

  
  /**
   * the value of a flag 
   * @warning: a grandkid menu inserted into a child menu would
   *           not be scanned, unless the child menu is 
   *           inserted as a child after the grandkid menu 
   *           was inserted as a child.  
   * @param the key of the flag --key
   */
  void* flagValue(const string& key); 

  /**
   * whether flag --key exist and set by the user  
   * @warning: a grandkid menu inserted into a child menu would
   *           not be scanned, unless the child menu is 
   *           inserted as a child after the grandkid menu 
   *           was inserted as a child.  
   * @param the key of the flag 
   */
  bool flagExist(const string& key);

  /**
   * whether flag   
   * @param the key of the flag 
   * @param the value 
   */
  void flagSetValue(const string& key,const string& val);


  /**
   *
   */
  inline void printFlags() { 
    map<string,FlagInterface*>::iterator it;
    it  = _flagsmap.begin(); 
    while(it != _flagsmap.end()) { 
      cout << it->first << " ,";
      it++;
    }
    cout << "\n";
  }


  /**
   * insert a menu as a child 
   * @warning: for complete functionalities, grandkids 
   *  should be inserted into child menus first.
   * @param pointer to another menu
   */ 
  inline void insertChild(Menu* node) { 
    DecisionNode::insertChild((DecisionNode*)node);
    map<string,FlagInterface*>::const_iterator it;
    it = node->_flagsmap.begin();
    while(it != node->_flagsmap.end()) { 
      _flagsmap.insert(make_pair(it->first,it->second));
      it++;
    }
  }
  
};


#endif  


