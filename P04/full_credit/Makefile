CXXFLAGS = --std=c++17

all: main
main: main.o
	$(CXX) $(CXXFLAGS) main.o -o main
	@echo "./main to run the program: Happy Coding"

main.o: main.cpp 
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

match: modulo.h
	$(CXX) $(CXXFLAGS) -c modulo.h -o modulo.gch


clean:
	rm -f *.o *.gch ~* a.out main
