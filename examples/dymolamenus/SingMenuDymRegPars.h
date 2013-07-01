/**
 * \file  SingMenuDymRegPars.h
 * \class SingMenuDymRegPars provides basic flags for a 
 *  list of regular expressions for determining active parameters
 * 
 *
 * @author      Atiyah Elsheikh 
 */


#ifndef SINGMENUDYMREGPARS_H
#define SINGMENUDYMREGPARS_H

#include <eo>
#include "SingltonTemplate.h"
#include "SingMenuDymExpPars.h"
#include "MenuDymRegPars.h"
#include "RegListFlag.h"
#include "CommonFlags.h"


class SingMenuDymRegPars
:public SingltonTemplate<MenuDymRegPars> { 

 private:

  /// flag for Pars 
  static RegListFlag*  FLG_REGPARS;

  /// flag for inPars
  static RegListFlag*  FLG_REGINPARS;


 protected:


  /**
   * protected Cor to ensure that the menu is declared only with create() 
   */ 
  SingMenuDymRegPars() { }


  /**
   * DCor
   */ 
  virtual ~SingMenuDymRegPars() { 
#ifdef DEBUG
    cout << "SingMenuDymRegPars::~ called\n";
#endif

    delete FLG_REGINPARS;    FLG_REGINPARS   = 0; 
    //delete FLG_REGPARS;      FLG_REGPARS     = 0; 
    FlgRegPars::finalize();
    SingMenuDymExpPars::finalize();
  } 


 public:

  
  /**
   *  
   */ 
  static void create(); 

  
  
  /**
   * get pointer to the menu instance 
   * @todo create if not yet created 
   */
  inline static MenuDymRegPars* getMenu() { 
    if(!isCreated()) create(); 
    return _object; 
  }
  

}; 

#endif
