#pragma once
#include <iostream>
#include "sqlite3.h"
#include "User.h"
#include <stdio.h>
#include "Menu.h"

using namespace std;

class Database
{	
public:
	sqlite3_stmt* stmt;
	sqlite3 *database;
	int rc;
	char *zErrMsg;
public:
	Database(void);
	~Database(void);

	bool connect();

	void signUp(User user);

	void logIn(string username, string password);

	bool check(string username, string password);

	void listFriend(string username);

	bool check(string username);

	void addFriend(string username, string Friend);

	void sendMessage(string sender, string receiver, string content);

	void block(string username, string block);

	void showMessage(string username);

	void showInfo(string username);

};

