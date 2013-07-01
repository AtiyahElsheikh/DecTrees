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
 * \file       MenuDymParsVals.cpp
 * \copydoc    MenuParsVals.h
 */ 



#include "StdDymSimSinglton.h"
#include "MenuDymParsVals.h"
using namespace std; 


/**
 *
 */ 
vector<double> 
MenuDymParsVals::defaults() {
  vector<string> list; 
  _listflag->flagValues(list);
  
  vector<double> ret; 
  ret.resize(list.size()); 
  for(int i=0;i<ret.size();i++) 
    ret[i] = StdDymSimSinglton::getPvalue(list[i]);   

  return ret; 
}
