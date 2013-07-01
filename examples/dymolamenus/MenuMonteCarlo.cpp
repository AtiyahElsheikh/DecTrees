/**
 * \file  MenuMonteCarlo.cpp 
 * \class MenuMonteCarlo
 */ 


#ifndef MENUMONTECARLO_CPP
#define MENUMONTECARLO_CPP

#include "MenuMonteCarlo.h"

int MenuMonteCarlo::DEF_NMONTS = 4; 

/**
 *
 */ 
void MenuMonteCarlo::specify() { 


  ///
  _FLG_MCSEED = 
    new ConfigFlag<int>(eoValueParam<int>(
			  0,
			  "mcseed",
			  "seed for montecarlo data samples, 0: totally random",
			  0,
			  false),
			(Condition *) 0);

  ///
  _FLG_NMONTS = 
    new ConfigFlag<int>(eoValueParam<int>(
			  DEF_NMONTS,
			  "nmonts",
			  "# of Monte Carlo data samples",
			  0,
			  true),
			(Condition *) 0);


 /// 
 _FLG_MCSTDDIV = 
   new ConfigFlag<double>(eoValueParam<double>(
			    0,
			    "mcstddiv",
			    "standard div. of errors in data samples",
			    0,
			    false),
			 (Condition *) 0);


  addFlag(_FLG_NMONTS);
  addFlag(_FLG_MCSEED);
  addFlag(_FLG_MCSTDDIV);

}

#endif 
