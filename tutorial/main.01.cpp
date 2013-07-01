using namespace std;

#include <eo>
#include "ParserSinglton.h"


/**
 *
 */
int main(int argc, char** argv) { 


  // create a parser 
  ParserSinglton::create(argc,argv,"current_param.conf"); 
  eoParser* parser = ParserSinglton::getObject();

  // code for creating flags and menus 
  // ... 
   

  // generate the configuration file
  ParserSinglton::generateConfFile();
 
  // deallocate memory 
  ParserSinglton::finalize();  
 
 
}

