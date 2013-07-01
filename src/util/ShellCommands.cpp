/*    
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
 * 
 * \file DsinDescriptor.cpp 
 * \copydoc DsinDescriptor.h 
 * @autodate
 * 
 */ 

#include "ShellCommands.h"
#include "myutil.h" 
#include "myconstants.h"

/**
 *
 */
int ShellCommands::execute(const string& command,
			   const string& classCaller,
			   const string& methodCaller) { 


#ifdef DEBUG 
  cout << classCaller << "::" << methodCaller << " excuting : " 
       << command << "\n"; 
#endif 

  int call = system(command.c_str()); 
  
  return call; 
}



/**
 *
 */ 
bool ShellCommands::copy(const string& from,
			 const string& to,
			 const string& classCaller,
			 const string& methodCaller)  { 
  
  if(!Myutil::file_exists(from.c_str())) { 
    cerr << classCaller << "::" << methodCaller << "  " 
	 << from << " does not exist!\n";
    assert(false);
    return false; 
  }

  if(to.empty()) { 
    cerr << classCaller << "::" << methodCaller << "  " 
	 << " 2nd argument for copy is empty\n"; 
    assert(false);
    return false; 
  }

  int call = execute("cp " + from + " " + to,classCaller,methodCaller);

  if(!Myutil::file_exists(to.c_str())) { 
    cerr << classCaller << "::" << methodCaller << "  " 
	 << to << " does not exist after copy!\n";
    assert(false);
    return false; 
  }

  return true; 
} 



/**
 *
 */ 
bool ShellCommands::makedir(const string& dir,
			    const string& classCaller,
			    const string& methodCaller) { 
  
  int call = execute("mkdir -p " + dir,
		     classCaller,
		     methodCaller);
  
  assert(Myutil::file_exists(dir.c_str())); 

  return true;
}


/**
 *
 */ 
bool ShellCommands::dymosim(const string& dymexe,
			    const string& input,
			    const string& output,
			    const string& out,
			    const string& classCaller,
			    const string& methodCaller) { 

  int call = execute(dymexe +" -s " +  
		     input + " " + output + " " + out ,
		     classCaller,
		     methodCaller);
 
  return true; 
}


/**
 *
 */
bool ShellCommands::loaddsin(const string& filename,
			     const string& octdir,
			     const string& classCaller,
			     const string& methodCaller) { 

  int call = execute(myconstants::LOAD_DSIN_SHELL + " " + 
		     filename + " " + octdir, 
		     classCaller,
		     methodCaller);

  

   string octpfile = octdir + myconstants::OCTAVE_PAR_FILE;
  
  if(!Myutil::file_exists(octpfile.c_str())) { 
    cerr << octpfile << " does not exist\n" ; 
    return false;
  }
   
  string octpnamefile = octdir + myconstants::OCTAVE_PARNAMES_FILE;

  if( !Myutil::file_exists(octpnamefile.c_str())) {
    cerr << octpnamefile  << " does not exist!\n"; 
    return false; 
  }

  //Initialize start values 
  string octx0file = octdir + myconstants::OCTAVE_X0_FILE;
  
  if(!Myutil::file_exists(octx0file.c_str())) { 
    cerr << octx0file << " does not exist! \n"; 
    return false;
  }

  string octx0namefile = octdir + myconstants::OCTAVE_X0NAMES_FILE;

  if(!Myutil::file_exists(octx0namefile.c_str())) { 
    cerr << octx0namefile << " does not exist \n"; 
    return false; 
  }

  return true; 
}


/**
 *
 */ 
bool ShellCommands::updatedsin(const string& inpdir,
			       const string& exparg,
			       const string& initarg,
			       const string& inpfile,
			       const string& classCaller,
			       const string& methodCaller) { 

  int call = execute(myconstants::UPDATE_DSIN_SHELL +
		     " dir="  + inpdir +
		     " exp=["  + exparg +
		     "] init=[" +  initarg + "] " + 
		     inpfile,
		     classCaller,
		     methodCaller
		     ); 
  
  return true; 
}



