#pragma once
#include <cmath>
#include "Point.h"
#include<iostream>
using namespace std;

float Point::getFirstExam(){
	return firstExam;
}

float Point::getSecondExam(){
	return secondExam;
}

float Point::getFinalExam(){
	return finalExam;
}

float Point::getComponent(){
	return component;
}

float Point::getAttendance(){
	return attendance;
}

float Point::getEoTCourse(){
	return eOtCourse;
}

void Point::inputPoint(){
	cout << "Mon hoc: Cau truc du lieu va giai thuat" << endl;
	cout << "Nhap diem bai kiem tra so 1: " << endl;
	cin >> firstExam;
	cout << "Nhap diem bai kiem tra so 2: " << endl;
	cin >> secondExam;
	cout << "Nhap diem bai kiem tra cuoi ky: " << endl;
	cin >> finalExam;
	cout << "Nhap diem chuyen can: " << endl;
	cin >> attendance;
	componentScoring();
	eOtCourseScoring();
}

void Point::outputPoint(){
	cout << "Mon hoc: Cau truc-du lieu va giai thuat" << endl;
	cout << "Diem bai kiem tra so 1 la: " << firstExam << endl;
	cout << "Diem bai kiem tra so 2 la: " << secondExam << endl;
	cout << "Diem bai kiem tra cuoi ky la: " << finalExam << endl;
	cout << "Diem chuyen can la: " << firstExam << endl;
	pointEvaluation();
		
}

void Point::componentScoring(){
	component = ((firstExam*20/100) + (secondExam*20/100) + (attendance*10/100));
}

void Point::eOtCourseScoring(){
	eOtCourse = ((finalExam*50/100) + component);
}

void Point::pointEvaluation(){
	if(eOtCourse >=8.5 && eOtCourse <=10 ){
		cout << "Hoc luc: Gioi - A" << endl;
	}else if (eOtCourse >=7 && eOtCourse <=8.4){
		cout << "Hoc luc: Kha - B" << endl;
	}else if (eOtCourse >=5.5 && eOtCourse <=6.9){
		cout << "Hoc luc: Trung binh - C" << endl;
	}else if (eOtCourse >=4 && eOtCourse <=5.4){
		cout << "Hoc luc: Yeu - D" << endl;
	}else if (eOtCourse <4){
		cout << "Hoc luc: Kem - F" << endl;
		cout << "Canh bao: Mon hoc khong dat!" << endl;
}
}
