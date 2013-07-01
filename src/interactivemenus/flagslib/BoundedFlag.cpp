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
 * \file BoundedFlag.cpp
 * \copydoc BoundedFlag.h
 */ 


#ifndef BOUNDEDFLAG_CPP
#define BOUNDEDFLAG_CPP


#include "BoundedFlag.h"
#include <cassert>
#include <cstdlib>


using namespace std; 


/**
 *
 */ 
template<typename T>
bool BoundedFlag<T>::isValid() const{ 

  
  assert(SpecifiedFlag<T>::isProcessed() );
  T val = SpecifiedFlag<T>::flagValue(); 
  bool ret = ((val >= _lower) && (val <= _upper)); 
  if(!ret) { 
    cout << _lower << " <= --" << SpecifiedFlag<T>::flagKey() << "=" 
	 << SpecifiedFlag<T>::flagValue() 
	 << " <= " << _upper << " : not valid \n";  
       return false;	        
  }
  return ret; 
}


#endif
