#pragma once
#include"List.h"
#include <string.h>
#include <cstring>
#include <conio.h>
#include<iostream>
#include <fstream>

void List::printMenu()
{
	int choice;
	do {
		cout << "         --QUAN LI SINH VIEN--       " << endl;
		cout << "=================================================" << endl;
		cout << "| 0)          Nhan 0 de thoat                   |" << endl;
		cout << "| 1)          Nhap sinh vien                    |" << endl;
		cout << "| 2)          Xuat sinh vien                    |" << endl;
		cout << "| 3)          Tim kiem sinh vien                |" << endl;
		cout << "| 4)          Xoa sinh vien                     |" << endl;
		cout << "| 5)          Chinh sua thong tin sinh vien     |" << endl;
		cout << "| 6)          Xuat thong tin ra file            |" << endl;
		cout << "=================================================" << endl;
		cout << "Nhap lua chon: ";
		cin >> choice;
		switch (choice)
		{
			case 0:
				cout << "\nBan da thoat chuong trinh" << endl;
				break;
			case 1:
				this->inputListStudent();
				cout << "\nNhan phim bat ky de tiep tuc" << endl;
				_getch();
				system("cls");
				break;
			case 2:
				if (size == 0)
				{
					cout << "\nDanh sach trong!" << endl;
				}
				else
				{
					this->printList();
				}

				cout << "\nNhan phim bat ky de tiep tuc" << endl;
				_getch();
				system("cls");
				break;
			case 3:
				if (size == 0)
				{
					cout << "\nDanh sach trong!" << endl;
				}
				else
				{
					short searchOption;
					cout << "1) Tim theo ten" << endl;
					cout << "2) Tim theo tuoi" << endl;
					cout << "3) Tim theo gioi tinh" << endl;
					cout << "4) Tim theo ngay thang nam sinh" << endl;
					cout << "5) Tim theo ma so sinh vien" << endl;
					cout << "6) Tim theo lop" << endl;
					cout << "7) Tim theo nien khoa" << endl;
					cout << "8) Tim theo que quan" << endl;
					cout << "9) Tim theo dia chi thuong tru" << endl;
					cout << "Nhap lua chon: ";
					cin >> searchOption;
					switch (searchOption)
					{
						case 1:
							this->searchBy("name");	//name
							break;
						case 2:
							this->searchBy("age");	//age
							break;
						case 3:
							this->searchBy("gender");
							break;
						case 4:
							this->searchBy("birthDay");
							break;
						case 5:
							this->searchBy("studentCode");
							break;
						case 6:
							this->searchBy("studentClass");
							break;
						case 7:
							this->searchBy("studentSYear");
							break;
						case 8:
							this->searchBy("studentTown");
							break;
						case 9:
							this->searchBy("address");
							break;
						default:
							cout << "Khong co lua chon nay" << endl;
					}
				}

				cout << "\nNhan phim bat ky de tiep tuc" << endl;
				_getch();
				system("cls");
				break;
			case 4:
				if(size == 0){
					cout << "\nDanh sach trong!" << endl;
				}else{
					string code;
					cout << "Nhap ma so sinh vien muon xoa: ";
					cin >> code;
					this->deleteByStudentCode(code);	
				}
				cout << "\nNhan phim bat ky de tiep tuc" << endl;
				_getch();
				system("cls");
				break;
			case 5:
				if(size == 0){
					cout << "\nDanh sach trong!" << endl;
				}else{
					string code;
					cout << "Cap nhap thong tin sinh vien!" << endl;
					cout << "Nhap ma so sinh vien: " << endl;
					cin >> code;
					this->updateByStudentCode(code);
				}	
				cout << "\nNhan phim bat ky de tiep tuc" << endl;
				_getch();
				system("cls");
				break;
			case 6:
				if(size == 0){
					cout << "\nDanh sach trong!" << endl;
				}else{
					this->outputFile();
				}	
				cout << "\nNhan phim bat ky de tiep tuc" << endl;
				_getch();
				system("cls");
				break;
			default:
				cout << "\nKhong co lua chon nay!" << endl;
				cout << "\nNhan phim bat ky de tiep tuc!" << endl;
				_getch();
				system("cls");
		}
	} while (choice != 0);

}

List::List()
{
	head = tail = NULL;
}

Node *List::createNode(Student data)
{
	Node *p = new Node;
	p->data = data;
	p->next = NULL;
	return p;
}

void List::updateByStudentCode(string code){
	bool isFound = false;
	
	for(Node *i=head;i!=NULL;i=i->next){
		if(i->data.getstudentCode() == code){
			isFound = true;
			cout << "\n\r";
			i->data.input();
		}
	}
	
	if(!isFound){
		cout << "Khong tim thay sinh vien!" << endl;
	}
}

