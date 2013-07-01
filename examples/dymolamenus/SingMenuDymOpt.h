/**
 * \file  SingMenuDymOpt.h
 * \class SingMenuDymOpt a unique menu for managing dymola optimization 
 * 
 *
 * @author      Atiyah Elsheikh 
 * 
 */


#ifndef SINGMENUDYMOPT_H
#define SINGMENUDYMOPT_H


#include "MenuConfiguration.h" 

class SingMenuDymOpt; 

class SingMenuDymOpt : public SingltonTemplate<SingMenuDymOpt> { 

 private:


 protected:


  SingMenuDymOpt() { }


  virtual ~SingMenuDymOpt { } 


 public:


  /**
   *
   */ 
  static void create();



  

};

#endif 
