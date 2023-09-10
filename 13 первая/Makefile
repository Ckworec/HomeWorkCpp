all: CComplexVector

CComplexVector: CComplexVector.o main.cpp
	g++ -o CComplexVector CComplexVector.o main.o

CComplexVector.o: CComplexVector.cpp CComplexVector.h
	g++ -c CComplexVector.cpp

main.o: main.cpp
	g++ -c main.cpp