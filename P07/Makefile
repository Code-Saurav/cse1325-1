CXXFLAGS = --std=c++17
GTXFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: manga

debug: CXXFLAGS += -g
debug: manga

main: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp $(GTXFLAGS) -o main

manga: cli.o store.o product.o plant.o tool.o mulch.o *.h
	$(CXX) $(CXXFLAGS) cli.o store.o product.o plant.o tool.o mulch.o -o manga
cli.o: cli.cpp *.h
	$(CXX) $(CXXFLAGS) -c cli.cpp -o cli.o
store.o: store.cpp *.h
	$(CXX) $(CXXFLAGS) -c store.cpp -o store.o
product.o: product.cpp *.h
	$(CXX) $(CXXFLAGS) -c product.cpp -o product.o
plant.o: plant.cpp *.h
	$(CXX) $(CXXFLAGS) -c plant.cpp -o plant.o
tool.o: tool.cpp *.h
	$(CXX) $(CXXFLAGS) -c tool.cpp -o tool.o
mulch.o: mulch.cpp *.h
	$(CXX) $(CXXFLAGS) -c mulch.cpp -o mulch.o

clean:
	rm -f *.o *.gch ~* a.out manga main

