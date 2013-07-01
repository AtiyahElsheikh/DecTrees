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
 * \file  MenuDymExpVars.h
 * \class MenuDymExpVars provides basic configuration flags for 
 *        simulating a Dymola program.  
 * 
 *
 * @author      Atiyah Elsheikh 
 */


#ifndef MENUDYMEXPPARS_H
#define MENUDYMEXPPARS_H

#include <eo>
#include "MenuVarsList.h"


class MenuDymExpPars:public MenuVarsList { 


 private:

 

  
 protected:
  
 
  /**
   *  getting all available admissible identities
   */
  virtual vector<string> allids(); 



 public:


   /**
    * Cor. 
    * @overwrite
    * @param  
    * @param 
    * @param 
    * @param condition to process this node 
    * @param optional whether succissful processing 
    *        for the menu is necessary for overall success
    */ 
  MenuDymExpPars(ListFlag* invars,
		 ListFlag* vars,
		 ListFlag* cands,
		 const string& section,
		 Condition* cond,
		 bool optional);
 

  /**
   * Copy Cor 
   */ 
  MenuDymExpPars(const MenuDymExpPars& menu);


  /**
   * DCor
   */ 
  virtual ~MenuDymExpPars() { 
#ifdef DEBUG
    cout << "MenuDymExpVars::~ called\n";
#endif
  } 

  

}; 

#endif
