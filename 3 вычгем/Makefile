WALLFLAG = -Wall

all: main.o func.o
	g++ main.o func.o

main.o: main.cpp
	g++ -c $(WALLFLAG) main.cpp

func.o: func.cpp
	g++ -c $(WALLFLAG) func.cpp

clean:
	rm -rf *.o