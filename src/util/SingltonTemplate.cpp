/*    
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
 *  /file SingltonTemplate.cpp
 *  /copydoc SingltonTemplate.h
 */ 


#ifndef SINGLTONTEMPLATE_CPP
#define SINGLTONTEMPLATE_CPP
#include "SingltonTemplate.h"
#include <iostream>
#include <cassert>

/// 
template<typename T>
T* SingltonTemplate<T>::_object = (T*)0;

///
template<typename T>
bool SingltonTemplate<T>::_created = false;

///
template<typename T>
SingltonTemplate<T>*
SingltonTemplate<T>:: _singlton = 0;


/**
 *
 */ 
template<typename T>
SingltonTemplate<T>::~SingltonTemplate() { 
  delete _object; 
  _created = false; 
}


/**
 *
 */ 
template<typename T>
void 
SingltonTemplate<T>::create() { 
  cerr << "Overwrite this method \n"; 
  assert(false);
  if(!isCreated()) { 
    _singlton = new SingltonTemplate<T>();
    //_object  = new T();
    _created = true; 
  }
}


/**
 *
 */ 
template<typename T>
void 
SingltonTemplate<T>::finalize() { 
  if(isCreated())  delete _singlton; 
}


/**
 *
 */ 
template<typename T>
T*  SingltonTemplate<T>::getObject() { 
  if(!isCreated()) _singlton->create();
  return _object; 
}


/**
 *
 */ 
template<typename T>
bool 
SingltonTemplate<T>::isCreated() { 
  return _created; 
}


/**
 *
 */ 
template<typename T>
SingltonTemplate<T>*
SingltonTemplate<T>::getSinglton() { 
  return _singlton; 
}


#endif
