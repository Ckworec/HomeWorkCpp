all: main.o CComplexVector.o CComplexNumber.o
	g++ -o a.out main.o CComplexVector.o CComplexNumber.o

main.o: main.cpp
	g++ -c main.cpp

CComplexVector.o: CComplexVector.cpp
	g++ -c CComplexVector.cpp
	
CComplexNumber.o: CComplexNumber.cpp
	g++ -c CComplexNumber.cpp

clean:
	rm -f a.out main.o CComplexVector.o CComplexNumber.o vgcore* out*.txt