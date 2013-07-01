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
 * \file  MenuConstants.h
 * \class Global menues-related constants used within various classes
 * 
 *
 * @author      Atiyah Elsheikh 
 */


#ifndef MENUCONSTANTS_H
#define MENUCONSTANTS_H

#include <string>
using namespace std; 

class MenuConstants { 


 public : 

  /// Sections 

  /** Configuration Section*/ 
  static const string SECCONF;

  /** Dymola Section */
  static const string SECDYML;

  /** Data Section */ 
  static const string SECDATA;

  /** Variables Section */ 
  static const string SECVARS;

  /** Regular Variables Section */ 
  static const string SECRVAR;

  /** Parameters Section */
  static const string SECPARS;

  /** Regular Parameters Section */
  static const string SECRPAR;

  /** Single Start Section */
  static const string SECSING; 

  /** Multi Start Section */
  static const string SECMULT; 

  /** Monte Carlo Section */
  static const string SECMONT;

  /** Optimization Algorithm Section */
  static const string SECOPTM;

  /** fixed parameter section */ 
  static const string SECFPAR; 

  /** Explicit Start Values section */ 
  static const string SECESV; 

  /** Regular  Start Values section */
  static const string SECRSV;

  /** Start Values boundaries section */ 
  static const string SECESVB; 

  /** Start Values boundaries section */
  static const string SECRSVB;

  /** parameter boundaries */ 
  static const string SECBPAR; 


  //
  // Flag Names 
  // 

  

};




#endif
