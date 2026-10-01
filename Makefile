CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

all: main

main: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main

clean:
	rm -f main *.o

.PHONY: clean