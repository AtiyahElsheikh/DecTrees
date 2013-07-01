CC=g++
PRE=time
PARADISEOHOME=../paradiseo-eo
UTILHOME=../util
FLAGSHOME=../flagslib
#MENUSHOME=../menuslib

help:
	@echo "Targets"
	@echo "======="
	@echo ""
	@echo "	build:		build exe without debuging"
	@echo "	builddbg:	build exe with    debuging"
	@echo "	run:		run exe"
	@echo "	rundbg:		run dbg-exe"
	@echo "	clean:		clean all objects"
	@echo ""


##Compiler Flags 
LIBUTIL=-L$(UTILHOME) 
LIBPARADISEO=-L$(PARADISEOHOME)/lib
LIBFLAGS=-L$(FLAGSHOME)
#LIBMENUS=-L$(MENUSHOME)
LDLIBS=$(LIBPARADISEO) $(LIBUTIL) $(LIBFLAGS)
LDFLAGS=$(LDLIBS) -lutil -leoutils -lflags
INCPARADISEO=-I$(PARADISEOHOME)/src -I$(PARADISEOHOME)/src/utils
INC=$(INCPARADISEO) -I$(UTILHOME) -I$(FLAGSHOME)
DBFLAGS=-g -DDEBUG
MACROS=
OPTFLAGS=-O 

##Executables
EXE=$(DYMSIMHOME)/bin/testdymflags.exe

## Object files and src codes 

SRC=CommonFlags.cpp SingltonFlag.cpp
OBJECTS=${SRC:.cpp=.o}



## Compile Targets  

build:$(EXE)

builddbg:
	make clean
	make build 	OPTFLAGS="$(DBFLAGS)" LDFLAGS="$(LDFLAGS) -lutil-dbg" 
	mv libflags.a libflags-dbg.a

$(EXE):$(OBJECTS) main.o
	$(CC) -o $@  main.o $(OBJECTS) $(LDFLAGS)
	ar  rcs  libdymflags.a $(OBJECTS)


###
# Objects 
#

.cpp.o:
	$(CC) -c $(INC) $(OPTFLAGS) $<

# Further Dependencies 

depend:
	makedepend -- $(INC) -- $(SRC)


clean:
	rm -f *.o *.a

