#/bin/sh

###
# env variables 
export DECSYSHOME=$PWD/

###
# ThirdParty
echo compiling paradiseo-eo components 
echo =================================
echo 
cd $DECSYSHOME/ThirdParty/paradiseo-eo/src 
make $@
echo 
echo 

###
# utilities 
echo compiling utility routines 
echo ==========================
echo
cd $DECSYSHOME/src/util  
make $@
echo 
echo 


###
# main components of decsion systems 
echo compiling decision tree components 
echo ==================================
echo 
cd $DECSYSHOME/src/main  
make $@
echo 
echo 


###
# main components of decsion systems 
echo compiling flags library  
echo =======================
echo 
cd $DECSYSHOME/src/interactivemenus/flagslib  
make $@ 
echo 
echo 


###
# main components of decsion systems 
echo compiling menus library 
echo =======================
echo 
cd $DECSYSHOME/src/interactivemenus/menuslib  
make $@ 
echo 
echo 