void List::deleteByStudentCode(string code)
{
	for(Node *i=head;i!=NULL;i=i->next){
		if(i->data.getstudentCode() == code){
			if(i == head){
				Node *currentNode = head;
				head = head->next;
				delete currentNode;
				size--;
				cout << "Da xoa thanh cong!" << endl;
			}else{
				for(Node *i = head;i != NULL;i = i->next){
					if(i->next->data.getstudentCode() == code){
						Node *nodeToDelete = i->next;
						i->next = i->next->next;
						delete nodeToDelete;
						size--;
						cout << "Da xoa thanh cong!" << endl;
					}
				}
			}
		}
	}
} 

void List::addLast(Student data)
{
	Node *p = createNode(data);
	if (head == NULL)
	{
		head = tail = p;
		this->size++;
	}
	else
	{
		tail->next = p;
		tail = p;
		this->size++;
	}
}

void List::searchBy(string choice)
{
	if (choice == "name")
	{
		bool isFound = false;
		char tempName[100];
		cout << "Nhap ten can tim: ";
		fflush(stdin);
		gets(tempName);

		for (Node *i = head; i != NULL; i = i->next)
		{
			int n = (i->data.getName()).length();
			char myarray[n + 1];
			strcpy(myarray, i->data.getName().c_str());
			if (strstr(strupr(myarray), strupr(tempName)) != NULL)
			{
				cout << "\n\r";
				isFound = true;
				i->data.output();
			}
		}

		if (!isFound)
		{
			cout << "\nKhong tim thay! " << endl;
		}
	}
	else if (choice == "age")
	{
		bool isFound = false;
		int tempAge;
		cout << "Nhap tuoi can tim: ";
		cin >> tempAge;

		for (Node *i = head; i != NULL; i = i->next)
		{
			if (i->data.getAge() == tempAge)
			{
				cout << "\n\r";
				isFound = true;
				i->data.output();
			}
		}

		if (!isFound)
		{
			cout << "\nKhong tim thay!" << endl;
		}
	}
	else if (choice == "gender")
	{
		bool isFound = false;
		int genderNum;
		string tempGender;
		do { 	cout << "Lua chon gioi tinh: " << endl;
			cout << "1) Nam \n\r2) Nu" << endl;
			cout << "Nhap lua chon: ";
			cin >> genderNum;
			switch (genderNum)
			{
				case 1:
					tempGender = "nam";
					break;
				case 2:
					tempGender = "nu";
					break;
				default:
					cout << "Khong co lua chon nay!" << endl;
			}
		} while (genderNum != 1 && genderNum != 2);

		for (Node *i = head; i != NULL; i = i->next)
		{
			if (i->data.getGender() == tempGender)
			{
				cout << "\n\r";
				isFound = true;
				i->data.output();
			}
		}

		if (!isFound)
		{
			cout << "\nKhong tim thay!" << endl;
		}
	}
	else if (choice == "studentCode")
	{
		bool isFound = false;
		char tempStudentCode[100];
		cout << "Nhap ma so sinh vien can tim: ";
		fflush(stdin);
		gets(tempStudentCode);

		for (Node *i = head; i != NULL; i = i->next)
		{
			int n = (i->data.getstudentCode()).length();
			char myarray[n + 1];
			strcpy(myarray, i->data.getstudentClass().c_str());
			if (strstr(strupr(myarray), strupr(tempStudentCode)) != NULL)
			{
				cout << "\n\r";
				isFound = true;
				i->data.output();
			}
		}

		if (!isFound)
		{
			cout << "\nKhong tim thay!" << endl;
		}
	}
	else if (choice == "studentClass")
	{
		bool isFound = false;
		char tempStudentClass[100];
		cout << "Nhap lop can tim: ";
		fflush(stdin);
		gets(tempStudentClass);

		for (Node *i = head; i != NULL; i = i->next)
		{
			int n = (i->data.getstudentClass()).length();
			char myarray[n + 1];
			strcpy(myarray, i->data.getstudentClass().c_str());
			if (strstr(strupr(myarray), strupr(tempStudentClass)) != NULL)
			{
				isFound = true;
				cout << "\n\r";
				i->data.output();
			}
		}

		if (!isFound)
		{
			cout << "\nKhong tim thay!" << endl;
		}
	}
	else if (choice == "studentSYear")
	{
		bool isFound = false;
		string tempStudentSYear;
		cout << "Nhap nien khoa can tim: ";
		cin >> tempStudentSYear;
		for (Node *i = head; i != NULL; i = i->next)
		{
			if (i->data.getstudentSYear() == tempStudentSYear)
			{
				isFound = true;
				cout << "\n\r";
				i->data.output();
			}
		}

		if (!isFound)
		{
			cout << "\nKhong tim thay!" << endl;
		}
	}
	else if (choice == "studentTown")
	{
		bool isFound = false;
		char tempStudentTown[100];
		cout << "Nhap que quan can tim: ";
		fflush(stdin);
		gets(tempStudentTown);

		for (Node *i = head; i != NULL; i = i->next)
		{
			int n = (i->data.getstudentTown()).length();
			char myarray[n + 1];
			strcpy(myarray, i->data.getstudentTown().c_str());
			if (strstr(strupr(myarray), strupr(tempStudentTown)) != NULL)
			{
				isFound = true;
				cout << "\n\r";
				i->data.output();
			}
		}

		if (!isFound)
		{
			cout << "\nKhong tim thay!" << endl;
		}
	}
	else if (choice == "birthDay")
	{
		bool isFound = false;
		Date tempBirthDay;
		do{
			cout << "Nhap ngay/ thang/ nam can tim: ";
			tempBirthDay.dateInput();
			if(tempBirthDay.checkDate() == false){
				cout << "Ngay khong hop le!" << endl;
			}
		}while(tempBirthDay.checkDate() == false);
		
	
		for (Node *i = head; i != NULL; i = i->next)
		{
			if (i->data.getBirthDay().compareDate(tempBirthDay) == true){
				isFound = true;
				cout << "\n\r";
				i->data.output();
			}	
		}

		if (!isFound)
		{
			cout << "\nKhong tim thay!";
		}
	}
	else if (choice == "address")
	{
		bool isFound = false;
		Address tempAddress;
		cout << "Nhap dia chi thuong tru can tim: ";
		tempAddress.addressInput();
		for (Node *i = head; i != NULL; i = i->next)
		{
			if (i->data.getAdress().compareAddress(tempAddress) == true){
				cout << "\n\r";
				isFound = true;
				i->data.output();
			}
		}

		if (!isFound)
		{
			cout << "\nKhong tim thay!";
		}
	}
}

