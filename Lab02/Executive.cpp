/**
 *File: Executive.cpp
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: February 7,2016
 *Purpose: creates an array of DriversLicenseRecord objects to store each line in each object.
 *	 It will then print out the options and take in the choice and requested info.
 *	 As well as compare the requested info to each object.
**/
#include "Executive.h"

Executive::Executive(std::string filename)
{
	//Establishing necessary variables
	std::string fName;
	std::string lName;
	int age;
	char vote;
	int licenseNum;

	//opening the provided file
	info.open(filename.c_str());

	//reading the first line for the array size
	info>>numRecords;
	//making records as a new array set to the size gotten from the file
	records = new DriversLicenseRecord[numRecords];

	//using a for loop to fill in the established array and move to the next spot in the array
	for(int x=0; x<numRecords; x++)
	{
		//reading the first name, last name, age, registered or not, and license number in that order from the current line
		info >> fName >> lName >> age >> vote >> licenseNum;
		//putting the received information into the current array spot
		records[x]=DriversLicenseRecord(fName, lName, age, vote, licenseNum);
	}

	//closing the file
	info.close();
}

Executive::~Executive()
{
	//deleting the heap-allocated array
	delete[] records;
}

void Executive::run()
{
	//Establishing necessary variables
	int choice=0;
	std::string ln="";
	int max=0;
	int min=0;
	char rVote=' ';

	//keeps the program going until the user picks 4 to quit
	while(choice != 4)
	{
		//printing out options for the user to choose from
		std::cout<<"What would you like to do?"<<'\n'
			<<"1: Query Last Name"<<'\n'
			<<"2: Query Age Range"<<'\n'
			<<"3: Query Registered Voters"<<'\n'
			<<"4: Quit"<<'\n';
		//taking in a choice fro the user
		std::cin>>choice;
		//Query last name
		if(choice == 1)
		{
			//asking for a last name and takes one in. Then runs the queryLastName method with the received name
			std::cout<<"Enter The Last Name: "<<'\n';
			std::cin>>ln;
			queryLastName(ln, records);
		}
		//Query age range
		else if(choice == 2)
		{
			//asking for a valid age range and takes each number in seperately. Then runs queryAgeRange with the received numbers
			std::cout<<"Enter The Minimum Age: "<<'\n';
			std::cin>>min;
			std::cout<<"Enter The Maximum Age: "<<'\n';
			std::cin>>max;
			queryAgeRange(min, max, records);
		}
		//Query registered voters
		else if(choice == 3)
		{
			//asking if the user wants the registered voters or not registered, using capital Y or N. Takes their option in.
			//runs the queryRegistered method with the character
			std::cout<<"Would you like Registered or Not Registered voters? (Y/N): "<<'\n';
			std::cin>>rVote;
			queryRegistered(rVote, records);

		}
		else if(choice != 4)
		{
			//prints out an error message if they put something other than 1,2,3, or 4.
			//Along with clears and ignores the invalid entry
			std::cout<<"Sorry. That's not an option. Please choose 1, 2, 3, or 4."<<'\n'<<'\n';
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		}
	}
	//prints out thank you message after the user quits the program
	std::cout<<'\n'<<"Thanks for using our system!"<<'\n'<<"Bye."<<'\n';
}

void Executive::queryLastName(std::string name, DriversLicenseRecord *records)
{
	bool found = false;

	//runs through the array comparing the received last name to each entry
	for(int x=0; x<numRecords; x++)
	{
		if(records[x].getLast() == name)
		{
			records[x].print();
			//changes the value of found if at least one entry matches the last name
			found = true;
		}
	}

	//prints out an error message if the given last name didn't match any of the entries
	if(found == false)
	{
		std::cout<< name <<" was not found in our data."<<'\n';
	}
}

void Executive::queryAgeRange(int min, int max, DriversLicenseRecord *records)
{
	//checks if the user put correct values, in this case, if the min is less than the max or not
	if(min > max)
	{
		//prints out error message of min is greater than max
		std::cout<<"The age range is invalid. Please check you enter the ages in the correct corresponding spots."<<'\n';
	}
	//if valid values given, checks the array for corresponding entries
	else
	{
		bool found = false;

		//running through the array finding the ages of the entries within the range given
		for(int x=0; x<numRecords; x++)
		{
			if(records[x].getAge() >= min && records[x].getAge() <= max)
			{
				records[x].print();
				//changing found to true if at least one person is found
				found = true;
			}
		}

		//prints out an error message if no one within the age range was found
		if(found == false)
		{
			std::cout<<"Apologies. No data was found for anybody within that age range."<<'\n';
		}
	}
}

void Executive::queryRegistered(char vote, DriversLicenseRecord *records)
{
	//changes the lowercase y or n to an uppercase Y or N, so the character can still be valid
	if(vote == 'y')
	{
		vote = 'Y';
	}
	else if(vote == 'n')
	{
		vote = 'N';
	}

	//checking if the user put a valid character. If not, prints out an error message.
	if(vote != 'Y' && vote != 'N')
	{
		std::cout<<"That was not an option. Please put Y or N."<<'\n';
	}

	//runs through the array printing out all corresponding registered voters or not registered voters
	for(int x=0; x<numRecords; x++)
	{
		if(records[x].getVote() == vote)
		{
			records[x].print();
		}
	}
}
