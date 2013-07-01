CC=g++
PRE=time
DYMSIMHOME=..
PARADISEOHOME=../optalg/paradiseo-1.2.1

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
DBFLAGS=-g -DDEBUG
MACROS=
OPTFLAGS=-O 
LIBPARADISEO=$(PARADISEOHOME)/paradiseo-eo/build/lib 
LDLIBS=-L$(LIBPARADISEO)$ \
	-L$(DYMSIMHOME)/util \
	-L$(DYMSIMHOME)/flagslib \
	-L$(DYMSIMHOME)/dymsim \
	-ldymsim -lflags -lutil -leoutils -leo
INCPARADISEO=-I$(PARADISEOHOME)/paradiseo-eo/src
INC=-I. -I$(DYMSIMHOME)/dymsim \
	-I$(DYMSIMHOME)/util \
	-I$(DYMSIMHOME)/flagslib
CFLAGS=
LDFLAGS=$(LDLIBS)
LDDBFLAGS=$(LDFLAGS)-lflags-dbg -lutil-dbg
##Executables
EXE=$(DYMSIMHOME)/bin/testmenus.exe

## Object files and src codes 

#SRC=MenuDymExpVars.cpp SingMenuDymExpVars.cpp	 SingMenuDymRegVars.cpp \
  MenuDymExpPars.cpp \
  MenuDymParsVals.cpp SingMenuDymParsVals.cpp
SRC=MenuDymParsVals.cpp SingMenuExtList.cpp MenuExtListFactory.cpp \
    MenuConfiguration.cpp MenuDymola.cpp MenuLevMar.cpp \
    MenuData.cpp MenuMultiStart.cpp MenuMonteCarlo.cpp \
    SingMenuDymExpVars.cpp MenuDymExpVars.cpp \
    SingMenuDymRegVars.cpp \
    SingMenuDymExpPars.cpp MenuDymExpPars.cpp \
    SingMenuDymRegPars.cpp \
    MenuDymOpt.cpp MenuDymSim.cpp

OBJECTS=${SRC:.cpp=.o}

## Compile Targets  

build:$(EXE) ../util/libutil.a

builddbg:
	make clean
	make build OPTFLAGS="$(DBFLAGS)" LDFLAGS="$(LDDBFLAGS)"
	mv libmenus.a libmenus-dbg.a

lib:$(OBJECTS)
	ar  rcs  libmenus.a $(OBJECTS)

$(EXE):$(OBJECTS) main.o 
	$(CC) -o $@  main.o $(OBJECTS) $(LDFLAGS)
	make lib


###
# Objects 
#

.cpp.o:
	$(CC) -c $(INC) $(INCPARADISEO) $(OPTFLAGS) $<

../dymsim/StdDymSimSinglton.o:../dymsim/StdDymSimSinglton.cpp \
	                     ../dymsim/StdDymSimSinglton.h
	cd ../dymsim
	make StdDymSimSinglton.o
	cd ../menuslib

# Further Dependencies 

depend:
	makedepend -- $(INC) -- $(SRC)


clean:
	rm -f *.o *.a
# DO NOT DELETE

