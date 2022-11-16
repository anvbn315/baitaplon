#pragma once
#include <cmath>
#include "Point.h"
#include<iostream>
#include<iomanip>

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

void Point::setFirstExam(float point) {
	this->firstExam = point;
}

void Point::setSecondExam(float point) {
	this->secondExam = point;
}

void Point::setFinalExam(float point) {
	this->finalExam = point;
}

void Point::setAttendance(float point) {
	this->attendance = point;
}

void Point::setComponent(float point) {
	this->component = point;
}

void Point::setEoTCourse(float point) {
	this->eOtCourse = point;
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
	pointEvaluation();
	cout<< setw(15)  << firstExam << "|"
	<< setw(15)  << secondExam << "|"
	<< setw(15)  << finalExam << "|"
	<< setw(15)  << attendance << "|" 
	<< setw(10) << rank << "|" <<  endl;
		
}

void Point::componentScoring(){
	component = ((firstExam*20/100) + (secondExam*20/100) + (attendance*10/100));
}

void Point::eOtCourseScoring(){
	eOtCourse = ((finalExam*50/100) + component);
}

void Point::pointEvaluation(){
	if(eOtCourse >=8.5 && eOtCourse <=10 ){
		rank="Gioi-A";
	}else if (eOtCourse >=7 && eOtCourse <=8.4){
		rank="Kha-B";
	}else if (eOtCourse >=5.5 && eOtCourse <=6.9){
		rank="Trung binh-C";
	}else if (eOtCourse >=4 && eOtCourse <=5.4){
		rank="Yeu-D";
	}else if (eOtCourse <4){
		rank="Kem-F";
}
}
