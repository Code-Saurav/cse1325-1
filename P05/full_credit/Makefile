CXXFLAGS = --std=c++17

all: main 

main: main.o data.o gate.o *.h
	$(CXX) $(CXXFLAGS) main.o data.o gate.o -o main
	@echo "./main to run the program. Happy coding :)"

main.o:  main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o 

data.o: data.cpp *.h
	$(CXX) $(CXXFLAGS) -c data.cpp -o data.o

gate.o: gate.cpp *.h 	
	$(CXX) $(CXXFLAGS) -c gate.cpp -o gate.o

clean:
	rm -f *.gch *.o main

