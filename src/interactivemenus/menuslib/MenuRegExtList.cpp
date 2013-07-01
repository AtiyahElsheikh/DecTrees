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
 * \file    MenuRegExtList.cpp
 * \copydoc MenuRegExtList.h 
 *
 */ 


#ifndef MENUREGEXTLIST_CPP
#define MENUREGEXTLIST_CPP

#include <sstream>
#include "MenuRegExtList.h"
#include "myutil.h"
using namespace std; 


/**
 *
 */ 
template<typename T> 
void MenuRegExtList<T>::specify() { 
  MenuExtendedList<T>::specify();
}

/**
 *
 */
template<typename T> 
bool MenuRegExtList<T>::explore(void* data) { 
  bool ret = MenuExtendedList<T>::explore(data);
  
   RegListFlag*            regflag = 
    (RegListFlag*) MenuExtendedList<T>::_listflag; 
  vector<ConfigFlag<T>*>& flags   = MenuExtendedList<T>::_flags; 
  vector<string>&         postfix = MenuExtendedList<T>::_postfix; 
  ListFlag*               expflag = _menu->getListFlag(); 

  /**
   * Algorithm 
   * 1. tokens <- regflag->values
   * 2. reg flags explicitly set 
   *      => overwrite corresponding explicit non-set flags   
   */ 
  
  vector<regex_t> regvars; 
  vector<string>  regvartoks; 
  regflag->flagValues(regvars,regvartoks);
  

  vector<string> expkeys;
  expflag->flagValues(expkeys);

  assert(flags.size() == regvars.size() * postfix.size()); 

  for(int cnt=0;cnt<flags.size();cnt++)
   
      if(flags[cnt]->flagExist()) { 
	ostringstream s;
	s << flags[cnt]->flagValue();

	vector<string> mkeys; // matched keys
	Myutil::match(regvars[cnt/postfix.size()],expkeys,mkeys);
	int k = cnt % postfix.size();

	for(int j=0;j<mkeys.size();j++) { 
	
	  // check whether _menu->flagExist(mkeys[i]+_postfix exist" 
	  if(!_menu->flagExist(mkeys[j]+ postfix[k])) {
	    _menu->flagSetValue(mkeys[j]+postfix[k],s.str());
	  }
	}
	
      }
     
 for(int i=0;i<regvars.size();i++) 
    regfree(&regvars[i]);
  
  return ret; 
} 


/**
 *
 */ 
template<typename T> 
vector<T> MenuRegExtList<T>::defaults() { 
  vector<T> res;
  RegListFlag*            regflag = 
     (RegListFlag*) MenuExtendedList<T>::_listflag;
  vector<string>  toks; 
  regflag->flagValues(toks);
 
  for(int i=0;i<toks.size();i++) 
    res.push_back((T)0); 
  return res;
}




#endif 
