CXXFLAGS = --std=c++17

all: main
main: main.o board.o tile.o *.h
	$(CXX) $(CXXFLAGS) main.o board.o tile.o -o main
	@echo "./main to run the program: Happy Coding"

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

board.o: board.cpp *.h
	$(CXX) $(CXXFLAGS) -c board.cpp -o board.o

tile.o: tile.cpp *.h
	$(CXX) $(CXXFLAGS) -c tile.cpp -o tile.o

match: match.h
	$(CXX) $(CXXFLAGS) -c match.h -o match.gch

clean:
	rm -f *.o *.gch ~* a.out main
	