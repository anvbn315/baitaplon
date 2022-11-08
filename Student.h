#pragma once
#include"Date.h"
#include"Address.h"
#include"Point.h"
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
	Point point;
	public:
	// getter
		string getName();
	int getAge();
	Date getBirthDay();
	Address getAddress();
	string getGender();
	string getstudentCode();
	string getstudentClass();
	string getstudentSYear();
	string getstudentTown();
	Point  getPoint();
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
	void setPoint(Point IPpoint);
	Student operator =(Student b);
	void input();
	void output();
	void countAge();
};
