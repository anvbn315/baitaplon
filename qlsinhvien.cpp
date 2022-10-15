#include<iostream>
#include<string.h>
#include <cstring>
#include <conio.h>
using namespace std;

typedef struct Date{
	int day;
	int month;
	int year;
	
	void dateInput();
	void dateOutput();
}Date;

typedef struct Address{
	string homeNum;
	string streetName;
	string ward;
	string district;
	string city; 
	
	void addressInput();
	void addressOutput();
	
}Address;

class Student{
	private:
		string name;
		int age;
		Date birthDay;
		string studentCode;
		string studentClass;
		string studentSYear;
		string studentTown;
		Address address;
	public:
		string getName();
		int getAge();
		void input();
		void output();
};

struct Node{
	Student data;
	Node*next;
};

class List{
	private:
	Node*head;
	Node*tail;
	int size;
	public:
	List();
	Node*createNode(Student data);
	void addLast(Student data);
	void inputListStudent();
	void printList();
	void searchBy(string choice);
	void printMenu();
};
int main(){
	List list;
	
//	list.inputListStudent();
	
//	list.printList();
	list.printMenu();
}

void List::printMenu(){
	int choice;

	
	do{
		cout << "\n1) Nhap sinh vien" << endl;
		cout << "2) Xuat sinh vien" << endl;
		cout << "3) Nhan 0 de thoat" << endl;
		cout << "4) Tim kiem sinh vien" << endl;
		cout << "Nhap lua chon: ";
		cin >> choice;
		switch(choice){
		case 0:
			cout << "Ban da thoat chuong trinh" << endl;
			break;
		case 1:
			this->inputListStudent();
			cout << "\nNhan phim bat ky de tiep tuc" << endl;
			_getch();
			system("cls");
			break;
		case 2:
			if(size == 0){
				cout << "Danh sach trong!" << endl;
			}else{
				this->printList();	
			}
			cout << "\nNhan phim bat ky de tiep tuc" << endl;
			_getch();
			system("cls");
			break;
		case 4:
			if(size==0){
				cout << "Danh sach trong!" << endl;
			}else{
				short searchOption;
				cout << "1) Tim theo ten" << endl;
				cout << "2) Tim theo tuoi" << endl;
				cout << "Nhap lua chon: ";
				cin  >> searchOption;
//				cout << "1) Tim theo gioi tinh" << endl;
//				cout << "1) Tim theo thanh pho" << endl;
				switch(searchOption){
					case 1:
						this->searchBy("name"); //name
						break;
					case 2:
						this->searchBy("age"); //age
						break;
					default:
						cout << "Khong co lua chon nay" << endl;
				}
			}
			cout << "\nNhan phim bat ky de tiep tuc" << endl;
			_getch();
			system("cls");
			break;
		default:
			cout << "Khong co lua chon nay" << endl;
			cout << "\nNhan phim bat ky de tiep tuc" << endl;
			_getch();
		}
	}while(choice != 0);
	
}

void Date::dateInput(){
	cout << "nhap ngay:" ;
	cin >> day;
	cout << "nhap thang:" ;
	cin >> month;
	cout << "nhap nam:" ;
	cin >> year;
}

void Date::dateOutput(){
	cout << day << "/" << month << "/" << year << endl;
}

void Address::addressInput(){
	cout << "Nhap so nha: ";
	cin >> homeNum;
	cout << "Nhap ten duong: ";
	fflush(stdin);
	getline(cin,streetName);
	cout << "Nhap phuong: ";
	fflush(stdin);
	getline(cin,ward);
	cout << "Nhap quan: ";
	fflush(stdin);
	getline(cin,district);
	cout << "Nhap thanh pho: ";
	fflush(stdin);
	getline(cin,city);
}

void Address::addressOutput(){
	cout << homeNum << ", duong" << streetName << ", phuong " << ward << ", quan " << district << ", thanh pho " << city << endl;
}

string Student::getName(){
	return name;
}

int Student::getAge(){
	return age;
}

void Student::input(){
	cout << "Nhap ten sinh vien: ";
	fflush(stdin);
	getline(cin, name);
	cout << "Nhap tuoi sinh vien: ";
	cin >> age;
	cout << "Nhap ngay sinh: " << endl;
	birthDay.dateInput();
	cout << "Nhap ma so sinh vien: ";
	cin >> studentCode;
	cout << "Nhap lop sinh vien: ";
	cin >> studentClass;
	cout << "Nhap nien khoa sinh vien: ";
	cin >> studentSYear;
	cout << "Nhap que quan sinh vien: ";
	fflush(stdin);
	getline(cin,studentTown);
	cout << "Nhap dia chi thuong tru: "<< endl;
	address.addressInput();
}

void Student::output() {
	cout << "\nTen sinh vien la: " << name << endl;
	cout << "Tuoi sinh vien la: " << age << endl;
	cout << "Ngay sinh la: ";
	birthDay.dateOutput();
	cout << "Ma so sinh vien la: " << studentCode << endl;
	cout << "Lop sinh vien la: " << studentClass << endl;
	cout << "Nien khoa sinh vien la: " << studentSYear << endl;
	cout << "Que quan sinh vien la: " << studentTown << endl;
	cout << "Dia chi sinh vien la: ";
	address.addressOutput();
}
List::List(){
	head=tail=NULL;
}
Node*List::createNode(Student data){
	Node* p = new Node;
	p->data = data;
	p->next = NULL;
	return p;
}
void List::addLast(Student data){
	Node* p = createNode(data);
	if(head==NULL){
		head=tail=p;
		this->size++;
	}else{
		tail->next = p;
		tail=p;
		this->size++;
	}
}

void List::searchBy(string choice){
	if(choice=="name"){
		char tempName[100];
		cout << "Nhap ten can tim: ";
		fflush(stdin);
		gets(tempName);
		
		for(Node* i=head;i!=NULL;i=i->next){	
			int n = (i->data.getName()).length();
			char myarray[n + 1];
			strcpy(myarray, i->data.getName().c_str());
			if(strstr(strupr(myarray), strupr(tempName)) != NULL){
				cout << "\n\r";
				i->data.output();
			}
		}
	}else if(choice=="age"){
		int tempAge;
		cout << "Nhap tuoi can tim: ";
		cin >> tempAge;
		for(Node*i=head;i!=NULL;i=i->next){
			if(i->data.getAge()==tempAge){
				cout << "\n\r";
				i->data.output();
			}
		}
		
	}
}

void List::inputListStudent(){
	int amount;
	cout << "Nhap so luong sinh vien muon them: ";
	cin >> amount;
	
	for(int i = 0; i < amount;i++){
		Student temp;
		temp.input();
		addLast(temp);
	}
}

void List::printList(){
    for(Node* i = head;i!=NULL;i=i->next){
    	i->data.output();
	}
}

