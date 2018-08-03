#pragma once
#include <iostream>
#include <string>

using namespace std;
class User
{
public:
	string username;
	string password;
	string fullname;
	string address;
	string birthday;
	string sex;

public:
	User(void);
	~User(void);

	User(string username, string password, string fullname, string birthday, string sex, string address);
	User(string username, string password);

	void nhap();
	void dangKy();

};
