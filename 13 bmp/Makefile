all: main.o Image.o
	g++ main.o Image.o

main.o: main.cpp
	g++ -c main.cpp

Image.o: Image.cpp
	g++ -c Image.cpp

clean:
	rm -f *.o *.out *.exe