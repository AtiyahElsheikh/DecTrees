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
 * \file  MenuExtendedList.h
 * \class MenuExtendedList Menu for extended flags accoarding to the 
 *  the value of a ListFlag.  
 * 
 *
 * 
 * @author      Atiyah Elsheikh 
 * 
 *
 * eg. for a --listflag=x1,x2,x3,... the menu explores the following flags:
 * --x1_{postfix}=<val>
 * --x2_{postfix}=<val> ... 
 */


#ifndef MENUEXTENDEDLIST_H
#define MENUEXTENDEDLIST_H

#include <vector>
#include "Menu.h"
#include "ListFlag.h" 


using namespace std; 


template <typename T> 
class MenuExtendedList:public Menu { 


 private: 


 protected:

  /// postfix extending  all values of the list flag 
  vector<string> _postfix; 

  /// the extended flags 
  vector<ConfigFlag<T>*> _flags;

  /// a list flag --list=v1,v2,.. 
  ListFlag* _listflag; 

  /// 
  vector<ConfigFlag<double>*> _facflags; 

  /**
   * 
   */ 
  virtual vector<T> defaults()=0; 

  /**
   * 
   */ 
  virtual void specify(); 
  

 public: 

  /**
   * Cor.
   */ 
  MenuExtendedList(ListFlag* list,
		   const string& postfix,
		   const string& section,
		   Condition* cond,
		   bool optional) 
    : Menu(section,cond,optional),
    _listflag(list)
    { 
      _postfix.push_back(postfix); 
    }

  /**
   * Cor.
   */ 
  MenuExtendedList(ListFlag* list,
		   const vector<string>& postfix,
		   const string& section,
		   Condition* cond,
		   bool optional) 
    : Menu(section,cond,optional),
    _listflag(list),
    _postfix(postfix)
    { 
      
    }


  /**
   * Cor.
   */ 
  MenuExtendedList(ListFlag* list,
		   const vector<string>& postfix,
		   const vector<ConfigFlag<double>*>& facflags,
		   const string& section,
		   Condition* cond,
		   bool optional) 
    : Menu(section,cond,optional),
    _listflag(list),
    _postfix(postfix),
    _facflags(facflags)
    { 
      assert(facflags.size() == postfix.size());
    }
      

  /**
   * CopyCor 
   */ 
  MenuExtendedList(const MenuExtendedList& menu)
    : Menu(menu._section,menu._condition,menu.isOptional()),
    _listflag(menu._listflag),
    _postfix(menu._postfix) { }

  /**
   * DCor 
   */ 
  virtual ~MenuExtendedList() { 
#ifdef DEBUG
    cout << "MenuExtendedList::~ called\n";
#endif
    for(int i=0;i<_flags.size();i++) {  
      delete _flags[i]; 
    }
  } 
 
  /**
   * Specify the flags of the menues and then explore 
   * @ret succ. of exploration 
   */ 
  virtual bool explore(void* data);

  /**
   * get the listflag
   * @ret
   */ 
  inline ListFlag* getListFlag() { 
    return _listflag; 
  }

  /**
   *
   */ 
  inline vector<string>& getPostfix() { 
    return _postfix;
  }


  /**
   *
   */ 
  void getExtListVals( vector<vector<double> >& ans) const;
 
}; 


#include "MenuExtendedList.cpp"

#endif 


