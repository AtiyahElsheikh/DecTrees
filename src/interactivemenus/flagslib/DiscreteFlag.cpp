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
 * \file DiscreteFlag.cpp
 * \copydoc DiscreteFlag.h
 */ 


#ifndef DISCRETEFLAG_CPP
#define DISCRETEFLAG_CPP


#include "DiscreteFlag.h"
#include <cassert>
#include <cstdlib>
#include <iterator>

using namespace std; 


/**
 *
 */ 
template<typename T, 
	 typename myiterator>
bool DiscreteFlag<T,myiterator>::isValid() const { 

  
  assert(SpecifiedFlag<T>::isProcessed() );
  typename set<T>::iterator it = 
    _candidate.find(SpecifiedFlag<T>::flagValue()); 
  return it != _candidate.end();
}


#endif
