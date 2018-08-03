#include "stdafx.h"
#include "User.h"


User::User(void)
{
}


User::~User(void)
{
}

User::User(string username, string password, string fullname, string address, string birthday, string sex){
	this->username=username;
	this->password=password;
	this->fullname=fullname;
	this->address=address;
	this->birthday=birthday;
	this->sex=sex;
}

User::User(string username, string password){
	this->username=username;
	this->password=password;
}

void User::nhap(){
	fflush(stdin);
	cout<< "Nhap username: ";
	getline(cin, username);
	fflush(stdin);
	cout<< "Nhap password: ";
	getline(cin, password);
	fflush(stdin);
}

void User::dangKy(){
	fflush(stdin);
	cout<< "Nhap username: ";
	getline(cin, username);
	fflush(stdin);
	cout<< "Nhap password: ";
	getline(cin, password);
	fflush(stdin);
	cout<< "Nhap day du ho va ten: ";
	getline(cin, fullname);
	fflush(stdin);
	cout<< "Nhap ngay, thang, nam sinh(dd/mm/yyyy): ";
	getline(cin, birthday);
	fflush(stdin);
	cout<< "Nhap gioi tinh: ";
	getline(cin, sex);
	fflush(stdin);
	cout<< "Nhap dia chi: ";
	getline(cin, address);
	fflush(stdin);
}
