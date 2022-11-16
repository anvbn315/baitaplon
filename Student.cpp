#pragma once
#include"Student.h"
#include<ctime>
#include"Point.h"
#include<iomanip>

Point Student::getPoint()
{
	return point;
}
string Student::getName()
{
	return name;
}

int Student::getAge()
{
	return age;
}

string Student::getGender()
{
	return gender;
}

string Student::getstudentCode()
{
	return studentCode;
}

string Student::getstudentClass()
{
	return studentClass;
}

string Student::getstudentSYear()
{
	return studentSYear;
}

string Student::getstudentTown()
{
	return studentTown;
}

Date Student::getBirthDay()
{
	return birthDay;
}

Address Student::getAddress()
{
	return address;
}

void Student::setName(string IPname){
	name = IPname;
}

void Student::setAge(int IPage){
	age = IPage;
}

void Student::setGender(string IPgender){
	gender = IPgender;
}

void Student::setBirthDay(Date IPbirthDay){
	birthDay.day = IPbirthDay.day;
	birthDay.month = IPbirthDay.month;
	birthDay.year = IPbirthDay.year;
}

void Student::setPoint(Point IPpoint){
	point.setFirstExam(IPpoint.getFirstExam());
	point.setSecondExam(IPpoint.getSecondExam());
	point.setFinalExam(IPpoint.getFinalExam());
	point.setAttendance(IPpoint.getAttendance());
	point.componentScoring();
	point.eOtCourseScoring();
}

void Student::setStudentCode(string IPstudentCode){
	studentCode = IPstudentCode;
}

void Student::setStudentClass(string IPstudentClass){
	studentClass = IPstudentClass;
}

void Student::setStudentSYear(string IPstudentSYear){
	studentSYear = IPstudentSYear;
}

void Student::setStudentTown(string IPstudentTown){
	studentTown = IPstudentTown;
}



void Student::setAddress(Address IPaddress){
	address.homeNum = IPaddress.homeNum;
	address.streetName = IPaddress.streetName;
	address.ward = IPaddress.ward;
	address.district = IPaddress.district;
	address.city = IPaddress.city;	
}

//**************************************
Student Student::operator =(Student b){
	this->address.city = b.address.city;
	this->address.district = b.address.district;
	this->address.homeNum = b.address.homeNum;
	this->address.streetName = b.address.streetName;
	this->address.ward = b.address.ward;
	
	this->age = b.age;
	
	this->birthDay.day = b.birthDay.day;
	this->birthDay.month = b.birthDay.month;
	this->birthDay.year = b.birthDay.year;
	
	this->gender = b.gender;
	
	this->name = b.name;
	this->studentCode = b.studentCode;
	this->studentClass = b.studentClass;
	this->studentSYear = b.studentSYear;
	this->studentTown = b.studentTown;
	
	this->point.setAttendance(b.point.getAttendance());
	this->point.setComponent(b.point.getComponent());
	this->point.setFirstExam(b.point.getFirstExam());
	this->point.setSecondExam(b.point.getSecondExam());
	this->point.setFinalExam(b.point.getFinalExam());
	this->point.setEoTCourse(b.point.getEoTCourse());
	
	return *this;
}

void Student::input()
{
	int genderTemp;
	cout << "Nhap ten sinh vien: ";
	fflush(stdin);
	getline(cin, name);

	do {
		cout << "Nhap gioi tinh sinh vien: " << endl;
		cout << "1) Nam" << endl;
		cout << "2) Nu" << endl;
		cout << "Nhap lua chon: ";
		cin >> genderTemp;
		switch (genderTemp)
		{
			case 1:
				gender = "nam";
				break;
			case 2:
				gender = "nu";
				break;
			default:
				cout << "Khong co lua chon nay!" << endl;
		}
	} while (genderTemp != 1 && genderTemp != 2);
	
	do{
		cout << "Nhap ngay sinh: ";
		birthDay.dateInput();
		
		if(birthDay.checkDate() == false){
			cout << "Ngay khong hop le!" << endl;
		}
	}while(birthDay.checkDate() == false);

	cout << "Nhap ma so sinh vien: ";
	cin >> studentCode;
	cout << "Nhap lop sinh vien: ";
	cin >> studentClass;
	cout << "Nhap nien khoa sinh vien: ";
	cin >> studentSYear;
	cout << "Nhap que quan sinh vien: ";
	fflush(stdin);
	getline(cin, studentTown);
	cout << "Nhap dia chi thuong tru: ";
	address.addressInput();
	countAge();
	cout<< "Nhap diem sinh vien: " <<endl;
	point.inputPoint();
	
}

void Student::output()
{	
	cout<< setw(20) << left << name << "|" 
	<< setw(5) << age << "|" 
	<< setw(10) << gender << "|";
	birthDay.dateOutput();
	cout << setw(15) << studentCode << "|" 
	<< setw(10) << studentClass << "|"
	<< setw(10) << studentSYear << "|"
	<< setw(10) << studentTown << "|" ;	
	address.addressOutput();
}

void Student::countAge(){
	int bornYear = birthDay.year;
	time_t Time = time(0);
	tm* Now = localtime(&Time);
	int	currentYear = Now->tm_year + 1900;
	
	age = currentYear - bornYear;
}
