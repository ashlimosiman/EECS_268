Lab06: main.o PrecondViolatedExcep.o
	g++ -g -std=c++11 -Wall main.o PrecondViolatedExcep.o -o Lab06

main.o: main.cpp Node.h Node.hpp StackInterface.h Stack.h Stack.hpp PrecondViolatedExcep.h
	g++ -g -std=c++11 -Wall -c main.cpp


PrecondViolatedExcep.o: PrecondViolatedExcep.h PrecondViolatedExcep.cpp
	g++ -g -std=c++11 -Wall -c PrecondViolatedExcep.cpp

clean:
	rm *.o Lab06
