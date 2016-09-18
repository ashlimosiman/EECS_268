Lab07: main.o Knight.o
	g++ -g -std=c++11 -Wall main.o Knight.o -o Lab07

main.o: main.cpp Knight.h
	g++ -g -std=c++11 -Wall -c main.cpp

Knight.o: Knight.cpp Knight.h
	g++ -g -std=c++11 -Wall -c Knight.cpp

clean:
	rm *.o Lab07
