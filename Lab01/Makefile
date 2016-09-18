Lab01: main.o Pokemon.o Colosseum.o Dice.o
	g++ -g -Wall main.o Pokemon.o Colosseum.o Dice.o -o Lab01

main.o: main.cpp Pokemon.h Colosseum.h Dice.h
	g++ -g -Wall -c main.cpp

Pokemon.o: Pokemon.h Pokemon.cpp
	g++ -g -Wall -c Pokemon.cpp

Colosseum.o: Colosseum.h Colosseum.cpp Pokemon.h Dice.h
	g++ -g -Wall -c Colosseum.cpp

Dice.o: Dice.h Dice.cpp
	g++ -g -Wall -c Dice.cpp

clean:
	rm *.o Lab01
