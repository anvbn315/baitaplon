#include<iostream>
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
	
	public:
	List();
	Node*createNode(Student data);
	void addLast(Student data);
	void inputListStudent();
	void printList();
};
int main(){
	List list;
	
	list.inputListStudent();
	cout << "testfix";
	cout << "fixed" << endl;
	list.printList();
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
	cout << "Ten sinh vien la: " << name << endl;
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
	}	else{
		tail->next=p;
		tail=p;
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


