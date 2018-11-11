CXX = g++

main: main.cpp round_robin.o
	$(CXX) -o main main.cpp round_robin.o process.o

process.o: process.cpp process.h
	$(CXX) -c process.cpp

round_robin.o: round_robin.cpp round_robin.h process.o
	$(CXX) -c round_robin.cpp

clean:
	rm *.o main	
