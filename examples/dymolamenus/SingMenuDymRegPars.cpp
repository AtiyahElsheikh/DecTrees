/**
 * \file SingMenuDymRegPars.cpp
 * \copydoc SingMenuDymRegPars.h 
 */ 


#include "SingMenuDymRegPars.h"


///
RegListFlag* 
SingMenuDymRegPars::FLG_REGPARS = (RegListFlag* ) 0; 
    
///
RegListFlag*
SingMenuDymRegPars::FLG_REGINPARS = (RegListFlag *) 0;


/**
 *
 */ 
void
SingMenuDymRegPars::create() { 


  
  if(!isCreated()) {
 
    _created  = true; 

    _singlton = new SingMenuDymRegPars(); 


    /*  FLG_REGPARS 
      = new RegListFlag(eoValueParam<string>(
			  "",
			  "regpars",
			  "list of regular expressions for parameters",
			  0,
			  false),               
			  Condition(true));*/
    
    FLG_REGPARS = (RegListFlag*) FlgRegPars::getObject();


    FLG_REGINPARS 
      = new RegListFlag(eoValueParam<string>(
			  "", 
			  "reginpars",
			  "list of regular expressions for inactive parameters",
			  0,
			  false), 
			NULL);   

 


    _object =
      new MenuDymRegPars(FLG_REGINPARS,
			 FLG_REGPARS,
			 SingMenuDymExpPars::getMenu(),
			 MenuConstants::SECRPAR,
			 NULL,
			 false);

  }
}
