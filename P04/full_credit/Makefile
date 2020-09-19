CXXFLAGS = --std=c++17

all: main
main: main.o modulo.o *.h
	$(CXX) $(CXXFLAGS) main.o modulo.o -o main
	@echo "./main to run the program: Happy Coding"

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

modulo.o: modulo.cpp *.h
	$(CXX) $(CXXFLAGS) -c modulo.cpp -o modulo.o

modulo: modulo.h
	$(CXX) $(CXXFLAGS) -c modulo.h -o modulo.gch

clean:
	rm -f *.o *.gch ~* a.out main
	