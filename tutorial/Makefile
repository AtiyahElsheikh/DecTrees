CC=g++
DYMSIMHOME=..
PARADISEOHOME=../optalg/paradiseo-1.2.1

help:
	@echo "Targets"
	@echo "======="
	@echo ""
	@echo "	build:		build exe without debuging"
	@echo "	clean:		clean all objects"
	@echo ""


##Compiler Flags 
DBFLAGS=-g -DDEBUG
MACROS=
OPTFLAGS=-O 
LIBPARADISEO=$(PARADISEOHOME)/paradiseo-eo/build/lib 
LDLIBS=-L$(LIBPARADISEO)$ \
	-L$(DYMSIMHOME)/util \
	-lutil -leoutils -leo
INCPARADISEO=-I$(PARADISEOHOME)/paradiseo-eo/src
INC=-I. -I$(DYMSIMHOME)/util 

CFLAGS=
LDFLAGS=$(LDLIBS)

##Executables
EXE=mymenus

## Object files and src codes 
SRC=MenuLevMar.cpp

OBJECTS=${SRC:.cpp=.o}

## Compile Targets  

build:$(EXE) ../util/libutil.a

builddbg:
	make clean
	make build OPTFLAGS="$(DBFLAGS)" LDFLAGS="$(LDDBFLAGS)"
	mv libmenus.a libmenus-dbg.a

lib:$(OBJECTS)
	ar  rcs  mymenus.a $(OBJECTS)

$(EXE):$(OBJECTS) main.o 
	$(CC) -o $@  main.o $(OBJECTS) $(LDFLAGS)
	make lib


###
# Objects 
#

.cpp.o:
	$(CC) -c $(INC) $(INCPARADISEO) $(OPTFLAGS) $<


# Further Dependencies 

depend:
	makedepend -- $(INC) -- $(SRC)


clean:
	rm -f $(DYMSIMHOME)/bin/*.exe *.o *.a


