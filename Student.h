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
		string getName();
	int getAge();
	Date getBirthDay();
	Address getAdress();
	string getGender();
	string getstudentCode();
	string getstudentClass();
	string getstudentSYear();
	string getstudentTown();
	void input();
	void output();
};
