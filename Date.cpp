#pragma once
#include"Date.h"
#include<iostream>

using namespace std;

void Date::dateInput()
{
	cout << "\nnhap ngay: ";
	cin >> day;
	cout << "nhap thang: ";
	cin >> month;
	cout << "nhap nam: ";
	cin >> year;
}

void Date::dateOutput()
{
	cout << day << "/" << month << "/" << year << endl;
}

bool Date::compareDate(Date date2){
	if(day == date2.day && month == date2.month && year == date2.year){
		return true;
	}
	return false;
}

//Nam nhuan la nam chia het cho 400
//Nam nhuan la nam chia het cho 4 nhung khong chia het cho 100

bool Date::checkLeapYear() {
	if (year % 400 == 0) {
		return true; 
	}
    if (year % 4 == 0 && year % 100 != 0) {
    	return true;
	}
        
    return false; 
}

bool Date::checkDate() {
	switch(month){
		case 4:
		case 6:
		case 9:
		case 11:
			if(day < 0 || day > 30){
				return false;
			}
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(day < 0 || day > 31){
				return false;
			}
		case 2:
			if(checkLeapYear() == true){
				if(day < 0 || day > 29){
					return false;
				}
			}else{
				if(day < 0 || day > 28){
					return false;
				}
			}
	}
	return true;
}
