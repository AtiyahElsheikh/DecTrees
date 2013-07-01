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
 * \file ShellCommands.h A collection of all commands executed by the framework
 * 
 * \class ShellCommands class for various shell-commands excuted by the framework   
 * 
 * 
 * Following shell commands are considered 
 * 1. System commands:
 * $ cp file1 file2 
 * 
 * 2. Dymosim commands:  
 * $ dymosim -s inp out [> stdout]
 * 
 * 3. Loading dsin.txt files 
 * $ loaddsin.ksh  /path/to/dsin*.txt  octdir 
 * 
 * 4. Updating dsin.txt 
 * $ updateDsin.sh inputdir exp=[StartTime=0,StopTime=5,..] init=[[p=1]*] dsinfile 
 * 
 * @author      Atiyah Elsheikh 
 * @version     1.0
 *
 */

#ifndef SHELLCOMMANDS_H
#define SHELLCOMMANDS_H
using namespace std; 
#include <string>

class ShellCommands { 

  private:

  /**
   * excute command by system call
   * 
   * @param command to be executed 
   * @param classCaller  from which class the command is needed
   * @param methodCaller by which class method this has been called 
   */
  static int execute(const string& command,
		     const string& classCaller,
		     const string& methodCaller); 

  
 public: 

  /**
   * $cp file1 file2
   * 
   * @param from file
   * @param to   file 
   * @param classCaller  from which class the command is needed
   * @param methodCaller by which class method this has been called 
   *
   */ 
  static bool copy(const string& from,
		   const string& to,
		   const string& classCaller,
		   const string& methodCaller); 


  /**
   * Make a directory using system call
   * @param name of directory 
   * @param classCaller  from which class the command is needed
   * @param methodCaller by which class method this has been called 
   */ 
  static bool makedir(const string& dir,
	       const string& classCaller,
	       const string& methodCaller); 

  /**
   * $ dymosim -s inp out [> out] 
   * 
   * @param dymexe dymola executable 
   * @param input file 
   * @param output file 
   * @param out 
   * @param classCaller  from which class the command is needed
   * @param methodCaller by which class method this has been called 
   */ 
  static bool dymosim(const string& dymexe,
		      const string& input,
		      const string& output,
		      const string& out,
		      const string& classCaller,
		      const string& methodCaller); 



  /**
   * $ loaddsin.ksh  /path/to/dsin*.txt  octdir 
   * Dymosim input-file dsin*.txt will be loaded by loaddsin.m from 
   * octave and required info will be output in single files under 
   * octdir 
   * 
   * @param filename Dymosim input file 
   * @param octdir   output directory 
   * @param classCaller  from which class the command is needed
   * @param methodCaller by which class method this has been called 
   */ 
  static bool loaddsin(const string& filename,
		       const string& octdir,
		       const string& classCaller,
		       const string& methodCaller); 
		      

  /**
   * $ updateDsin.sh inputdir exp=[StartTime=0,StopTime=5,..] init=[[p=1]*] dsinfile
   * Update Dymosim inputfile  
   *
   * @param inpdir input directory where Dymosim input file is
   * @param simulation parameter arguments to be changed StartTime=0,StopTime=5,...
   * @param model parameters to be changed [p=<val>]*
   * @param inputfile   
   * @param classCaller  from which class the command is needed
   * @param methodCaller by which class method this has been called 
   */
  static bool updatedsin(const string& inpdir,
			 const string& exparg,
			 const string& initarg,
			 const string& inpfile,
			 const string& classCaller,
			 const string& methodCaller); 
 
}; 

#endif 
