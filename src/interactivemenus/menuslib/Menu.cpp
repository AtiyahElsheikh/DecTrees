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
 * \file Menu.cpp
 * \copydoc Menu.h 
 */ 


#include "ParserSinglton.h"
#include "Menu.h"
#include <iostream>
#include <cstdlib>
using namespace std;


/**
 *
 */ 
Menu::Menu(const string& section,
	   Condition* cond,
	   bool optional)
  : DecisionNode(cond,optional),
    _section(section) { }


/**
 *
 */ 
Menu::Menu(const Menu& menu)
  : DecisionNode(menu._condition,menu.isOptional()),
    _section(menu._section)
{
  assert(false); // not really needed 
}

/**
 *
 */ 
Menu::~Menu() {

#ifdef DEBUG
  cout << "Menu::~ called\n";
#endif 

}


/**
 *
 */ 
bool Menu::process(void* data) { 

#ifdef DEBUG
  cout << "Menu::process() called\n"; 
#endif 

  bool ret = true; 
  

  for(int i=0;i<_flags.size();i++) { 
    
    bool temp = _flags[i]->explore(&_section);     

#ifdef DEBUG    
    cout << "exploring " << _flags[i]->flagKey() 
         << "  " << temp << " " << _flags[i]->isOptional() << "\n"; 
#endif

    ret = ret && temp ;

  }

  //cout << "Exploring Menu " << ret << "\n"; 

  return ret; 
}


/**
 *
 */ 
void Menu::addFlag(FlagInterface* flag) { 
  
  //flag->setSection(_section);
  flag->setProccessFunc(&flagProcessor); // All childern will be set as well
  _flags.push_back(flag);
  addFlag2Map(flag);

}


/**
 *
 */
void Menu::addFlag2Map(FlagInterface* flag) { 

  pair<map<string,FlagInterface*>::iterator,bool> temp = 
    _flagsmap.insert(make_pair(flag->flagKey(),flag));  
  
  if(temp.second == false) { // insertion did not take place because flagKey() allready exist
    if(temp.first->second != flag) { // Different ConfigFlag were used for the same key
      cerr << flag->flagKey() << 
	"already exist!\nTip: Use the same ConfigFlag object in both menus\n";
      assert(temp.first->second == flag);
    }
  }

  vector<DecisionNode *> child = flag->getChildern(); 
  for(int i=0;i<child.size();i++) { 
    FlagInterface* temp = (FlagInterface *) child[i]; 
    addFlag2Map(temp);
  }
}


/**
 *
 */ 
void Menu::addMenu(const Menu& menu) { 

  for(int i=0;i<menu._flags.size();i++) 
    addFlag(_flags[i]);

  //
  // check intersection consistency => corresponding ConfigFlag identical 
  //

  // Make union
  map<string,FlagInterface*>::const_iterator it;
  it = menu._flagsmap.begin();
  while(it != menu._flagsmap.end()) { 
    _flagsmap.insert(make_pair(it->first,it->second));
    it++;
  }
}


/**
 *  
 */ 
void* Menu::flagValue(const string& key) { 
  
  map<string,FlagInterface*>::iterator it;
  /*it  = _flagsmap.begin(); 
  while(it != _flagsmap.end()) { 
    cout << it->first << "\n";
    it++;
    }*/
 
  it = _flagsmap.find(key); 
  if(it == _flagsmap.end()) { 
    cerr << "flag : " << key << " not specified in the menu \n"; 
    exit(0);
    return NULL;
  } else { 
    return it->second->value();
  } 

}


/**
 * 
 */ 
bool Menu::flagExist(const string& key) { 
  
  map<string,FlagInterface*>::iterator it; 
  /*cout << "searching: " << key <<"\n";
  it  = _flagsmap.begin(); 
  while(it != _flagsmap.end()) { 
    cout << it->first << "\n";
    it++;
    }*/

  it = _flagsmap.find(key); 
  if(it == _flagsmap.end()) { 
    cerr << "flag : " << key << " not specified in the menu \n"; 
    exit(0);
    return false;
  } else { 
    return it->second->flagExist();
  } 

}

/**
 *  
 */ 
void Menu::flagSetValue(const string& key,const string& val) { 
  

  map<string,FlagInterface*>::iterator it; 
  it = _flagsmap.find(key); 
  if(it == _flagsmap.end()) { 
    cerr << "flag : " << key << " not specified in the menu \n";
    exit(0);
  } else { 
    it->second->setValue(val);
  } 

}


/**
 *
 */ 
bool Menu::flagProcessor(void *data) {   
  /*eoParam* flag   = ((FlagInterface*) data)->getEOParam();
  const string& section = ((FlagInterface*) data)->getSection();
  ParserSinglton::processParam(flag,section);//_section);*/

#ifdef DEBUG
  cout << "Menu::flagProcessor() called \n";
#endif

}


