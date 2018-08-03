#include "stdafx.h"
#include "Menu.h"

Menu::Menu(void)
{
}


Menu::~Menu(void)
{
}

void Menu::menu1(){
	cout<<endl<<endl<<endl;
	cout<< "\t\t\t===============MENU=============="<<endl;
	cout<< "\t\t\t|                               |"<<endl;
	cout<< "\t\t\t|\t1. Dang ky\t\t|"<<endl;
	cout<< "\t\t\t|\t2. Dang nhap\t\t|"<<endl;
	cout<< "\t\t\t|\t3. Thoat\t\t|"<<endl;
	cout<< "\t\t\t|                               |"<<endl;
	cout<< "\t\t\t================================="<<endl;
}

void Menu::menu2()
{
	cout<<endl<<endl;
	cout<< "\t===========================MENU=========================="<<endl;
	cout<< "\t|                                                       |"<<endl;
	cout<< "\t|\t1. Hien thi cac tin nhan da gui\t\t\t|"<<endl;
	cout<< "\t|\t2. Gui tin nhan\t\t\t\t\t|"<<endl;
	cout<< "\t|\t3. Them ban\t\t\t\t\t|"<<endl;
	cout<< "\t|\t4. Hien thi danh sach ban be\t\t\t|"<<endl;
	cout<< "\t|\t5. Block\t\t\t\t\t|"<<endl;
	cout<< "\t|\t6. Hien thi thong tin tai khoan\t\t\t|"<<endl;
	cout<< "\t|\t7. Thoat\t\t\t\t\t|"<<endl;
	cout<< "\t|                                                       |"<<endl;
	cout<< "\t========================================================="<<endl;
}

void Menu::choice1(){
	Database database;
	char chosse1;
	do
	{
		system("cls");
		menu1();
		cout<<endl<<"\tNhap vao lua chon: ";
		fflush(stdin);
		cin>>chosse1;
		switch (chosse1)
		{
		case '1':
			if(database.connect()){
				//fprintf(stdout, "\nOpened database successfully\n");
				user.dangKy();
				database.signUp(user);
			}
			else{
				fprintf(stderr, "\n\tKo the mo database: %s\n");
			}
			break;
		case '2':
			system("cls");
			if(database.connect()){
				user.nhap();
				database.logIn(user.username, user.password);
			}
			else
			{
				cout <<endl<< "Loi !!!";
			}
			break;
		case '3': cout<<endl<< "Da Thoat !!!"<<endl;
			break;
		default:
			cout<<endl<< "Chon sai. An mot phim bat ky de chon lai !!!"<<endl;
			_getch();
		}
		if (chosse1=='3')
		{
			break;
		}
	} while (true);
}

void Menu::choice2(string username, string password)
{
	Database database;
	char chosse2;
	do
	{
		system("cls");
		menu2();
		cout<<endl<<"\tNhap vao lua chon: ";
		fflush(stdin);
		scanf_s("%d", &chosse2);
		switch (chosse2)
		{
		case '1':	
			cout<<endl;
			if(database.connect()){
				database.showMessage(username);
			}
			else
			{
				cout <<endl<< "Loi !!!";
			}
			break;
		case '2': 
			if(database.connect()){
				string receiver="";
				string content="";
				fflush(stdin);
				cout<< "Nhap ten nguoi nhan: ";
				getline(cin, receiver);
				fflush(stdin);
				cout<< "Noi dung tin nhan: ";
				getline(cin, content);
				fflush(stdin);

				database.sendMessage(username, receiver, content);
			}
			else
			{
				cout <<endl<< "Loi !!!";
			}
			break;
		case '3':
			if(database.connect()){
				string Friend="";
				fflush(stdin);
				cout<< "Nhap ten ban be muon them: ";
				getline(cin, Friend);
				fflush(stdin);
				database.addFriend(username,Friend);
			}
			else
			{
				cout<<endl<<"Loi !!!";
			}
			break;
		case '4': 
			if(database.connect()){
				database.listFriend(username);
			}
			else
			{
				cout<<endl<< "Loi !!!";
			}
			break;
		case '5':
			if(database.connect()){
				string block="";
				fflush(stdin);
				cout<< "Nhap ten ban be muon block: ";
				getline(cin, block);
				fflush(stdin);
				database.block(username, block);
			}
			else
			{
				cout<<endl<<"Loi !!!";
			}
			break;
		case '6': 
			if(database.connect()){
				database.showInfo(username);
			}
			else
			{
				cout<<endl<<"Loi !!!";
			}
			break;
		case '7': 
			system("cls");
			break;
		default:
			cout<<endl<< "Chon sai. An mot phim bat ky de chon lai !!!"<<endl;
			_getch();
		}
		if (chosse2=='7')
		{
			break;
		}
	} while (true);
}