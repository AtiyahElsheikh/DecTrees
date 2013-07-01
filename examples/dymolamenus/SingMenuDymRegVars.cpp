/**
 * \file SingMenuDymRegVars.cpp
 * \copydoc SingMenuDymRegVars.h 
 */ 


#include "SingMenuDymRegVars.h"




///
RegListFlag* 
SingMenuDymRegVars::FLG_REGVARS = (RegListFlag* ) 0; 
    
///
RegListFlag*
SingMenuDymRegVars::FLG_REGINVARS = (RegListFlag *) 0;


/**
 *
 */ 
void
SingMenuDymRegVars::create() { 


  
  if(!isCreated()) {
 
    _created  = true; 

    _singlton = new SingMenuDymRegVars(); 


    FLG_REGVARS 
      = new RegListFlag(eoValueParam<string>(
			  "",
			  "regvars",
			  "list of regular expressions for variables",
			  0,
			  false),               
			NULL);


    FLG_REGINVARS 
      = new RegListFlag(eoValueParam<string>(
			  "", 
			  "reginvars",
			  "list of regular expressions for inactive variables",
			  0,
			  false), 
			NULL);   

 


    _object =
      new MenuDymRegVars(FLG_REGINVARS,
			 FLG_REGVARS,
			 SingMenuDymExpVars::getMenu(),
			 MenuConstants::SECRVAR,
			 NULL,
			 false);

  }
}
