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
 *  \file    SingltonFlag.cpp
 *  \copydoc SingltonFlag.h 
 */


#ifndef SINGLTONFLAG_CPP
#define SINGLTONFLAG_CPP

#include "SingltonFlag.h"
using namespace std;

/// 
template<FlagInterface* flagfun()>
FlagInterface* SingltonFlag<flagfun>::_object = (FlagInterface*)0;

///
template<FlagInterface* flagfun()>
bool SingltonFlag<flagfun>::_created = false;

///
template<FlagInterface* flagfun()>
SingltonFlag<flagfun>*
SingltonFlag<flagfun>::_singlton = 0;


/**
 *
 */
template<FlagInterface* flagfun()> 
void 
SingltonFlag<flagfun>::create() {
  if(!isCreated()) { 
    _singlton = new SingltonFlag<flagfun>();
    _object = flagfun();
    _created = true;  
  }
}


/**
 *
 */ 
template<FlagInterface* flagfun()>
void 
SingltonFlag<flagfun>::finalize() { 
  if(isCreated()) delete _singlton; 
}

/**
 *
 */ 
template<FlagInterface* flagfun()>
bool 
SingltonFlag<flagfun>::isCreated() { 
  return _created; 
}


/**
 *
 */ 
template<FlagInterface* flagfun()>
SingltonFlag<flagfun>*
SingltonFlag<flagfun>::getSinglton() { 
  return _singlton; 
}

/**
 *
 */ 
template<FlagInterface* flagfun()> 
FlagInterface* 
SingltonFlag<flagfun>::getObject()  { 
  if(!isCreated()) create();
  return _object;
}


#endif 

 
