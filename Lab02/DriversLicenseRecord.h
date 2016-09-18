/**
 *File: DriversLicenseRecord.h
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: February 7,2016
 *Purpose: Header file for the DriversLicenseRecord class
**/

#ifndef DRIVERSLICENSERECORD_H
#define DRIVERSLICENSERECORD_H
#include <iostream>
#include <string>



//reads in the file

class DriversLicenseRecord
{
	private:
		int m_age;
		std::string m_lName;
		std::string m_fName;
		char m_vote;
		int m_licenseNum;
	public:
	/**
	*  @pre the private variables
	*  @post sets all private variables to their respective zeros
	*  @return None
	*/
		DriversLicenseRecord();
	/**
	*  @pre two strings, two integers, and a character for first and last name, age, licenses number, and registered as a voter
	*  @post sets the private variables to equal the corresponding variable from the parameter
	*  @return None
	*/
		DriversLicenseRecord(std::string first, std::string last, int age, char vote, int licenseNum);
	/**
	*  @pre defined variables
	*  @post prints out the information from the private variables with their labels
	*  @return None
	*/
		void print();
	/**
	*  @pre None
	*  @post gives the age contained in an object when requested
	*  @return an Integer, age
	*/
		int getAge() const;
	/**
	*  @pre an integer, num
	*  @post assigns the taken in integer to m_age
	*  @return None
	*/
		void setAge(int num);
	/**
	*  @pre None
	*  @post gives the first name contained in an object when requested
	*  @return a string, first name
	*/
		std::string getFirst() const;
	/**
	*  @pre a string, name
	*  @post assigns the taken in string to m_fName
	*  @return None
	*/
		void setFirst(std::string name);
	/**
	*  @pre None
	*  @post gives the last name contained in an object when requested
	*  @return a string, last name
	*/
		std::string getLast() const;
	/**
	*  @pre a string, name
	*  @post assigns the taken in string to m_lName
	*  @return None
	*/
		void setLast(std::string name);
	/**
	*  @pre None
	*  @post gives the license number contained in an object when requested
	*  @return an integer, license number
	*/
		int getNumber() const;
	/**
	*  @pre an integer, num
	*  @post assigns the taken in string to m_licenseNum
	*  @return None
	*/
		void setNumber(int num);
	/**
	*  @pre None
	*  @post gives the character representing a registered or not registered voter in an object when requested
	*  @return a character, vote
	*/
		char getVote() const;
	/**
	*  @pre a character, v
	*  @post assigns the taken in character to m_vote
	*  @return None
	*/
		void setVote(char v);
};


#endif
