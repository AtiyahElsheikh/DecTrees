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
	@echo "	libdbg:		build lib with debuging"
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
INCFLAGS=-I$(DECSYSHOME)/src/interactivemenus/flagslib
INC= $(INCDECSYS) $(INCUTIL) $(INCPARADISEO) $(INCFLAGS)

CFLAGS=
OPTFLAGS=-O 
DBFLAGS=-g -DDEBUG

##Executables
EXE=
EXEDBG=

## Object files and src codes 
SRC=Menu.cpp MenuConstants.cpp \
  MenuVarsList.cpp MenuRegList.cpp \
  MenuExtendedList.cpp MenuRegExtList.cpp
OBJECTS=${SRC:.cpp=.o}
TARGET=$(LIBHOME)/libmenus.a
TARGETDBG=$(LIBHOME)/libmenus-dbg.a


libdbg:
	make clean
	make lib OPTFLAGS="$(DBFLAGS)" TARGET=$(TARGETDBG) LDFLAGS="-lutil-dbg -leoutils-dbg -ldecsys-dbg  -lflags-dbg"
	rm *.o 

lib:$(OBJECTS)
	ar  rcs $(TARGET) $(OBJECTS)

rebuild:
	make clean;
	make build

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
	rm -f  *.o $(EXE) $(EXEDBG) $(TARGET) $(TARGETDBG)

