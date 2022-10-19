#pragma once
#include"Address.h"

void Address::addressInput()
{
	cout << "\nNhap so nha: ";
	cin >> homeNum;
	cout << "Nhap ten duong: ";
	fflush(stdin);
	getline(cin, streetName);
	cout << "Nhap phuong: ";
	fflush(stdin);
	getline(cin, ward);
	cout << "Nhap quan: ";
	fflush(stdin);
	getline(cin, district);
	cout << "Nhap thanh pho: ";
	fflush(stdin);
	getline(cin, city);
}

void Address::addressOutput()
{
	cout << homeNum << ", duong " << streetName << ", phuong " << ward << ", quan " << district << ", thanh pho " << city << endl;
}

bool Address::compareAddress(Address address2){
	if(homeNum == address2.homeNum && 
	   streetName == address2.streetName && 
	   ward == address2.ward && 
	   district == address2.district && 
	   city == address2.city ){
		return true;
	}
	return false;
}
