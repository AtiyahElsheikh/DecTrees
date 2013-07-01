CC=g++
PRE=time
PARADISEOHOME=$(DECSYSHOME)/ThirdParty/paradiseo-eo
LIBHOME=$(DECSYSHOME)/lib
UTILHOME=$(DECSYSHOME)/src/util

help:
	@echo "Targets"
	@echo "======="
	@echo ""
	@echo "	lib:		build library"
	@echo "	build:		build exe without debuging"
	@echo "	builddbg:	build exe with    debuging"
	@echo "	rebuild:        clean and build"
	@echo "	clean:		clean all objects"
	@echo ""

##Compiler Flags 

LIBUTIL=-L$(LIBHOME) 
LIBPARADISEO=-L$(LIBHOME) 
LIBDECSYS=-L$(LIBHOME)
LDLIBS=-L$(LIBHOME)
LDFLAGS=-lutil -leoutils -ldecsys 
INCPARADISEO=-I$(PARADISEOHOME)/src -I$(PARADISEOHOME)/src/utils
INCUTIL=-I$(UTILHOME)
INCDECSYS=-I$(DECSYSHOME)/src/main
INC= $(INCDECSYS) $(INCUTIL) $(INCPARADISEO)

CFLAGS=
OPTFLAGS=-O 
DBFLAGS=-g -DDEBUG

##Executables
EXE=$(DECSYSHOME)/bin/testflags.exe
EXEDBG=$(DECSYSHOME)/bin/testflags-dbg.exe

## Object files and src codes 
SRC=ConfigFlag.cpp \
    SpecifiedFlag.cpp DiscreteFlag.cpp BoundedFlag.cpp  \
    ListFlag.cpp RegListFlag.cpp 

OBJECTS=${SRC:.cpp=.o}
TARGET=$(LIBHOME)/libflags.a
TARGETDBG=$(LIBHOME)/libflags-dbg.a

build:$(EXE)

builddbg:
	make clean
	make build OPTFLAGS="$(DBFLAGS)" EXE=$(EXEDBG) TARGET=$(TARGETDBG) LDFLAGS="-lutil-dbg -leoutils-dbg -ldecsys-dbg "
	rm *.o 

lib:$(OBJECTS)
	ar  rcs $(TARGET) $(OBJECTS)

libdbg:
	make clean
	make lib OPTFLAGS="$(DBFLAGS)" EXE=$(EXEDBG) TARGET=$(TARGETDBG) LDFLAGS="-lutil-dbg -leoutils-dbg -ldecsys-dbg "
	rm *.o 


rebuild:
	make clean;
	make build

$(EXE):$(OBJECTS) main.o
	$(CC) -o $@ $(OBJECTS) main.o $(LDLIBS) $(LDFLAGS)
	make lib

###
# Objects 
#

.cpp.o:
	$(CC) -c $(CFLAGS) $(OPTFLAGS) $(INC) $<

###
# DBG-Objects 
# 

# Further Dependencies 

depend:
	makedepend -- $(SRC)

clean:
	rm -f $(EXE) $(EXEDBG) *.o $(TARGET) $(TARGETDBG) 

