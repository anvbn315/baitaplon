#pragma once
#include"Student.h"

#define FILE_PATH "C:/Duonghieu/QuanLiSinhVien.txt"

struct Node
{
	Student data;
	Node * next;
};

class List
{
	private:
		Node * head;
	Node * tail;
	int size;
	public:
		List();
	Node* createNode(Student data);
	void addLast(Student data);
	void inputListStudent();
	void printList();
	void searchBy(string choice);
	void printMenu();
	void deleteByStudentCode(string code); 
	void updateByStudentCode(string code);
	void inputFile();
	void outputFile();
};
