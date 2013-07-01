CC=g++
PRE=time
LIBHOME=$(DECSYSHOME)lib

help:
	@echo "Targets"
	@echo "======="
	@echo ""
	@echo "	lib:		build exe without debuging"
	@echo "	libdbg:		build exe with    debuging"
	@echo "	rebuild:	clean and build"
	@echo "	clean:		clean all objects"
	@echo ""

##Compiler Flags 

CFLAGS=
OPTFLAGS=-O 
DBFLAGS=-g -DDEBUG
INC=-I.


## Object files and src codes 
SRC=eoParser.cpp eoPersistent.cpp eoPrintable.cpp utils/eoData.cpp 
OBJECTS=eoParser.o eoPersistent.o eoPrintable.o utils/eoData.o
TARGET=$(LIBHOME)/libeoutils.a
TARGETDBG=$(LIBHOME)/libeoutils-dbg.a


libdbg:
	make clean
	make lib OPTFLAGS="$(DBFLAGS)" TARGET=$(TARGETDBG)
	rm *.o 

lib:$(OBJECTS) 
	ar  rcs  $(TARGET) $(OBJECTS)

rebuild:
	make clean;
	make build 

eoParser.o:eoParser.cpp
	$(CC) -c $(INC) $(CFLAGS) $(OPTFLAGS) eoParser.cpp 

eoPersistent.o:eoPersistent.cpp
	$(CC) -c $(INC) $(CFLAGS) $(OPTFLAGS) eoPersistent.cpp

eoPrintable.o:eoPrintable.cpp
	$(CC) -c $(INC) $(CFLAGS) $(OPTFLAGS) eoPrintable.cpp

utils/eoData.o:utils/eoData.cpp
	$(CC) -c $(INC) $(CFLAGS) $(OPTFLAGS) utils/eoData.cpp -o utils/eoData.o


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
	rm -f $(OBJECTS) $(TARGET) $(TARGETDBG)