MenuDymParsVals.o: ../dymsim/StdDymSimSinglton.h ../dymsim/mytypes.h
MenuDymParsVals.o: ../dymsim/ParameterizedDymolaSimulator.h
MenuDymParsVals.o: ../dymsim/DymolaSimulator.h ../dymsim/DsinDescriptor.h
MenuDymParsVals.o: ../util/myconstants.h ../util/myutil.h
MenuDymParsVals.o: /usr/include/regex.h /usr/include/sys/types.h
MenuDymParsVals.o: /usr/include/features.h /usr/include/sys/cdefs.h
MenuDymParsVals.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
MenuDymParsVals.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
MenuDymParsVals.o: /usr/include/bits/typesizes.h /usr/include/time.h
MenuDymParsVals.o: /usr/include/endian.h /usr/include/bits/endian.h
MenuDymParsVals.o: /usr/include/sys/select.h /usr/include/bits/select.h
MenuDymParsVals.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
MenuDymParsVals.o: /usr/include/sys/sysmacros.h
MenuDymParsVals.o: /usr/include/bits/pthreadtypes.h ../dymsim/AbsDymSim.h
MenuDymParsVals.o: ../dymsim/DAESimInterface.h ../util/ShellCommands.h
MenuDymParsVals.o: ../dymsim/DymolaSimulator.cpp ../dymsim/StdDymExe.h
MenuDymParsVals.o: ../dymsim/DymolaExecutor.h ../dymsim/AbsParDymSim.h
MenuDymParsVals.o: ../dymsim/ParameterizedDymolaSimulator.cpp
MenuDymParsVals.o: ../util/SingltonTemplate.h ../util/SingltonTemplate.cpp
MenuDymParsVals.o: MenuDymParsVals.h ../util/MenuExtendedList.h
MenuDymParsVals.o: ../util/Menu.h ../util/FlagInterface.h
MenuDymParsVals.o: ../util/DecisionNode.h ../util/Condition.h
MenuDymParsVals.o: ../util/ListFlag.h ../util/ConfigFlag.h
MenuDymParsVals.o: ../util/ConfigFlag.cpp ../util/ParserSinglton.h
MenuDymParsVals.o: ../util/ListFlag.cpp ../util/MenuExtendedList.cpp
SingMenuExtList.o: SingMenuExtList.h ../util/ListFlag.h ../util/ConfigFlag.h
SingMenuExtList.o: ../util/FlagInterface.h ../util/DecisionNode.h
SingMenuExtList.o: ../util/Condition.h ../util/ConfigFlag.cpp
SingMenuExtList.o: ../util/ParserSinglton.h ../util/SingltonTemplate.h
SingMenuExtList.o: ../util/SingltonTemplate.cpp ../util/ListFlag.cpp
SingMenuExtList.o: ../util/myutil.h /usr/include/regex.h
SingMenuExtList.o: /usr/include/sys/types.h /usr/include/features.h
SingMenuExtList.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
SingMenuExtList.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
SingMenuExtList.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
SingMenuExtList.o: /usr/include/time.h /usr/include/endian.h
SingMenuExtList.o: /usr/include/bits/endian.h /usr/include/sys/select.h
SingMenuExtList.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
SingMenuExtList.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
SingMenuExtList.o: /usr/include/bits/pthreadtypes.h
SingMenuExtList.o: ../util/MenuExtendedList.h ../util/Menu.h
SingMenuExtList.o: ../util/MenuExtendedList.cpp MenuExtListFactory.h
SingMenuExtList.o: ../util/MenuVarsList.h ../util/MenuConstants.h
SingMenuExtList.o: MenuDymParsVals.h SingMenuDymRegPars.h
SingMenuExtList.o: SingMenuDymExpPars.h MenuDymExpPars.h
SingMenuExtList.o: ../flagslib/CommonFlags.h ../flagslib/SingltonFlag.h
SingMenuExtList.o: ../flagslib/SingltonFlag.cpp MenuDymRegPars.h
SingMenuExtList.o: ../util/RegListFlag.h ../util/RegListFlag.cpp
SingMenuExtList.o: ../util/MenuRegList.h
MenuExtListFactory.o: MenuExtListFactory.h SingMenuExtList.h
MenuExtListFactory.o: ../util/ListFlag.h ../util/ConfigFlag.h
MenuExtListFactory.o: ../util/FlagInterface.h ../util/DecisionNode.h
MenuExtListFactory.o: ../util/Condition.h ../util/ConfigFlag.cpp
MenuExtListFactory.o: ../util/ParserSinglton.h ../util/SingltonTemplate.h
MenuExtListFactory.o: ../util/SingltonTemplate.cpp ../util/ListFlag.cpp
MenuExtListFactory.o: ../util/myutil.h /usr/include/regex.h
MenuExtListFactory.o: /usr/include/sys/types.h /usr/include/features.h
MenuExtListFactory.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
MenuExtListFactory.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
MenuExtListFactory.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
MenuExtListFactory.o: /usr/include/time.h /usr/include/endian.h
MenuExtListFactory.o: /usr/include/bits/endian.h /usr/include/sys/select.h
MenuExtListFactory.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
MenuExtListFactory.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
MenuExtListFactory.o: /usr/include/bits/pthreadtypes.h
MenuExtListFactory.o: ../util/MenuExtendedList.h ../util/Menu.h
MenuExtListFactory.o: ../util/MenuExtendedList.cpp SingMenuExtList.cpp
MenuExtListFactory.o: ../util/MenuVarsList.h ../util/MenuConstants.h
MenuExtListFactory.o: MenuDymParsVals.h SingMenuDymRegPars.h
MenuExtListFactory.o: SingMenuDymExpPars.h MenuDymExpPars.h
MenuExtListFactory.o: ../flagslib/CommonFlags.h ../flagslib/SingltonFlag.h
MenuExtListFactory.o: ../flagslib/SingltonFlag.cpp MenuDymRegPars.h
MenuExtListFactory.o: ../util/RegListFlag.h ../util/RegListFlag.cpp
MenuExtListFactory.o: ../util/MenuRegList.h ../util/CondFlgVal.h
MenuExtListFactory.o: ../util/CondOr.h
MenuConfiguration.o: MenuConfiguration.h ../util/Menu.h
MenuConfiguration.o: ../util/FlagInterface.h ../util/DecisionNode.h
MenuConfiguration.o: ../util/Condition.h ../util/MenuConstants.h
MenuConfiguration.o: ../util/BoundedFlag.h ../util/SpecifiedFlag.h
MenuConfiguration.o: ../util/ConfigFlag.h ../util/ConfigFlag.cpp
MenuConfiguration.o: ../util/ParserSinglton.h ../util/SingltonTemplate.h
MenuConfiguration.o: ../util/SingltonTemplate.cpp ../util/SpecifiedFlag.cpp
MenuConfiguration.o: ../util/BoundedFlag.cpp ../util/DiscreteFlag.h
MenuConfiguration.o: ../util/DiscreteFlag.cpp ../flagslib/CommonFlags.h
MenuConfiguration.o: ../flagslib/SingltonFlag.h ../util/ListFlag.h
MenuConfiguration.o: ../util/ListFlag.cpp ../util/myutil.h
MenuConfiguration.o: /usr/include/regex.h /usr/include/sys/types.h
MenuConfiguration.o: /usr/include/features.h /usr/include/sys/cdefs.h
MenuConfiguration.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
MenuConfiguration.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
MenuConfiguration.o: /usr/include/bits/typesizes.h /usr/include/time.h
MenuConfiguration.o: /usr/include/endian.h /usr/include/bits/endian.h
MenuConfiguration.o: /usr/include/sys/select.h /usr/include/bits/select.h
MenuConfiguration.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
MenuConfiguration.o: /usr/include/sys/sysmacros.h
MenuConfiguration.o: /usr/include/bits/pthreadtypes.h
MenuConfiguration.o: ../flagslib/SingltonFlag.cpp ../util/myconstants.h
MenuDymola.o: MenuDymola.h ../util/Menu.h ../util/FlagInterface.h
MenuDymola.o: ../util/DecisionNode.h ../util/Condition.h
MenuDymola.o: ../util/MenuConstants.h ../util/BoundedFlag.h
MenuDymola.o: ../util/SpecifiedFlag.h ../util/ConfigFlag.h
MenuDymola.o: ../util/ConfigFlag.cpp ../util/ParserSinglton.h
MenuDymola.o: ../util/SingltonTemplate.h ../util/SingltonTemplate.cpp
MenuDymola.o: ../util/SpecifiedFlag.cpp ../util/BoundedFlag.cpp
MenuDymola.o: ../util/myconstants.h
MenuLevMar.o: MenuLevMar.h ../util/Menu.h ../util/FlagInterface.h
MenuLevMar.o: ../util/DecisionNode.h ../util/Condition.h
MenuLevMar.o: ../util/MenuConstants.h ../util/BoundedFlag.h
MenuLevMar.o: ../util/SpecifiedFlag.h ../util/ConfigFlag.h
MenuLevMar.o: ../util/ConfigFlag.cpp ../util/ParserSinglton.h
MenuLevMar.o: ../util/SingltonTemplate.h ../util/SingltonTemplate.cpp
MenuLevMar.o: ../util/SpecifiedFlag.cpp ../util/BoundedFlag.cpp
MenuLevMar.o: ../util/DiscreteFlag.h ../util/DiscreteFlag.cpp
MenuLevMar.o: ../flagslib/CommonFlags.h ../flagslib/SingltonFlag.h
MenuLevMar.o: ../util/ListFlag.h ../util/ListFlag.cpp ../util/myutil.h
MenuLevMar.o: /usr/include/regex.h /usr/include/sys/types.h
MenuLevMar.o: /usr/include/features.h /usr/include/sys/cdefs.h
MenuLevMar.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
MenuLevMar.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
MenuLevMar.o: /usr/include/bits/typesizes.h /usr/include/time.h
MenuLevMar.o: /usr/include/endian.h /usr/include/bits/endian.h
MenuLevMar.o: /usr/include/sys/select.h /usr/include/bits/select.h
MenuLevMar.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
MenuLevMar.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
MenuLevMar.o: ../flagslib/SingltonFlag.cpp MenuConfiguration.h
MenuData.o: MenuData.h ../util/Menu.h ../util/FlagInterface.h
MenuData.o: ../util/DecisionNode.h ../util/Condition.h
MenuData.o: ../util/MenuConstants.h ../util/ConfigFlag.h
MenuData.o: ../util/ConfigFlag.cpp ../util/ParserSinglton.h
MenuData.o: ../util/SingltonTemplate.h ../util/SingltonTemplate.cpp
MenuMultiStart.o: MenuMultiStart.h ../util/Menu.h ../util/FlagInterface.h
MenuMultiStart.o: ../util/DecisionNode.h ../util/Condition.h
MenuMultiStart.o: ../util/MenuConstants.h ../util/ConfigFlag.h
MenuMultiStart.o: ../util/ConfigFlag.cpp ../util/ParserSinglton.h
MenuMultiStart.o: ../util/SingltonTemplate.h ../util/SingltonTemplate.cpp
MenuMultiStart.o: ../flagslib/CommonFlags.h ../flagslib/SingltonFlag.h
MenuMultiStart.o: ../util/ListFlag.h ../util/ListFlag.cpp ../util/myutil.h
MenuMultiStart.o: /usr/include/regex.h /usr/include/sys/types.h
MenuMultiStart.o: /usr/include/features.h /usr/include/sys/cdefs.h
MenuMultiStart.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
MenuMultiStart.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
MenuMultiStart.o: /usr/include/bits/typesizes.h /usr/include/time.h
MenuMultiStart.o: /usr/include/endian.h /usr/include/bits/endian.h
MenuMultiStart.o: /usr/include/sys/select.h /usr/include/bits/select.h
MenuMultiStart.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
MenuMultiStart.o: /usr/include/sys/sysmacros.h
MenuMultiStart.o: /usr/include/bits/pthreadtypes.h
MenuMultiStart.o: ../flagslib/SingltonFlag.cpp
MenuMonteCarlo.o: MenuMonteCarlo.h ../util/Menu.h ../util/FlagInterface.h
MenuMonteCarlo.o: ../util/DecisionNode.h ../util/Condition.h
MenuMonteCarlo.o: ../util/MenuConstants.h ../util/ConfigFlag.h
MenuMonteCarlo.o: ../util/ConfigFlag.cpp ../util/ParserSinglton.h
MenuMonteCarlo.o: ../util/SingltonTemplate.h ../util/SingltonTemplate.cpp
SingMenuDymExpVars.o: SingMenuDymExpVars.h ../util/SingltonTemplate.h
SingMenuDymExpVars.o: ../util/SingltonTemplate.cpp ../util/ListFlag.h
SingMenuDymExpVars.o: ../util/ConfigFlag.h ../util/FlagInterface.h
SingMenuDymExpVars.o: ../util/DecisionNode.h ../util/Condition.h
SingMenuDymExpVars.o: ../util/ConfigFlag.cpp ../util/ParserSinglton.h
SingMenuDymExpVars.o: ../util/ListFlag.cpp ../util/myutil.h
SingMenuDymExpVars.o: /usr/include/regex.h /usr/include/sys/types.h
SingMenuDymExpVars.o: /usr/include/features.h /usr/include/sys/cdefs.h
SingMenuDymExpVars.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
SingMenuDymExpVars.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
SingMenuDymExpVars.o: /usr/include/bits/typesizes.h /usr/include/time.h
SingMenuDymExpVars.o: /usr/include/endian.h /usr/include/bits/endian.h
SingMenuDymExpVars.o: /usr/include/sys/select.h /usr/include/bits/select.h
SingMenuDymExpVars.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
SingMenuDymExpVars.o: /usr/include/sys/sysmacros.h
SingMenuDymExpVars.o: /usr/include/bits/pthreadtypes.h MenuDymExpVars.h
SingMenuDymExpVars.o: ../util/MenuVarsList.h ../util/Menu.h
SingMenuDymExpVars.o: ../util/MenuConstants.h
MenuDymExpVars.o: ../dymsim/StdDymSimSinglton.h ../dymsim/mytypes.h
MenuDymExpVars.o: ../dymsim/ParameterizedDymolaSimulator.h
MenuDymExpVars.o: ../dymsim/DymolaSimulator.h ../dymsim/DsinDescriptor.h
MenuDymExpVars.o: ../util/myconstants.h ../util/myutil.h /usr/include/regex.h
MenuDymExpVars.o: /usr/include/sys/types.h /usr/include/features.h
MenuDymExpVars.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
MenuDymExpVars.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
MenuDymExpVars.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
MenuDymExpVars.o: /usr/include/time.h /usr/include/endian.h
MenuDymExpVars.o: /usr/include/bits/endian.h /usr/include/sys/select.h
MenuDymExpVars.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
MenuDymExpVars.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
MenuDymExpVars.o: /usr/include/bits/pthreadtypes.h ../dymsim/AbsDymSim.h
MenuDymExpVars.o: ../dymsim/DAESimInterface.h ../util/ShellCommands.h
MenuDymExpVars.o: ../dymsim/DymolaSimulator.cpp ../dymsim/StdDymExe.h
MenuDymExpVars.o: ../dymsim/DymolaExecutor.h ../dymsim/AbsParDymSim.h
MenuDymExpVars.o: ../dymsim/ParameterizedDymolaSimulator.cpp
MenuDymExpVars.o: ../util/SingltonTemplate.h ../util/SingltonTemplate.cpp
MenuDymExpVars.o: MenuDymExpVars.h ../util/MenuVarsList.h ../util/Menu.h
MenuDymExpVars.o: ../util/FlagInterface.h ../util/DecisionNode.h
MenuDymExpVars.o: ../util/Condition.h ../util/MenuConstants.h
MenuDymExpVars.o: ../util/ListFlag.h ../util/ConfigFlag.h
MenuDymExpVars.o: ../util/ConfigFlag.cpp ../util/ParserSinglton.h
MenuDymExpVars.o: ../util/ListFlag.cpp
SingMenuDymRegVars.o: SingMenuDymRegVars.h ../util/SingltonTemplate.h
SingMenuDymRegVars.o: ../util/SingltonTemplate.cpp SingMenuDymExpVars.h
SingMenuDymRegVars.o: ../util/ListFlag.h ../util/ConfigFlag.h
SingMenuDymRegVars.o: ../util/FlagInterface.h ../util/DecisionNode.h
SingMenuDymRegVars.o: ../util/Condition.h ../util/ConfigFlag.cpp
SingMenuDymRegVars.o: ../util/ParserSinglton.h ../util/ListFlag.cpp
SingMenuDymRegVars.o: ../util/myutil.h /usr/include/regex.h
SingMenuDymRegVars.o: /usr/include/sys/types.h /usr/include/features.h
SingMenuDymRegVars.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
SingMenuDymRegVars.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
SingMenuDymRegVars.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
SingMenuDymRegVars.o: /usr/include/time.h /usr/include/endian.h
SingMenuDymRegVars.o: /usr/include/bits/endian.h /usr/include/sys/select.h
SingMenuDymRegVars.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
SingMenuDymRegVars.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
SingMenuDymRegVars.o: /usr/include/bits/pthreadtypes.h MenuDymExpVars.h
SingMenuDymRegVars.o: ../util/MenuVarsList.h ../util/Menu.h
SingMenuDymRegVars.o: ../util/MenuConstants.h MenuDymRegVars.h
SingMenuDymRegVars.o: ../util/RegListFlag.h ../util/RegListFlag.cpp
SingMenuDymRegVars.o: ../util/MenuRegList.h
SingMenuDymExpPars.o: SingMenuDymExpPars.h ../util/SingltonTemplate.h
SingMenuDymExpPars.o: ../util/SingltonTemplate.cpp ../util/ListFlag.h
SingMenuDymExpPars.o: ../util/ConfigFlag.h ../util/FlagInterface.h
SingMenuDymExpPars.o: ../util/DecisionNode.h ../util/Condition.h
SingMenuDymExpPars.o: ../util/ConfigFlag.cpp ../util/ParserSinglton.h
SingMenuDymExpPars.o: ../util/ListFlag.cpp ../util/myutil.h
SingMenuDymExpPars.o: /usr/include/regex.h /usr/include/sys/types.h
SingMenuDymExpPars.o: /usr/include/features.h /usr/include/sys/cdefs.h
SingMenuDymExpPars.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
SingMenuDymExpPars.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
SingMenuDymExpPars.o: /usr/include/bits/typesizes.h /usr/include/time.h
SingMenuDymExpPars.o: /usr/include/endian.h /usr/include/bits/endian.h
SingMenuDymExpPars.o: /usr/include/sys/select.h /usr/include/bits/select.h
SingMenuDymExpPars.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
SingMenuDymExpPars.o: /usr/include/sys/sysmacros.h
SingMenuDymExpPars.o: /usr/include/bits/pthreadtypes.h MenuDymExpPars.h
SingMenuDymExpPars.o: ../util/MenuVarsList.h ../util/Menu.h
SingMenuDymExpPars.o: ../util/MenuConstants.h ../flagslib/CommonFlags.h
SingMenuDymExpPars.o: ../flagslib/SingltonFlag.h ../flagslib/SingltonFlag.cpp
MenuDymExpPars.o: ../dymsim/StdDymSimSinglton.h ../dymsim/mytypes.h
MenuDymExpPars.o: ../dymsim/ParameterizedDymolaSimulator.h
MenuDymExpPars.o: ../dymsim/DymolaSimulator.h ../dymsim/DsinDescriptor.h
MenuDymExpPars.o: ../util/myconstants.h ../util/myutil.h /usr/include/regex.h
MenuDymExpPars.o: /usr/include/sys/types.h /usr/include/features.h
MenuDymExpPars.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
MenuDymExpPars.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
MenuDymExpPars.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
MenuDymExpPars.o: /usr/include/time.h /usr/include/endian.h
MenuDymExpPars.o: /usr/include/bits/endian.h /usr/include/sys/select.h
MenuDymExpPars.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
MenuDymExpPars.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
MenuDymExpPars.o: /usr/include/bits/pthreadtypes.h ../dymsim/AbsDymSim.h
MenuDymExpPars.o: ../dymsim/DAESimInterface.h ../util/ShellCommands.h
MenuDymExpPars.o: ../dymsim/DymolaSimulator.cpp ../dymsim/StdDymExe.h
MenuDymExpPars.o: ../dymsim/DymolaExecutor.h ../dymsim/AbsParDymSim.h
MenuDymExpPars.o: ../dymsim/ParameterizedDymolaSimulator.cpp
MenuDymExpPars.o: ../util/SingltonTemplate.h ../util/SingltonTemplate.cpp
MenuDymExpPars.o: MenuDymExpPars.h ../util/MenuVarsList.h ../util/Menu.h
MenuDymExpPars.o: ../util/FlagInterface.h ../util/DecisionNode.h
MenuDymExpPars.o: ../util/Condition.h ../util/MenuConstants.h
MenuDymExpPars.o: ../util/ListFlag.h ../util/ConfigFlag.h
MenuDymExpPars.o: ../util/ConfigFlag.cpp ../util/ParserSinglton.h
MenuDymExpPars.o: ../util/ListFlag.cpp
SingMenuDymRegPars.o: SingMenuDymRegPars.h ../util/SingltonTemplate.h
SingMenuDymRegPars.o: ../util/SingltonTemplate.cpp SingMenuDymExpPars.h
SingMenuDymRegPars.o: ../util/ListFlag.h ../util/ConfigFlag.h
SingMenuDymRegPars.o: ../util/FlagInterface.h ../util/DecisionNode.h
SingMenuDymRegPars.o: ../util/Condition.h ../util/ConfigFlag.cpp
SingMenuDymRegPars.o: ../util/ParserSinglton.h ../util/ListFlag.cpp
SingMenuDymRegPars.o: ../util/myutil.h /usr/include/regex.h
SingMenuDymRegPars.o: /usr/include/sys/types.h /usr/include/features.h
SingMenuDymRegPars.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
SingMenuDymRegPars.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
SingMenuDymRegPars.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
SingMenuDymRegPars.o: /usr/include/time.h /usr/include/endian.h
SingMenuDymRegPars.o: /usr/include/bits/endian.h /usr/include/sys/select.h
SingMenuDymRegPars.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
SingMenuDymRegPars.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
SingMenuDymRegPars.o: /usr/include/bits/pthreadtypes.h MenuDymExpPars.h
SingMenuDymRegPars.o: ../util/MenuVarsList.h ../util/Menu.h
SingMenuDymRegPars.o: ../util/MenuConstants.h ../flagslib/CommonFlags.h
SingMenuDymRegPars.o: ../flagslib/SingltonFlag.h ../flagslib/SingltonFlag.cpp
SingMenuDymRegPars.o: MenuDymRegPars.h ../util/RegListFlag.h
SingMenuDymRegPars.o: ../util/RegListFlag.cpp ../util/MenuRegList.h
MenuDymOpt.o: MenuDymOpt.h ../util/Menu.h ../util/FlagInterface.h
MenuDymOpt.o: ../util/DecisionNode.h ../util/Condition.h MenuConfiguration.h
MenuDymOpt.o: ../util/MenuConstants.h ../util/BoundedFlag.h
MenuDymOpt.o: ../util/SpecifiedFlag.h ../util/ConfigFlag.h
MenuDymOpt.o: ../util/ConfigFlag.cpp ../util/ParserSinglton.h
MenuDymOpt.o: ../util/SingltonTemplate.h ../util/SingltonTemplate.cpp
MenuDymOpt.o: ../util/SpecifiedFlag.cpp ../util/BoundedFlag.cpp
MenuDymOpt.o: ../util/DiscreteFlag.h ../util/DiscreteFlag.cpp
MenuDymOpt.o: ../flagslib/CommonFlags.h ../flagslib/SingltonFlag.h
MenuDymOpt.o: ../util/ListFlag.h ../util/ListFlag.cpp ../util/myutil.h
MenuDymOpt.o: /usr/include/regex.h /usr/include/sys/types.h
MenuDymOpt.o: /usr/include/features.h /usr/include/sys/cdefs.h
MenuDymOpt.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
MenuDymOpt.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
MenuDymOpt.o: /usr/include/bits/typesizes.h /usr/include/time.h
MenuDymOpt.o: /usr/include/endian.h /usr/include/bits/endian.h
MenuDymOpt.o: /usr/include/sys/select.h /usr/include/bits/select.h
MenuDymOpt.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
MenuDymOpt.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
MenuDymOpt.o: ../flagslib/SingltonFlag.cpp MenuDymola.h MenuLevMar.h
MenuDymOpt.o: MenuData.h MenuMultiStart.h MenuMonteCarlo.h
MenuDymOpt.o: SingMenuDymRegVars.h SingMenuDymExpVars.h MenuDymExpVars.h
MenuDymOpt.o: ../util/MenuVarsList.h MenuDymRegVars.h ../util/RegListFlag.h
MenuDymOpt.o: ../util/RegListFlag.cpp ../util/MenuRegList.h
MenuDymOpt.o: SingMenuDymRegPars.h SingMenuDymExpPars.h MenuDymExpPars.h
MenuDymOpt.o: MenuDymRegPars.h SingMenuExtList.h ../util/MenuExtendedList.h
MenuDymOpt.o: ../util/MenuExtendedList.cpp SingMenuExtList.cpp
MenuDymOpt.o: MenuDymParsVals.h MenuExtListFactory.h ../util/CondDyn.h
MenuDymOpt.o: ../util/MenuRegExtList.h ../util/MenuRegExtList.cpp
MenuDymOpt.o: ../util/CondFlgVal.h ../util/CondOr.h
MenuDymSim.o: MenuDymSim.h ../util/Menu.h ../util/FlagInterface.h
MenuDymSim.o: ../util/DecisionNode.h ../util/Condition.h MenuConfiguration.h
MenuDymSim.o: ../util/MenuConstants.h ../util/BoundedFlag.h
MenuDymSim.o: ../util/SpecifiedFlag.h ../util/ConfigFlag.h
MenuDymSim.o: ../util/ConfigFlag.cpp ../util/ParserSinglton.h
MenuDymSim.o: ../util/SingltonTemplate.h ../util/SingltonTemplate.cpp
MenuDymSim.o: ../util/SpecifiedFlag.cpp ../util/BoundedFlag.cpp
MenuDymSim.o: ../util/DiscreteFlag.h ../util/DiscreteFlag.cpp
MenuDymSim.o: ../flagslib/CommonFlags.h ../flagslib/SingltonFlag.h
MenuDymSim.o: ../util/ListFlag.h ../util/ListFlag.cpp ../util/myutil.h
MenuDymSim.o: /usr/include/regex.h /usr/include/sys/types.h
MenuDymSim.o: /usr/include/features.h /usr/include/sys/cdefs.h
MenuDymSim.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
MenuDymSim.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
MenuDymSim.o: /usr/include/bits/typesizes.h /usr/include/time.h
MenuDymSim.o: /usr/include/endian.h /usr/include/bits/endian.h
MenuDymSim.o: /usr/include/sys/select.h /usr/include/bits/select.h
MenuDymSim.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
MenuDymSim.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
MenuDymSim.o: ../flagslib/SingltonFlag.cpp MenuDymola.h SingMenuDymRegVars.h
MenuDymSim.o: SingMenuDymExpVars.h MenuDymExpVars.h ../util/MenuVarsList.h
MenuDymSim.o: MenuDymRegVars.h ../util/RegListFlag.h ../util/RegListFlag.cpp
MenuDymSim.o: ../util/MenuRegList.h SingMenuDymRegPars.h SingMenuDymExpPars.h
MenuDymSim.o: MenuDymExpPars.h MenuDymRegPars.h SingMenuExtList.h
MenuDymSim.o: ../util/MenuExtendedList.h ../util/MenuExtendedList.cpp
MenuDymSim.o: SingMenuExtList.cpp MenuDymParsVals.h MenuExtListFactory.h
MenuDymSim.o: ../util/CondDyn.h ../util/MenuRegExtList.h
MenuDymSim.o: ../util/MenuRegExtList.cpp ../util/CondFlgVal.h
MenuDymSim.o: ../util/CondOr.h
