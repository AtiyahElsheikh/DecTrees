_par_startvalfile = new eoValueParam<string>(DEF_STARTVALFILE,
					       "startvalfile",
					       "input file for extracting start values for SingleStart mode " + DEF_DATAFILE,
					       0,
					       true);

/**
 * \file DymolaMenu.cpp
 * \copydoc DymolaMenu.h 
 */ 


#include "DymolaMenu.h"
#include "MenuConstants.h"
#include "myconstants.h"

using namespace std; 


/// starttime 
double DymolaMenu::DEF_STARTTIME = myconstants::KEYS_DEF_VAL[0].second; 

/// stoptime 
double DymolaMenu::DEF_STOPTIME  = myconstants::KEYS_DEF_VAL[1].second;  

/// Increment 
double DymolaMenu::DEF_INCREMENT = myconstants::KEYS_DEF_VAL[2].second;

/// Increment 
double DymolaMenu::DEF_TOLERANCE = myconstants::KEYS_DEF_VAL[4].second;

/// Algorithm  
int DymolaMenu::DEF_ALGORITHM    = myconstants::KEYS_DEF_VAL[6].second;;

ConfigFlag<string>
DymolaMenu::FLG_SIMDIR(eoValueParam<string>(
		          "/path/to/model",     // default value     
			  string("simdir"),     // flag name --longname
			  "Path to Modelica Model, default: current directory",
			  0,                    // short name flag -c : ignore make it always 0 
			  false),               // wh. flag is required 
		       Condition(true));    // condition to process 
		      
ConfigFlag<double>
DymolaMenu::FLG_TOLERANCE(eoValueParam<double>(
			    DEF_TOLERANCE,
			    "tolerance",
			    "solver tolerance of results : [1e-8]",
			    0,
			    false),
			  Condition(true));


ConfigFlag<double>
DymolaMenu::FLG_INCREMENT(eoValueParam<double>(
			    DEF_INCREMENT,
			    "increment",
			    "increment of results : [0.2]",
			    0,
			    false),
			  Condition(true));
	   
ConfigFlag<int>
DymolaMenu::FLG_ALGORITHM(eoValueParam<int>(
                            DEF_ALGORITHM,
			    "algorithm",
			    "DAE Algorithm : [1-14]",
			    0,
			    false),
			  Condition(true));

///
ConfigFlag<double>  
DymolaMenu::FLG_STARTTIME(eoValueParam<double>(  
			      DEF_STARTTIME,
			      "starttime",
			      "simulation start time [0] ",
			      0,
			      false),
			  Condition(true)); 

///
ConfigFlag<double>  
DymolaMenu::FLG_STOPTIME(eoValueParam<double>(  
			      DEF_STOPTIME,
			      "stoptime",
			      "simulation stop time [1.0] ",
			      0,
			      false),
			 Condition(true)); //""); 


/**
 * A consistency routine for stoptime flag 
 */ 
bool DymolaMenu::stoptimeValid(void* data) { 

  if( DymolaMenu::FLG_STOPTIME.flagValue() <= 
      DymolaMenu::FLG_STARTTIME.flagValue() )
    cerr << "stoptime < starttime ???\n"; 

  return DymolaMenu::FLG_STOPTIME.flagValue() >= 
    DymolaMenu::FLG_STARTTIME.flagValue(); 

}

/**
 *
 */ 
bool DymolaMenu::setDefaultSimDir(void* data) { 
  
  if(!DymolaMenu::FLG_SIMDIR.flagExist()) { 
    
    // Get Current Diurectory 
    char cCurrentpath[FILENAME_MAX];
    if (!getcwd(cCurrentpath, sizeof(cCurrentpath))) {
      cerr << "current directory not obtainable\n" ;
      exit(0);
    }
    string currdir(cCurrentpath);
    FLG_SIMDIR.setValue(currdir);
  }

  return true;
}



/**
 *
 */ 
void DymolaMenu::specify() { 


  FLG_STOPTIME.setProccessFunc(&stoptimeValid);
  FLG_SIMDIR.setProccessFunc(&setDefaultSimDir);

  FLG_STARTTIME.insertChild(&FLG_STOPTIME);

  addFlag(&FLG_SIMDIR); 
  addFlag(&FLG_STARTTIME);
  addFlag(&FLG_INCREMENT);
  addFlag(&FLG_ALGORITHM);
  addFlag(&FLG_TOLERANCE); 
  
}


