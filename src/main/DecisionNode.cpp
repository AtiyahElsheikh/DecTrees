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
 *  \file    DecisionNode.cpp
 *  \copydoc DecisionNode.h 
 *
 */

#include "DecisionNode.h"
#include <cassert>
#include <iostream>

/**
 *
 */ 
DecisionNode::~DecisionNode() { 

#ifdef DEBUG
  cout << "DecisionNode::~ called\n";
#endif 

  

#ifdef DEBUG
  cout << "DecisionNode::~ succ. called\n";
#endif 
} 


/**
 * 
 */ 
bool DecisionNode::explore(void* data) { 

#ifdef DEBUG
  cout << "DecisionNode::explore()" << _explored << "\n"; 
#endif 

  if(isExplored()) { 
    bool child = true;
    if(decide()) { 
      for(int i=0;i<_child.size();i++) {
	bool temp = _child[i]->explore(data); 
	child = child && temp; //_child[i]->isOptional() ? child || temp : child && temp;  
      }  
    }
    return _exploreRet && child; 
  } else { 
    _explored = true; 
  }

  bool optional = isOptional();  
  bool ret = true; 

  if(decide()) {
    bool thisNode = process(data); 
    thisNode = thisNode || optional; 

    //cout << "this node " << thisNode << "\n"; 

    bool child = true; 
    for(int i=0;i<_child.size();i++) {
      bool temp = _child[i]->explore(data); 
      child = child && temp; //_child[i]->isOptional() ? child || temp : child && temp;  
    }  
    
    // cout << "childs " << child << "\n"; 
    ret = thisNode && child; 
  }

  _exploreRet = ret; 
  return ret; 

}


/**
 *
 */
void DecisionNode::insertChild(DecisionNode* node) { 
  assert(node != NULL); 
  _child.push_back(node); 
}


/**
 *
 */ 
void DecisionNode::setProccessFunc( bool (*processfun)(void*)) { 
  if(isProcessFuncNull()) { 
    _processfun = processfun;
    for(int i=0;i<_child.size();i++)
      _child[i]->setProccessFunc(processfun);
  }
}
