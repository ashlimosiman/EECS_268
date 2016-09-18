Lab02: main.o Executive.o DriversLicenseRecord.o
	g++ -g -Wall main.o Executive.o DriversLicenseRecord.o -o Lab02

main.o: main.cpp Executive.h DriversLicenseRecord.h
	g++ -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp DriversLicenseRecord.h
	g++ -g -Wall -c Executive.cpp

DriversLicenseRecord.o: DriversLicenseRecord.h DriversLicenseRecord.cpp
	g++ -g -Wall -c DriversLicenseRecord.cpp

clean:
	rm *.o Lab02