void List::inputListStudent()
{
	int amount;
	cout << "Nhap so luong sinh vien muon them: ";
	cin >> amount;

	for (int i = 0; i < amount; i++)
	{
		Student temp;
		temp.input();
		addLast(temp);
	}
}

void List::printList()
{
	for (Node *i = head; i != NULL; i = i->next)
	{
		i->data.output();
	}
}

void List::inputFile() {
	ifstream infile;
	infile.open(FILE_PATH);
	
	Date tempBirthDay;
	string tempName;
	string tempGender;
	string tempStudentCode;
	string tempStudentClass;
	string tempStudentSYear;
	string tempStudentTown;
	Address tempAddress;
	Student temp;
	
	if(infile.is_open() == false){
		cout << "File khong ton tai!" << endl;
	}
	
	while(infile >> tempBirthDay.day){
		infile >> tempBirthDay.month;
		infile >> tempBirthDay.year;
		infile.ignore();
		getline(infile, tempName);
		infile >> tempGender;
		infile >> tempStudentCode;
		infile >> tempStudentClass;
		infile >> tempStudentSYear;
		infile >> tempStudentTown;
		infile.ignore();
		getline(infile, tempAddress.homeNum);
		getline(infile, tempAddress.streetName);
		getline(infile, tempAddress.ward);
		getline(infile, tempAddress.district);
		getline(infile, tempAddress.city);
		
		temp.setName(tempName);
		temp.setBirthDay(tempBirthDay);
		temp.setAddress(tempAddress);
		temp.setGender(tempGender);
		temp.setStudentClass(tempStudentClass);
		temp.setStudentCode(tempStudentCode);
		temp.setStudentSYear(tempStudentSYear);
		temp.setStudentTown(tempStudentTown);
		temp.countAge();
		
		this->addLast(temp);
	
	}
		infile.close();	
}

void List::outputFile(){
	ofstream outFile;
	outFile.open(FILE_PATH);
	
	if(outFile.is_open() == false){
		cout << "File khong ton tai!" << endl;
	}	
	
	for(Node *i = head;i != NULL;i=i->next){
		outFile << i->data.getBirthDay().day << endl;
		outFile << i->data.getBirthDay().month << endl;
		outFile << i->data.getBirthDay().year << endl;
		outFile << i->data.getName() << endl;
		outFile << i->data.getGender() << endl;
		outFile << i->data.getstudentCode() << endl;
		outFile << i->data.getstudentClass() << endl;
		outFile << i->data.getstudentSYear() << endl;
		outFile << i->data.getstudentTown() << endl;
		outFile << i->data.getAdress().homeNum << endl;
		outFile << i->data.getAdress().streetName << endl;
		outFile << i->data.getAdress().ward << endl;
		outFile << i->data.getAdress().district << endl;
		outFile << i->data.getAdress().city << endl;
	}
	
	outFile.close();
}
