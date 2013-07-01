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
 *  \file    CommonFlags.cpp
 *  \copydoc CommonFlags.h 
 */


#ifndef COMMONFLAGS_CPP
#define COMMONFLAGS_CPP
#include <cstdlib>
#include "CommonFlags.h"
#include "ListFlag.h"
#include "RegListFlag.h"
#include "DiscreteFlag.h"
#include "CondFlgVal.h"

using namespace std; 


vector<Condition*> FlagFuns::_conditions(0);

/// candiate values of mode flag 
string   
FlagFuns::CAND_MODE[]={"SingleStart",
		      "MultiStart",
		      "MonteCarlo"}; 


/// Default Optimization Software
string  
FlagFuns::DEF_MODE    = CAND_MODE[0];


/**
 *
 */ 
FlagInterface*
FlagFuns::FLG_PCAND() { 
  return new ListFlag(eoValueParam<string>(
			"all",
			"pcand",
			"Parameters Candidates",
			0,
			false),
		      NULL); 
}


/**
 *
 */
FlagInterface*
FlagFuns::FLG_SIMDIR() { 
  FlagInterface* ret =
    new ConfigFlag<string>(
	  eoValueParam<string>(
	    "/path/to/model",     // default value     
	    string("simdir"),     // flag name --longname
	    "Path to Modelica Model, default: current directory",
	    0,                    // short name flag -c : ignore make it always 0 
	    false),               // whether flag is required 
	  NULL);
 
  ret->setProccessFunc(&setDefaultSimDir);
  return ret; 
}


/**
 *
 */
FlagInterface*
FlagFuns::FLG_MODE() { 
  FlagInterface* ret =
    new DiscreteFlag<string,string*>(
	   eoValueParam<string>(
	     DEF_MODE,
	     "mode",
	     "optimization mode: SingleStart / MultiStart / MonteCarlo",
	     0,
	     true),
	   NULL,
	   CAND_MODE,
	   CAND_MODE+sizeof CAND_MODE/sizeof(string));

  return ret; 
}


/**
 *
 */ 
bool FlagFuns::setDefaultSimDir(void* data) { 
  
  FlagInterface* simdir = FlgSimDir::getObject(); 
  
  if(!simdir->flagExist()) { 
    
    // Get Current Diurectory 
    char cCurrentpath[FILENAME_MAX];
    if (!getcwd(cCurrentpath, sizeof(cCurrentpath))) {
      cerr << "current directory not obtainable\n" ;
      exit(0);
    }
    string currdir(cCurrentpath);
    simdir->setValue(currdir);
  }

  return true;
}


/**
 *
 */ 
FlagInterface*
FlagFuns::FLG_RPAR() { 
  return new RegListFlag(eoValueParam<string>(
		           "",
			   "regpars",
			   "list of regular expressions for parameters",
			   0,
			   false),               
			 NULL);
}


/**
 *
 */ 
FlagInterface*
FlagFuns::FLG_APAR() { 
  return new ListFlag(eoValueParam<string>(
		        "",
			"pars",
			"active parameters",
			0,
			true),               
		      NULL); 
}


/**
 *
 */ 
FlagInterface*
FlagFuns::FLG_SVUPBD() { 
  return new ConfigFlag<double>(eoValueParam<double>(
			          1.5,
				  "svuppb",
				  "upper range for start values > 1",
				  0,
				  false),
				(Condition *) 0);
}


/**
 *
 */ 
FlagInterface*
FlagFuns::FLG_SVLOBD() { 
  return new ConfigFlag<double>(eoValueParam<double>(
			    0.5,
			    "svlowb",
			    "lower range for start values < 1",
			    0,
			    false),
			  (Condition *) 0);
}


/**
 *
 */ 
FlagInterface*
FlagFuns::FLG_ANADER() { 
  return new ConfigFlag<int>(
	     eoValueParam<int>(
	      0,
	      "analyticder",
	      "whether analytic derivatives should be used [0/1]",
	      0,
	      false),
	     (Condition *) 0);
}


/**
 *
 */ 
FlagInterface*
FlagFuns::FLG_FDSTEP() {

  Condition* cond = new CondFlgVal(FlgAnaDer::getObject(),"0");
  _conditions.push_back(cond);
  
  return new ConfigFlag<double>(
	      eoValueParam<double>(
		1e-5,
		"fdstepsize",
		"step size of finitie difference",
		0,
		false),
	      cond);
}


/**
 *
 */
void
FlagFuns::finalize() { 
  FlgFDStep::finalize();
  FlgAnaDer::finalize();
  FlgSimDir::finalize();
  FlgMode::finalize();
  FlgParCand::finalize();
  FlgRegPars::finalize();
  FlgActPars::finalize();
  FlgSvUppBd::finalize();
  FlgSvLowBd::finalize();
  // for(int i=0;i<_conditions.size();i++) 
  // delete _conditions[i];
  //_conditions.clear();
} 


#endif
