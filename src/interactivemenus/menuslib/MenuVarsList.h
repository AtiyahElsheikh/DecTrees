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
 * \file  MenuVarsList.h
 * \class MenuVarsList provides a menu for specifying 3 complementary
 *                     list of vars sorted accoarding to priority 
 *                     1- Inactive Variables 2- Active Variables 3- Rest of Candidates    
 * 
 *
 * @author      Atiyah Elsheikh 
 * 
 */


#ifndef MENUVARSLIST_H
#define MENUVARSLIST_H

//#include <eo>
#include "Menu.h"
#include "MenuConstants.h"
#include "ListFlag.h"
using namespace std;

class MenuVarsList:public Menu { 


 private:

 

 protected:
  

   /// List of inactive variables flags (eg. --invars=v1,v2,v3,...)  
  ListFlag* _inActiveFlag; 

  /// List of active variables flags   
  ListFlag* _activeFlag; 

  /// List of candidates               
  ListFlag* _candFlag; 

  /**
   *
   */ 
  virtual void specify();

 
  /**
   *
   */ 
  virtual bool process(void *data);


 
 public:

  /// macro for all available identity 
  static string DEF_ALL;

  /**
   * 
   * @param Flag of Inactive Identity List (eg. --invars=v1,v2,v3,..)
   * @param Flags of Active Identity List 
   * @param Flags of Candidates (not set within inactive & acitve Flags
   * @param section in which this menu get specified 
   * @param condition to process this node 
   * @param optional whether succissful processing 
   *        for the menu is necessary for overall success
   */ 
  MenuVarsList(ListFlag* inactive,
	       ListFlag* active,
	       ListFlag* cand,
	       const string& section,
	       Condition* cond,
	       bool option) 
  : Menu(section,cond,option),
      _inActiveFlag(inactive),
      _activeFlag(active),
      _candFlag(cand) { 
	specify();
      }
 
  /**
   * @todo implement it by providing Cor ListFlag(string) 
   *
   * @param Flag of Inactive Identity List (eg. --invars=v1,v2,v3,..)
   * @param Flags of Active Identity List 
   * @param Flags of Candidates (not set within inactive & acitve Flags
   * @param section in which this menu get specified 
   * @param condition to process this node 
   * @param optional whether succissful processing 
   *        for the menu is necessary for overall success
   */ 
  /*MenuVarsList(const string& inactive,
	       const string& active,
	       const string& cand,
	       //bool (*foo)(void *data),
	       const string& section,
	       Condition cond=Condition(true),
	       bool optional=true) 
  : Menu(section,cond,optional),
      _inActiveFlag(inactive),
      _activeFlag(active),
      _candFlag(cand) { 
	specify();
	}*/
  
  
  /**
   * Copy Cor 
   */ 
 MenuVarsList(const MenuVarsList& menu)
   : Menu(menu._section,menu._condition,menu.isOptional()),
    _inActiveFlag(menu._inActiveFlag),
    _activeFlag(menu._activeFlag),
    _candFlag(menu._candFlag)
      { 
	specify();
      }  


  /**
   * DCor
   */ 
  virtual ~MenuVarsList() { 
#ifdef DEBUG
    cout << "MenuVarsList::~ called\n";
#endif
  }
  
  /**
   *  getting all available admissible identities
   */ 
  virtual vector<string> allids()=0;


  /**
   * add a set of identities to the set specified by --inActiveFlag
   * 
   * @param set of ids 
   */ 
  template<typename T>
    inline  void addToActiveFlag(const T& varsset) { 
     _activeFlag->addValues(varsset); 
  }
 


  /**
   * add a set of identities to the set specified by --inActiveFlag
   * 
   * @param set of ids 
   */ 
  template<typename T>
   inline  void addToInActiveFlag(const T& varsset) { 
     _inActiveFlag->addValues(varsset); 
  }


  /**
   * Update the set of active / inactive variables accoarding to 
   * the given flag values 
   */ 
  void refresh();
  

  
 
};

#endif
