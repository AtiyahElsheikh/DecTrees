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

#ifndef MYCONSTANTS_H
#define MYCONSTANTS_H

#include<string> 
using namespace std;


/**
 * A struct for global constants
 *
 * 
 */
struct myconstants {
  /**
   * Arguments describing simulation options in dsin.txt 
   */
  static const int NUM_SIM_KEYS=7; 
  
  /**
   * Simulation parameters and thier default values.
   */ 
  static pair<string,double> KEYS_DEF_VAL[NUM_SIM_KEYS];
  static const string OCTAVE_TEMP_DIR;
  static const string OCTAVE_PAR_FILE; 
  static const string OCTAVE_PARNAMES_FILE;
  static const string OCTAVE_X0_FILE;
  static const string OCTAVE_X0NAMES_FILE;
  static const string LOAD_DSIN_SHELL;
  static const string UPDATE_DSIN_SHELL;
  static const string DYMOSIM;
  static const string DSRES_FILE;
  static const string DSINP_FILE;
  static const string DSINP_DIR;
  static const string DSRES_DIR;
  static const int MAX_BUFF_LEN; 

};

#endif 
