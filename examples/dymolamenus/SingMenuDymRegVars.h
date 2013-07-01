/**
 * \file  SingMenuDymRegVars.h
 * \class SingMenuDymRegVars provides basic flags for Dymola 
 * variables list of regular expressions. 
 * 
 *
 * @author      Atiyah Elsheikh 
 */


#ifndef SINGMENUDYMREGVARS_H
#define SINGMENUDYMREGVARS_H

#include <eo>
#include "SingltonTemplate.h"
#include "SingMenuDymExpVars.h"
#include "MenuDymRegVars.h"
#include "RegListFlag.h"



class SingMenuDymRegVars
:public SingltonTemplate<MenuDymRegVars> { 

 private:

  /// flag for vars 
  static RegListFlag*  FLG_REGVARS;

  /// flag for invars
  static RegListFlag*  FLG_REGINVARS;

  /// a menu for regular variables 
  //  static MenuRegList*  MENU_DYMREGVARS;  

 protected:

 

  /**
   * protected Cor to ensure that the menu is declared only with create() 
   */ 
  SingMenuDymRegVars() { }


  /**
   * DCor
   */ 
  virtual ~SingMenuDymRegVars() { 
#ifdef DEBUG
    cout << "SingMenuDymRegVars::~ called\n";
#endif

    delete FLG_REGINVARS;    FLG_REGINVARS   = 0; 
    delete FLG_REGVARS;      FLG_REGVARS     = 0; 
    //delete MENU_DYMREGVARS;  MENU_DYMREGVARS = 0; 
    SingMenuDymExpVars::finalize();
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
  inline static MenuDymRegVars* getMenu() { 
    if(!isCreated()) create(); 
    return _object; 
  }
  

}; 

#endif
