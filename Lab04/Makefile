Lab04: main.o PreconditionViolationException.o Test.o Test_Stack.o
	g++ -g -std=c++11 -Wall main.o PreconditionViolationException.o Test.o Test_Stack.o -o Lab04

main.o: main.cpp StackInterface.h Node.h Node.hpp Stack.h Stack.hpp PreconditionViolationException.h Test_Stack.h Test.h
	g++ -g -std=c++11 -Wall -c main.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -Wall -c PreconditionViolationException.cpp

Test.o: Test.h Test.cpp
	g++ -g -std=c++11 -Wall -c Test.cpp

Test_Stack.o: Test_Stack.h Test_Stack.cpp Test.h
	g++ -g -std=c++11 -Wall -c Test_Stack.cpp
clean:
	rm *.o Lab04
