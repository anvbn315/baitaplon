#pragma once
#include"Student.h"

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

void Student::input()
{
	int genderTemp;
	cout << "Nhap ten sinh vien: ";
	fflush(stdin);
	getline(cin, name);
	cout << "Nhap tuoi sinh vien: ";
	cin >> age;

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
