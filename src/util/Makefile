CC=g++
PRE=time
PARADISEOHOME=$(DECSYSHOME)/ThirdParty/paradiseo-eo
LIBHOME=$(DECSYSHOME)/lib

help:
	@echo "Targets"
	@echo "======="
	@echo ""
	@echo "	lib:		build library"
	@echo "	libdbg:		build library with debuging"
	@echo "	rebuild:        clean and build"
	@echo "	clean:		clean all objects"
	@echo ""

##Compiler Flags 

LIBPARADISEO=-L$(LIBHOME) -leoutils 
LDLIBS=$(LIBPARADISEO)
INCPARADISEO=-I$(PARADISEOHOME)/src -I$(PARADISEOHOME)/src/utils

CFLAGS=
OPTFLAGS=-O 
DBFLAGS=-g -DDEBUG

## Object files and src codes 
SRC=SingltonTemplate.cpp ParserSinglton.cpp  \
  myconstants.cpp myutil.cpp ShellCommands.cpp 
OBJECTS=${SRC:.cpp=.o}
TARGET=$(LIBHOME)/libutil.a
TARGETDBG=$(LIBHOME)/libutil-dbg.a

#build:$(EXE)

libdbg:
	make clean
	make lib OPTFLAGS="$(DBFLAGS)" TARGET=$(TARGETDBG)
	rm *.o 

lib:$(OBJECTS)
	ar  rcs $(TARGET) $(OBJECTS)

rebuild:
	make clean;
	make lib

###
# Objects 
#

.cpp.o:
	$(CC) -c $(CFLAGS) $(OPTFLAGS) $(INCPARADISEO) $<

###
# DBG-Objects 
# 


# Further Dependencies 

depend:
	makedepend -- $(SRC)

clean:
	rm -f  *.o $(TARGET) $(TARGETDBG)


