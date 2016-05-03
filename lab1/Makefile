CPP=g++ -std=c++11
run: main.cpp EightPuzzle.o 
	${CPP} -o run main.cpp EightPuzzle.o 
EightPuzzle: EightPuzzle.hpp 
	${CPP} -c EightPuzzle.cpp
clean:
	rm *.o
