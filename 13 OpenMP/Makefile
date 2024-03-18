all: main.o CComplexVector.o CComplexNumber.o
	g++ -o a.out -fopenmp main.o CComplexVector.o CComplexNumber.o

main.o: main.cpp
	g++ -c -O3 -fopenmp main.cpp

CComplexVector.o: CComplexVector.cpp
	g++ -c -O3 -fopenmp CComplexVector.cpp
	
CComplexNumber.o: CComplexNumber.cpp
	g++ -c -O3 -fopenmp CComplexNumber.cpp

clean:
	rm -f a.out main.o CComplexVector.o CComplexNumber.o vgcore* out*.txt