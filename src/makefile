################################################################################
#	File: 	makefile
#	Author:	Kelley Neubauer
#	Date:	11/13/2019
#
#	Description:
#	This is a makefile for Bigger or Better.
#
#	Elements of this code have been adapted from:
#	- 	Title: OSU CS 162 makefile lecture
#		Author: Instructor
#		Date: Unknown  
#		Availability: https://oregonstate.instructure.com/courses/
#	
#	- 	Title: intermediate_make_sample
#		Author: Harlan James
#		Date: Unknown  
#		Availability: https://oregonstate.instructure.com/courses/
################################################################################

#
# Compiler
#
CXX = g++

#
# Compiler Flags
#
CXXFLAGS = -std=c++11 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
#LDFLAGS = -lboost_date_time

#
# Project Name
#
PROJ = biggerOrBetter

#
# Source Files
#
# SRC += 
SRC  = biggerOrBetterMain.cpp 
SRC += inputValidation.cpp
SRC += Menu.cpp
SRC += utilityFunctions.cpp
SRC += Game.cpp
SRC += Graphics.cpp
SRC += Space.cpp
SRC += SpaceHouse.cpp
SRC += SpaceHome.cpp
SRC += SpaceItem.cpp
SRC += SpaceStreet.cpp
SRC += Player.cpp


#
# Header Files
#
# HEADER +=
HEADER += inputValidation.hpp
HEADER += Menu.hpp
HEADER += utilityFunctions.hpp
HEADER += Game.hpp
HEADER += Graphics.hpp
HEADER += Space.hpp
HEADER += SpaceHouse.hpp
HEADER += SpaceHome.hpp
HEADER += SpaceItem.hpp
HEADER += SpaceStreet.hpp
HEADER += Player.hpp


#
# Object Files
#
# OBJ +=  
OBJ  = biggerOrBetterMain.o 
OBJ += inputValidation.o
OBJ += Menu.o
OBJ += utilityFunctions.o
OBJ += Game.o
OBJ += Graphics.o
OBJ += Space.o
OBJ += SpaceHouse.o
OBJ += SpaceHome.o
OBJ += SpaceItem.o
OBJ += SpaceStreet.o
OBJ += Player.o


#
# Create Executable File
#
${PROJ}: ${OBJ} ${HEADER}
	${CXX} ${LDFLAGS} ${OBJ} -o ${PROJ}

#
# Create Object Files
#
${OBJ}: ${SRC}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o ${PROJ}



#
#SIMPLE TEST MAKE BELOW
#

#output: main.o readMatrix.o determinant.o
#	g++ main.o readMatrix.o determinant.o -o lab1

#main.o: main.cpp
#	g++ -c main.cpp

#readMatrix.o: readMatrix.cpp readMatrix.hpp
#	g++ -c readMatrix.cpp

#determinant.o: determinant.cpp determinant.hpp
#	g++ -c determinant.cpp

#clean:
#	rm *.o lab1