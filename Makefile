# Makefile for "Test Case Generator" C++ application
# Created by C Shriram : 21-04-20

CXX = g++
PROG = TCG
CXXFLAGS = -std=c++17 -Wall -g
OBJS = numOp.o Invalid.o Timer.o FileOp.o Distribution.o IntTypes.o FloatTypes.o ArrayTypes.o FarrayTypes.o SarrayTypes.o Perm.o String.o chStringTypes.o spString.o IntervalTypes.o MatrixTypes.o FmatrixTypes.o TreeTypes.o DenseGraph.o GraphTypes.o DigraphTypes.o Coordinates.o Polynomial.o Tuple.o ParamArray.o Generator.o main.o
HEADER2 = numOp.h Invalid.h Timer.h FileOp.h Distribution.h IntTypes.h FloatTypes.h ArrayTypes.h FarrayTypes.h SarrayTypes.h Perm.h String.h chStringTypes.h spString.h IntervalTypes.h MatrixTypes.h FmatrixTypes.h TreeTypes.h DenseGraph.h GraphTypes.h DigraphTypes.h Coordinates.h Polynomial.h Tuple.h ParamArray.h Generator.h
HEADER1 = numOp.h Invalid.h Timer.h FileOp.h Distribution.h

$(PROG) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(PROG) $(OBJS)

numOp.o : numOp.h
	$(CXX) $(CXXFLAGS) -c numOp.cpp

Invalid.o : Invalid.h
	$(CXX) $(CXXFLAGS) -c Invalid.cpp

Timer.o : Timer.h
	$(CXX) $(CXXFLAGS) -c Timer.cpp

FileOp.o : numOp.h FileOp.h
	$(CXX) $(CXXFLAGS) -c FileOp.cpp

Distribution.o : Distribution.h
	$(CXX) $(CXXFLAGS) -c Distribution.cpp

IntTypes.o : $(HEADER1) IntTypes.h
	$(CXX) $(CXXFLAGS) -c IntTypes.cpp

FloatTypes.o : $(HEADER1) IntTypes.cpp
	$(CXX) $(CXXFLAGS) -c FloatTypes.cpp

ArrayTypes.o : $(HEADER1) ArrayTypes.h
	$(CXX) $(CXXFLAGS) -c ArrayTypes.cpp

FarrayTypes.o : $(HEADER1) FarrayTypes.h
	$(CXX) $(CXXFLAGS) -c FarrayTypes.cpp

SarrayTypes.o : $(HEADER1) SarrayTypes.h
	$(CXX) $(CXXFLAGS) -c SarrayTypes.cpp

Perm.o : $(HEADER1) Perm.h
	$(CXX) $(CXXFLAGS) -c Perm.cpp

String.o : $(HEADER1) String.h
	$(CXX) $(CXXFLAGS) -c String.cpp

chStringTypes.o : $(HEADER1) chStringTypes.h
	$(CXX) $(CXXFLAGS) -c chStringTypes.cpp

spString.o : $(HEADER1) spString.h
	$(CXX) $(CXXFLAGS) -c spString.cpp

IntervalTypes.o : $(HEADER1) IntervalTypes.h
	$(CXX) $(CXXFLAGS) -c IntervalTypes.cpp

MatrixTypes.o : $(HEADER1) MatrixTypes.h
	$(CXX) $(CXXFLAGS) -c MatrixTypes.cpp

FmatrixTypes.o : $(HEADER1) FmatrixTypes.h
	$(CXX) $(CXXFLAGS) -c FmatrixTypes.cpp

TreeTypes.o : $(HEADER1) TreeTypes.h
	$(CXX) $(CXXFLAGS) -c TreeTypes.cpp

DenseGraph.o : $(HEADER1) DenseGraph.h
	$(CXX) $(CXXFLAGS) -c DenseGraph.cpp

GraphTypes.o : $(HEADER1) GraphTypes.h
	$(CXX) $(CXXFLAGS) -c GraphTypes.cpp

DigraphTypes.o : $(HEADER1) DigraphTypes.h
	$(CXX) $(CXXFLAGS) -c DigraphTypes.cpp

Coordinates.o : $(HEADER1) Coordinates.h
	$(CXX) $(CXXFLAGS) -c Coordinates.cpp

Polynomial.o : $(HEADER1) Polynomial.h
	$(CXX) $(CXXFLAGS) -c Polynomial.cpp

Tuple.o : $(HEADER1) Tuple.h
	$(CXX) $(CXXFLAGS) -c Tuple.cpp

ParamArray.o : $(HEADER1) ParamArray.h
	$(CXX) $(CXXFLAGS) -c ParamArray.cpp

Generator.o : $(HEADER2)
	$(CXX) $(CXXFLAGS) -c Generator.cpp

main.o : $(HEADER2)
	$(CXX) $(CXXFLAGS) -c main.cpp

.PHONY : clean
clean :
	-rm $(OBJS) $(PROG)

