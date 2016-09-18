Lab03: main.o LinkedList.o Node.o Test.o Test_LinkedList.o
	g++ -g -std=c++11 -Wall main.o LinkedList.o Node.o Test.o Test_LinkedList.o -o Lab03

main.o: main.cpp Node.h LinkedList.h Test.h Test_LinkedList.h
	g++ -g -std=c++11 -Wall -c main.cpp

LinkedList.o: LinkedList.h LinkedList.cpp Node.h
	g++ -g -std=c++11 -Wall -c LinkedList.cpp

Node.o: Node.h Node.cpp
	g++ -g -std=c++11 -Wall -c Node.cpp

Test.o: Test.h Test.cpp
	g++ -g -std=c++11 -Wall -c Test.cpp

Test_LinkedList.o: Test_LinkedList.h Test_LinkedList.cpp Test.h LinkedList.h
	g++ -g -std=c++11 -Wall -c Test_LinkedList.cpp

clean:
	rm *.o Lab03
