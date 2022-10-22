#pragma once
#include"Date.h"
#include"Address.h"

class Student
{
	private:
		string name;
	int age;
	string gender;
	Date birthDay;
	string studentCode;
	string studentClass;
	string studentSYear;
	string studentTown;
	Address address;
	public:
	// getter
		string getName();
	int getAge();
	Date getBirthDay();
	Address getAdress();
	string getGender();
	string getstudentCode();
	string getstudentClass();
	string getstudentSYear();
	string getstudentTown();
	//setter
	void setName(string IPname);
	void setAge(int IPage);
	void setGender(string IPgender);
	void setBirthDay(Date IPbirthDay);
	void setStudentCode(string IPstudentCode);
	void setStudentClass(string IPstudentClass);
	void setStudentSYear(string IPstudentSYear);
	void setStudentTown(string IPstudentTown);
	void setAddress(Address IPaddress);
	
	void input();
	void output();
	void countAge();
};
