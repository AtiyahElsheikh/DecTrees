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

/*
 * \file MenuExtListFactory.cpp
 * \copydoc MenuExtListFactory.h 
 */


#include "MenuExtListFactory.h" 
#include "CommonFlags.h"
#include "MenuDymParsVals.h"
#include "MenuConstants.h"
#include "CondFlgVal.h"
#include "CondOr.h"


vector<Condition*> MenuExtListFactory::CONDITIONS; 


/**
 *
 */
void
MenuExtListFactory::finalize() { 
  if(!CONDITIONS.empty()) { 
    for(int i=0;i<CONDITIONS.size();i++)
      delete CONDITIONS[i];
    CONDITIONS.clear();
  }
}


/**
 *
 */ 
MenuExtendedList<double>* 
MenuExtListFactory::MenuFixedPars() { 
  ListFlag* listflag = (ListFlag*) FlgParCand::getObject();  
  assert(listflag != 0);
  Menu* basemenu = SingMenuDymRegPars::getMenu(); 
  assert(basemenu != 0);
    
  // in case the list is empty, menu would not produce any flag to process
  MenuExtendedList<double>* ret 
    = new MenuDymParsVals(listflag,
			  "",
			  MenuConstants::SECFPAR,
			  NULL, 
			  false);

  basemenu->insertChild(ret);
  return ret;
}



/**
 *
 */ 
MenuExtendedList<double>* 
MenuExtListFactory::MenuStartVals() { 
  ListFlag* listflag = (ListFlag*) FlgActPars::getObject();  
  assert(listflag != 0);

  Menu* basemenu = SingMenuDymRegPars::getMenu(); 
  assert(basemenu != 0);

  Condition* cond = new CondFlgVal(FlgMode::getObject(),
				   FlagFuns::CAND_MODE[0]);
  CONDITIONS.push_back(cond);

  MenuExtendedList<double>* ret 
    = new MenuDymParsVals(listflag,
			  "_0",
			  MenuConstants::SECESV,
			  cond, // NULL,
			  false);

  basemenu->insertChild(ret);
  return ret; 
}


/**
 *
 */ 
MenuExtendedList<double>* 
MenuExtListFactory::MenuStValsBound() { 
  ListFlag* listflag = (ListFlag*) FlgActPars::getObject();  
  assert(listflag != 0);

  Menu* basemenu = SingMenuDymRegPars::getMenu(); 
  assert(basemenu != 0);

  vector<string> postfix; 
  postfix.push_back(std::string("_min_0")); 
  postfix.push_back(std::string("_max_0"));

  Condition* cond1 = new CondFlgVal(FlgMode::getObject(),
				    FlagFuns::CAND_MODE[1]);
  CONDITIONS.push_back(cond1);

  Condition* cond2 = new CondFlgVal(FlgMode::getObject(),
				   FlagFuns::CAND_MODE[2]);
  CONDITIONS.push_back(cond2);

  Condition* cond3 = new CondOr(cond1,cond2); 
  CONDITIONS.push_back(cond3);

  vector<ConfigFlag<double>*> factors; 
  factors.push_back((ConfigFlag<double>*)FlgSvLowBd::getObject()); 
  factors.push_back((ConfigFlag<double>*)FlgSvUppBd::getObject()); 

  MenuExtendedList<double>* ret 
    = new MenuDymParsVals(listflag,
			  postfix,
			  factors,
			  MenuConstants::SECESVB,
			  cond3,
			  false);

  basemenu->insertChild(ret);
  return ret; 
}




