#pragma once
#include <iostream>
#include "Database.h"
#include "User.h"

using namespace std;

class Menu
{
public:
	User user;

	Menu(void);
	~Menu(void);
	
	void menu1();
	
	void menu2();
	
	void choice1();
	
	void choice2(string username, string password);
	
};

