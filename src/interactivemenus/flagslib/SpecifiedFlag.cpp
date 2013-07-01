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
 * \file SpecifiedFlag.cpp
 * \copydoc SpecifiedFlag.h
 */ 


#ifndef SPECIFIEDFLAG_CPP
#define SPECIFIEDFLAG_CPP


#include "SpecifiedFlag.h"
using namespace std; 


template<typename T>
bool SpecifiedFlag<T>::process(void *data) { 
     
     bool ret = ConfigFlag<T>::process(data); 


     if(!isValid()) { 
       cout << "Value of --" << SpecifiedFlag<T>::flagKey() << "=" 
	    << SpecifiedFlag<T>::flagValue() << " not admissible\n"; 
       return false;	        
     }    

  
     return ret; 
}


#endif 
