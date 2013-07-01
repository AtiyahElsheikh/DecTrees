/**
 * \file  MenuLevMar.h
 * \class MenuLevMar provides basic flags for the optimization 
 *                   software LEVMAR 
 *                    
 * 
 *
 * @author      Atiyah Elsheikh 
 * @date        Mar 2010
 * @since       Mar 2010
 * @version     1.0
 */


#ifndef MENULEVMAR_H
#define MENULEVMAR_H

#include <eo>
#include "Menu.h"
#include "MenuConstants.h"
#include "BoundedFlag.h"
#include "DiscreteFlag.h"


using namespace std;



class MenuLevMar:public Menu { 


 private:

 protected:
  
  /**
   *
   */ 
  virtual void specify();

 
 public:


  /**
   * Cor
   * @param condition to process this node 
   * @param optional whether succissful processing 
   *        for the menu is necessary for overall success
   */ 
 MenuLevMar(Condition* cond,
	    bool optional) 
   : Menu(MenuConstants::SECOPTM,cond,optional) {
    specify();
  } 
  
  /**
   * Copy Cor 
   */ 
 MenuLevMar(const MenuLevMar& menu)
   : Menu(MenuConstants::SECOPTM,menu._condition,menu.isOptional()) { }  
  
  
  /**
   * DCor
   */ 
  virtual ~MenuLevMar() { 
#ifdef DEBUG
    cout << "MenuLevMar::~ called\n";
#endif

    delete _FLG_PSCALING; _FLG_PSCALING = 0; 
    delete _FLG_MAXITER; _FLG_MAXITER  = 0;
    delete _FLG_LAMBDA;  _FLG_LAMBDA   = 0; 
    delete _FLG_STOP_JE; _FLG_STOP_JE  = 0; 
    delete _FLG_STOP_DP; _FLG_STOP_DP  = 0; 
    delete _FLG_STOP_E;  _FLG_STOP_E   = 0;
  } 


  /// candiate values of optsoft flag 
  static string CAND_PSCALING[]; 
  
  ///
  /// Flags 
  ///

  /// flag for optimization software 
  DiscreteFlag<string,string*>* _FLG_PSCALING; 
  
  /// max. number of iterations 
  ConfigFlag<int>*      _FLG_MAXITER;

  /// start lambda of LM 
  ConfigFlag<double>*   _FLG_LAMBDA;

  /// stop criteria ||J^T * e||_{inf} : change in the goal function 
  ConfigFlag<double>*   _FLG_STOP_JE; 

  /// stop criteria || D * p || : change in the scaled optimization variables 
  ConfigFlag<double>*   _FLG_STOP_DP; 

  /// stop criteria || e || : value of the goal function  
  ConfigFlag<double>*   _FLG_STOP_E; 

};

#endif
