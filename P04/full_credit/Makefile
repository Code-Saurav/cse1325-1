CXXFLAGS = --std=c++17

all: modulo modulo2

modulo: main.o modulo.o *.h
	$(CXX) $(CXXFLAGS) main.o modulo.o -o modulo
	@echo "./modulo to run the main cpp program: Happy Coding"

modulo2: main2.o modulo.o *.h
	$(CXX) $(CXXFLAGS) main2.o modulo.o -o modulo2
	@echo "./modulo2 to run the main2 cpp program: Happy Coding"

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

main2.o: main2.cpp *.h
	$(CXX) $(CXXFLAGS) -c main2.cpp -o main2.o

modulo.o: modulo.cpp *.h
	$(CXX) $(CXXFLAGS) -c modulo.cpp -o modulo.o

moduloHeader: modulo.h
	$(CXX) $(CXXFLAGS) -c modulo.h -o modulo.gch

clean:
	rm -f *.o *.gch ~* a.out modulo modulo2
	