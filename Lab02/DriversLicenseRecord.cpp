/**
 *File: DriversLicenseRecord.cpp
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: February 7,2016
 *Purpose: Creates an object, so the array of DriverLicenseRecord in Executive class can store each line from the provided file in each object.
**/
#include "DriversLicenseRecord.h"
DriversLicenseRecord::DriversLicenseRecord()
{
	//setting all private variables to their repective zero
	m_fName = "";
	m_lName = "";
	m_age = 0;
	m_vote = 'Y';
	m_licenseNum = 0;
}
DriversLicenseRecord::DriversLicenseRecord(std::string first, std::string last, int age, char vote, int licenseNum)
{
	//setting the private variables to the corresponding values gotten from the parameters
	m_fName = first;
	m_lName = last;
	m_age = age;
	m_vote = vote;
	m_licenseNum = licenseNum;

	
}

void DriversLicenseRecord::print()
{
	//printing our the labels and corresponding info received from the file
	std::cout<<"Record: "
		<< m_fName <<" "<< m_lName <<"; "
		<<"Age: "<< m_age <<"; ";
		if(m_vote == 'Y')
		{
			std::cout<<"Registered To Vote; ";
		}
		else
		{
			std::cout<<"Not Registered To Vote; ";
		}
		std::cout<<"License Number: "<< m_licenseNum <<";"<<'\n';
}
int DriversLicenseRecord::getAge() const
{
	return(m_age);
}
void DriversLicenseRecord::setAge(int num)
{
	m_age = num;
}
std::string DriversLicenseRecord::getFirst() const
{
	return(m_fName);
}
void DriversLicenseRecord::setFirst(std::string name)
{
	m_fName = name;
}
std::string DriversLicenseRecord::getLast() const
{
	return(m_lName);
}
void DriversLicenseRecord::setLast(std::string name)
{
	m_lName = name;
}
int DriversLicenseRecord::getNumber() const
{
	return(m_licenseNum);
}
void DriversLicenseRecord::setNumber(int num)
{
	m_licenseNum = num;
}
char DriversLicenseRecord::getVote() const
{
	return(m_vote);
}
void DriversLicenseRecord::setVote(char v)
{
	m_vote = v;
}
