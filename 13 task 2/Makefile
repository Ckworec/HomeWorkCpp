WALLFLAG = -Wall

all: main.o Table_Element.o
	g++ main.o Table_Element.o

main.o: main.cpp
	g++ -c $(WALLFLAG) main.cpp

Table_Element.o: Table_Element.cpp
	g++ -c $(WALLFLAG) Table_Element.cpp

clean:
	rm *.o
