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
 * \file  DecisionNode.h
 * \class DecisionNode implements a decision tree for routines  
 * 
 * A client uses a DecisionNode object by 
 * 1. constructing it
 * 2. exploring and processing by the explore() which process the whole 
 *    tree using the protected method process() 
 * 
 * @author      Atiyah Elsheikh 
 * 
 */


#ifndef DECISIONNODE_H
#define DECISIONNODE_H 

#include <cassert>
#include <iostream>
#include <vector>
#include "Condition.h"
using namespace std;

class DecisionNode; 

class DecisionNode { 

 private:

  /// Whether successiful processing is necessary for ovelall success 
  bool _optional; 

  /// whether this node has been explored before 
  bool _explored; 

  /// The result of the first exploration of this node 
  bool _exploreRet; 

  /// an alternative processing function which will be called by process() 
  bool (*_processfun)(void*);

 protected:
  
  /// condition to process this node 
  Condition* _condition; 

  /// childern node, only evaluated if _condition is true 
  vector<DecisionNode*> _child; 

  /**
   * Process the node in case Condition is true called by explore()
   */ 
  virtual bool process(void* data)=0;
  

 public:

 

  /**
   * @param condition to process the node / 0 if no condition
   * @param optional whether successiful processing is optional for overall success
   */ 
 DecisionNode(Condition* condition=NULL,
	      bool optional=false)
   : _condition(condition),
    _optional(optional)
    { 
      _explored = false; 
      _processfun = 0;
    }


  /**
   * Copy Constructor 
   */
  DecisionNode(const DecisionNode& node)
    : _condition(node._condition),
    _optional(node._optional),
    _explored(node._explored),
    _exploreRet(node._exploreRet),
    _processfun(node._processfun),
    _child(node._child)
    { 
     
    }


  /**
   * Destructor 
   */ 
  virtual ~DecisionNode(); 

  
  /**
   * if condition is satisfied process the current node 
   * and childern recursively  
   */ 
  virtual bool explore(void* data); 

  /**
   * decide whether the current node will be processed 
   */ 
  inline bool decide() const { 
    if(_condition == 0) return true;
    return _condition->evaluate(); 
  }

  /**
   * insert a child node to the current node
   * @param a child node 
   */ 
  void insertChild(DecisionNode* node); 

  /**
   * Whether successiful processing/exploration of this node is necessary 
   * for ovelall success
   */
  inline bool isOptional() const { 
    return _optional;
  }
  
  /**
   *
   */
  inline bool isExplored() const { 
    return _explored; 
  }

  /**
   *
   */ 
  inline vector<DecisionNode*> getChildern() { 
    return _child;
  }

  /**
   * Set extra or alternative processing function (only once) 
   */ 
  void setProccessFunc( bool (*processfun)(void*));

  /**
   *
   */ 
  inline bool isProcessFuncNull() { 
    return (_processfun == NULL); 
  }

  /**
   *
   */ 
  inline bool applyProcessFunc(void* data) { 
    assert(!isProcessFuncNull());
    return _processfun(data);
  }

  /**
   *
   */
  inline int numOfChild() { 
    return _child.size();
  }

  /**
   *
   */ 
  inline Condition* getCondition() { 
    return _condition; 
  }

}; 

#endif
