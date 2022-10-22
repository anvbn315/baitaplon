#pragma once
#include"Student.h"
#include<ctime>

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

Address Student::getAdress()
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
}

void Student::output()
{
	cout << "\nTen sinh vien la: " << name << endl;
	cout << "Tuoi sinh vien la: " << age << endl;
	cout << "Gioi tinh sinh vien la: " << gender << endl;
	cout << "Ngay sinh la: ";
	birthDay.dateOutput();
	cout << "Ma so sinh vien la: " << studentCode << endl;
	cout << "Lop sinh vien la: " << studentClass << endl;
	cout << "Nien khoa sinh vien la: " << studentSYear << endl;
	cout << "Que quan sinh vien la: " << studentTown << endl;
	cout << "Dia chi sinh vien la: ";
	address.addressOutput();
}

void Student::countAge(){
	int bornYear = birthDay.year;
	time_t Time = time(0);
	tm* Now = localtime(&Time);
	int	currentYear = Now->tm_year + 1900;
	
	age = currentYear - bornYear;
}
