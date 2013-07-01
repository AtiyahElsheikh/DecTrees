using namespace std;

#include <eo>
#include "ParserSinglton.h"

#include "ConfigFlag.h"
#include "Condition.h"


/**
 *
 */
int main(int argc, char** argv) { 


  // create a parser 
  ParserSinglton::create(argc,argv,"current_param.conf"); 
  eoParser* parser = ParserSinglton::getObject();

  // code for creating flags and menus 
  // ... 
   

  // flag specification 
  ConfigFlag<int>  flag(eoValueParam<int>(
			     1,                 // default value 
			     "flagname",            // long name --flag
			     "flag comments",   // commnets to the flag
			     0,                 // short name
			     false),            // required or not
			   (Condition *) 0);    // Condition to create

  // exploring the flag 
  flag.explore(0);

  // accessing flag values 
  cout << "flag value of --" << flag.flagKey() 
       << " is " << flag.flagValue() << "\n";  

  // generate the configuration file
  ParserSinglton::generateConfFile();
 
  // deallocate memory 
  ParserSinglton::finalize();  
 
 
}

