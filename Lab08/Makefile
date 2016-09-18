Lab08: main.o FileReader.o Translator.o PreconditionViolationException.o
	g++ -g -std=c++11 -Wall main.o FileReader.o Translator.o PreconditionViolationException.o -o Lab08

main.o: main.cpp FileReader.h Translator.h PreconditionViolationException.h
	g++ -g -std=c++11 -Wall -c main.cpp

FileReader.o: FileReader.cpp FileReader.h PreconditionViolationException.h
	g++ -g -std=c++11 -Wall -c FileReader.cpp

Translator.o: Translator.cpp Translator.h
		g++ -g -std=c++11 -Wall -c Translator.cpp

PreconditionViolationException.o: PreconditionViolationException.cpp PreconditionViolationException.h
		g++ -g -std=c++11 -Wall -c PreconditionViolationException.cpp

clean:
	rm *.o Lab08
