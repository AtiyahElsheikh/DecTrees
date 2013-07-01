using namespace std;

#include <eo>
#include "ParserSinglton.h"

#include "ConfigFlag.h"
#include "Condition.h"

#include "ListFlag.h"
#include "DiscreteFlag.h"

/**
 *
 */
int main(int argc, char** argv) { 

  //
  // create a parser 
  //
  ParserSinglton::create(argc,argv,"current_param.conf"); 
  eoParser* parser = ParserSinglton::getObject();

  //
  // code for creating flags and menus 
  // ... 
   

  //
  // flag specification 
  //
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

  //
  // An example with ListFlag
  //
  ListFlag  listflag(eoValueParam<string>(
		        "",
			"pars",
			"parameters to be estimated",
			0,
			true),               
		     (Condition *) 0);
  listflag.explore(0);
  
  vector<string> listflagvals; 
  listflag.flagValues(listflagvals); 

  cout << "flag values of --" << listflag.flagKey() << "\n"; 
  for(int i=0;i<listflagvals.size();i++)
    cout << "   " << listflagvals[i] << "\n"; 


  //
  // An example with DiscreteFlag 
  //
  string Candidates[] = {"Tolga","Michael","Frieder"}; 

  DiscreteFlag<string,string*> 
    inviteMeToIce(                          //iterator of type string*
    eoValueParam<string>(
       Candidates[0],
       "WhoWillInviteMeToday",
       "candidates are: Tolga, Michael, Fireder",
       0,
       true),                               // it is required 
    NULL,                                   // without any conditions 
    Candidates,                             // iterator begin
    Candidates+sizeof Candidates / sizeof(string));  // end

  inviteMeToIce.explore(0);
  cout << inviteMeToIce.flagValue() << " will invite me to ice\n";
 
  //
  // generate the configuration file
  //
  ParserSinglton::generateConfFile();
 
  //
  // deallocate memory 
  //
  ParserSinglton::finalize();  
 
 
}

