/**
 * \file  MenuLevMar.cpp 
 * \class MenuLevMar
 */ 


#ifndef MENULEVMAR_CPP
#define MENULEVMAR_CPP

#include "MenuLevMar.h"

///
string MenuLevMar::CAND_PSCALING[] = 
  {"none","log","plog","unity","dynunity"}; 


/**
 *
 */ 
void MenuLevMar::specify() { 

  /// 
  _FLG_PSCALING 
    = new DiscreteFlag<string,string*>(
       eoValueParam<string>(
	 CAND_PSCALING[0],
	 "pscaling",
	 "parameter scaling type : [none,log,plog,unity,dynunity]",
	 0,
	 false),
       (Condition *) 0,
       CAND_PSCALING,
       CAND_PSCALING+sizeof CAND_PSCALING/sizeof(string));  


  _FLG_MAXITER 
    = new ConfigFlag<int>(eoValueParam<int>(
			    50,
			    "maxiter",
			    "maximum number of iterations",
			    0,
			    false),
			  (Condition *) 0);

  _FLG_LAMBDA 
    = new ConfigFlag<double>(eoValueParam<double>(
			       10.0,
			       "lambda",
			       "start lambda for Levenberg-Marquardt",
			       0,
			       false),
			  (Condition *) 0);
			  
  _FLG_STOP_JE
    = new ConfigFlag<double>(eoValueParam<double>(
			       1e-20,
			       "stop_Je",
			       "stop criteria ||J^T e||_{inf} < ?",
			       0,
			       false),
			  (Condition *) 0);

  _FLG_STOP_DP = 	    
    new ConfigFlag<double>(eoValueParam<double>(
                             1e-20,
			     "stop_Dp",
			     "stop criteria change in the scaled opt. variables ||Dp|| < ",
			     0,
			     false),
			  (Condition *) 0);

  _FLG_STOP_E = 
    new ConfigFlag<double>(eoValueParam<double>(
			     0.0,
			     "stop_e",
			     "stop criteria value of the goal function ||e|| < ",
			     0,
			     false),
			  (Condition *) 0);


  addFlag(_FLG_MAXITER);
  addFlag(_FLG_LAMBDA);
  addFlag(_FLG_PSCALING);
  addFlag(_FLG_STOP_JE);
  addFlag(_FLG_STOP_DP);
  addFlag(_FLG_STOP_E);

}






#endif 
