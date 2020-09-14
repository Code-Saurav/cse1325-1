CXXFLAGS= --std=c++17
all: main
main: main.o
	$(CXX) $(CXXFLAGS) main.o -o main
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm -f *.o *.gch ~* a.out main