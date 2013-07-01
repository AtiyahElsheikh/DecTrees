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
 * 
 * \file    MenuExtendedList.cpp
 * \copydoc MenuExtendedList.h 
 *
 */ 


#ifndef MENUEXTENDEDLIST_CPP
#define MENUEXTENDEDLIST_CPP

#include "MenuExtendedList.h"
using namespace std; 


/**
 *
 */ 
template<typename T> 
void MenuExtendedList<T>::specify() { 
  
  // get the value of listFlag?
  assert(_listflag->isProcessed());

  vector<string> list; 
  _listflag->flagValues(list); 

  //
  // create sequence of flags consider them as childern?  
  // for(int i=0;i<list.size();i++) {
  //  list[i] = list[i] + _postfix; 
  //
  
  vector<T> vals = this->defaults(); 

  _flags.resize(list.size()*_postfix.size());
 
  int cnt = 0;
  for(int i=0;i<list.size();i++) 
    for(int j=0;j<_postfix.size();j++)  { 
      double t = _facflags.empty()? 
	vals[i]:vals[i]*_facflags[j]->flagValue();
      _flags[cnt++] = new ConfigFlag<T>(eoValueParam<T>(
				      t,
				      list[i] + _postfix[j],
				      "",
				      0,
				      false),
				    NULL); // no condition for processing			 
    }
  for(int i=0;i<_flags.size();i++) 
    addFlag(_flags[i]);

}

/**
 *
 */ 
template<typename T> 
bool MenuExtendedList<T>::explore(void* data)
{ 
  if(!isExplored()) { 
    specify();
  }
  return Menu::explore(data);
}

/**
 *
 */
template<typename T>
void MenuExtendedList<T>::
getExtListVals(vector< vector<double> >& ans) const { 

  ans.clear();
  ans.resize(_postfix.size()); 

  int cnt = 0;
  int s   = _postfix.size();
  while(cnt < _flags.size()) { 
    ans[cnt%s].push_back(_flags[cnt]->flagValue());
    cnt++;
  }

}

#endif
