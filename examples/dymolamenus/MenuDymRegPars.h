/**
 * \file  MenuDymRegPars.h
 * \class MenuDymRegPars provides basic configuration flags for simulating a Dymola program.  
 * 
 *
 * @author      Atiyah Elsheikh 
 * @date        Mar 2010
 * @since       Feb 2010
 * @version     1.0
 */


#ifndef MENUDYMREGPARS_H
#define MENUDYMREGPARS_H

#include <eo>
#include "RegListFlag.h"
#include "MenuDymExpPars.h"
#include "MenuRegList.h"


class MenuDymRegPars:public MenuRegList { 


 private:

 

  
 protected:
 
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
  MenuDymRegPars(RegListFlag*    rinPars,
		 RegListFlag*    rPars,
		 MenuDymExpPars* menu,
		 const string&    section,
		 Condition* cond,
		 bool optional) 
    : MenuRegList(rinPars,rPars,menu,section,cond,optional) { }
 

  /**
   * Copy Cor 
   */ 
 MenuDymRegPars(const MenuDymRegPars& menu)
   : MenuRegList( (MenuRegList) menu) { }


  /**
   * DCor
   */ 
  virtual ~MenuDymRegPars() { 
#ifdef DEBUG
    cout << "MenuDymRegPars::~ called\n";
#endif
  } 

  

}; 

#endif
