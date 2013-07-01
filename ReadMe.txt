About 
=====

C++ libraries for implementing dependent flags and menus relying on decision 
systems. Combining them with emacs, simple interactive menus can be created.



Contact details
===============

Atiyah Elsheikh, Energy Department, Austrian Institute of Technology GmbH (AIT), Vienna, Austria
Email: Atiyah.Elsheikh@ait.ac.at 

License
=======

This software is distributed under the terms and conditions of LGPL


Reference
=========
If this software is useful for you, please reference the following paper 

Atiyah Elsheikh, Assisting identifiability analysis of large-scale dynamical models
with decision trees: DecTrees and InteractiveMenus, In The 8th EUROSIM Congress on 
Modelling and Simulation, Cardiff, Wales, UK, Sep. 2013.  

@INPROCEEDINGS{Elsheikh:DT:2013,
  author = {Atiyah Elsheikh},
  title = {Assisting identifiability analysis of large-scale dynamical models
	with decision trees: DecTrees and InteractiveMenus},
  booktitle = {The 8th EUROSIM Congress on Modelling and Simulation},
  year = {2013},
  address = {Cardiff, Wales, UK},
  month = {Sep.}
}

Tested Platforms
================

1. Tested with Cygwin gcc version 4.5.3 
2. Tested with Linux-Suse gcc version 4.6.2
3. Tested with Mingw gcc 4.3.4 (Regular expression excluded) 

Structure
=========
Directories are: 


src/			: main source
   /util		: utilites routines 
   /main		: decision tree components 
   /interactivemenus 	: components of interactive menus     
   	/flagslib    	: flags 
	/menuslib    	: menus 
ThirdParty/   		: A third party tool paradiseo. Only the required headerfiles 
	          	  and source code is utilized 
lib/			: compiled libraries 
bin/			: test drivers 
tutorial/		: getting-started tutorial about developing with this code  
doc/			: API with doxygen  
examples		: real examples: menus for the software Dymola 

Installation
============

building libraries is done with 
$ build.sh lib 

Building test drivers under bin is done with 
$ build.sh build 

Clean the installation is done with
$ build.sh clean 

Building for mingw is done with adding 
$ build.sh -f Makefile.mingw lib 

Remarks
-------
A. 
The code depends on few elements of the Paradiseo software. 
You can either install the software or rely on the 
available elements extracted from the software

B. 
All routines making use of regexp.h are excluded when compiled within mingw 
There are only few routines, and a re-implementation is possible with the Boost library



Getting started
===============
cf. tutorial/  


ToDo
====
1. implement operators for the Conditions 
2. stub generators : Code for specialized menus to get generated with 
