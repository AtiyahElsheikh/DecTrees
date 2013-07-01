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
 * \file  CommonFlags.h
 * \class CommonFlags a repositary of flags used throughout multiple menus
 * 
 * @author      Atiyah Elsheikh 
 */


#ifndef COMMONFLAGS_H
#define COMMONFLAGS_H

//#include <eo>
#include "SingltonFlag.h"
#include "FlagInterface.h"
using namespace std; 



class FlagFuns { 

 private:

  /// conditions needed to initialize flags 
  static vector<Condition*> _conditions; 

 public:

  /**
   * de allocate all memories used 
   */ 
  static void finalize();

  /** */
  static string CAND_MODE[];

  /** */ 
  static string DEF_MODE;

  /** */ 
  static FlagInterface* FLG_SIMDIR();

  /** */ 
  static bool setDefaultSimDir(void* data);

  /** */ 
  static FlagInterface* FLG_PCAND();

  /** */ 
  static FlagInterface* FLG_RPAR(); 

  /** */ 
  static FlagInterface* FLG_APAR();

  /** */
  static FlagInterface* FLG_SVUPBD(); 
  
  /** */ 
  static FlagInterface* FLG_SVLOBD(); 

  /** */ 
  static FlagInterface* FLG_MODE();

  /** */ 
  static FlagInterface* FLG_ANADER();

  /** */ 
  static FlagInterface* FLG_FDSTEP();
};

/// \class FlgAnaDer whether derivatives are analytic 
typedef SingltonFlag<&FlagFuns::FLG_FDSTEP> FlgFDStep;

/// \class FlgAnaDer whether derivatives are analytic 
typedef SingltonFlag<&FlagFuns::FLG_ANADER> FlgAnaDer;

/// \class FlgSimDir simulation directory flag 
typedef SingltonFlag<&FlagFuns::FLG_SIMDIR> FlgSimDir; 

/// \class FlgMode configuration mode : Single Start, Multi or Monte Carlo
typedef SingltonFlag<&FlagFuns::FLG_MODE> FlgMode; 

/// \class FlgParCand  parameter candidate flag
typedef SingltonFlag<&FlagFuns::FLG_PCAND>  FlgParCand;

/// \class FlgRegPars  regular expression of parameters flag
typedef SingltonFlag<&FlagFuns::FLG_RPAR>  FlgRegPars;

/// \class FlgActPars  active parameters flag
typedef SingltonFlag<&FlagFuns::FLG_APAR>  FlgActPars;

/// \class FlgSvUppBd  upper bound for start values flag 
typedef SingltonFlag<&FlagFuns::FLG_SVUPBD>  FlgSvUppBd;

/// \class FlgSvLowBd  lower bound for start values flag
typedef SingltonFlag<&FlagFuns::FLG_SVLOBD>  FlgSvLowBd;


#endif 

