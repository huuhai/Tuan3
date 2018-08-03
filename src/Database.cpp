#include "stdafx.h"
#include "Database.h"

Database::Database(void)
{
}


Database::~Database(void)
{
}

bool Database::connect()
{
	rc = sqlite3_open("CoSoDuLieu.db", &database);
	if (rc)
	{	   
		sqlite3_close(database);
		return false;
	}
	else{
		return true;
	}
}

void Database::signUp(User user)
{
	/*User user;
	user.nhap();*/
	if(!check(user.username, user.password)){
		string query = "INSERT INTO AccountInfo(username, password, fullname, birthday, sex, address) VALUES('"+user.username+"', '"+user.password+"' ,'"+user.fullname+"', '"+user.birthday+"', '"+user.sex+"', '"+user.address+"')";
		rc = sqlite3_exec(database, query.c_str(),sqlite3_callback(),0, &zErrMsg);
		if( rc != SQLITE_OK ){
			fprintf(stderr, "\n\tSQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
			sqlite3_close(database);
		}
		else{
			fprintf(stdout, "\n\t\tThem thanh cong !!!\n");
			sqlite3_close(database);
		}
	}
	else
	{
		cout<<endl<<"\tDa ton tai trong database. Chon tai khoan khac !!!"<<endl;
		sqlite3_close(database);
	}
}

void Database::logIn(string username, string password){
	/*User user;
	user.nhap();*/
	Menu menu;
	system("cls");
	if(check(username, password)){
		menu.choice2(username,password);
	}
	else
	{
		cout<<endl<<"Dang nhap ko thanh cong !!!"<<endl;
		sqlite3_close(database);
	}
}

bool Database::check(string username, string password){
	string sql = "select username, password from AccountInfo where username = '"+username+"' and password = '"+password+"'";
	SQLITE_CALLBACK (sqlite3_prepare_v2 (database, sql.c_str(), sql.length() + 1, &stmt, NULL));
	int row = 0;
	while (1) {
		int s;
		s = sqlite3_step (stmt);
		if (s == SQLITE_ROW) {
			int bytes;
			const unsigned char * text1;
			const unsigned char * text2;
			bytes = sqlite3_column_bytes (stmt, 0);
			text1  = sqlite3_column_text (stmt, 0);
			text2  = sqlite3_column_text (stmt, 1);
			//printf ("%s: %s\n", text1, text2);
			return true;
			row++;
		}
		else if (s == SQLITE_DONE) {
			return false;
			break;
		}
		else {
			fprintf (stderr, "Failed.\n");
			exit (1);
		}
	}
}

void Database::addFriend(string username, string Friend){
	if(!check(Friend)){
		cout<<endl<<"Tai khoan ko ton tai hoac da bi xoa !!!"<<endl;	
	}
	else
	{
		string query = "INSERT INTO Friend(friend, username) VALUES ('"+Friend+"', '"+username+"')";
		rc = sqlite3_exec(database, query.c_str(),sqlite3_callback(),0, &zErrMsg);
		if( rc != SQLITE_OK ){
			fprintf(stderr, "\n\tSQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
			sqlite3_close(database);
		}
		else{
			fprintf(stdout, "\n\t\tThem thanh cong !!!\n");
			sqlite3_close(database);
		}
	}
}

void Database::listFriend(string username){
	if(check(username)){
		string query = "select friend from Friend where username ='"+username+"'";
		SQLITE_CALLBACK (sqlite3_prepare_v2 (database, query.c_str(), query.length() + 1, &stmt, NULL));
		int row = 0;
		while (1) {
			int s;
			s = sqlite3_step (stmt);
			if (s == SQLITE_ROW) {
				int bytes;
				const unsigned char * text0;
				bytes = sqlite3_column_bytes (stmt, 0);
				text0  = sqlite3_column_text (stmt, 0);
				printf ("\tfriend: %s\n", text0);
				row++;
			}
			else if (s == SQLITE_DONE) {
				break;
				sqlite3_close(database);
			}
			else {
				sqlite3_close(database);
				fprintf (stderr, "Failed.\n");
				exit (1);
			}
		}
	}
	else
	{
		cout<<endl<<"Tai khoan ko ton tai hoac da bi xoa !!!"<<endl;
	}
}

bool Database::check(string username){
	string sql = "select username from AccountInfo where username = '"+username+"'";
	SQLITE_CALLBACK (sqlite3_prepare_v2 (database, sql.c_str(), sql.length() + 1, &stmt, NULL));
	int row = 0;
	while (1) {
		int s;
		s = sqlite3_step (stmt);
		if (s == SQLITE_ROW) {
			int bytes;
			const unsigned char * text1;
			bytes = sqlite3_column_bytes (stmt, 0);
			text1  = sqlite3_column_text (stmt, 0);
			return true;
			row++;
		}
		else if (s == SQLITE_DONE) {
			return false;
			break;
		}
		else {
			sqlite3_close_v2(database);
			fprintf (stderr, "Failed.\n");
			exit (1);
		}
	}
}

void Database::sendMessage(string sender, string receiver, string content){
	if(!check(receiver)){
		cout<<endl<<"Tai khoan ko ton tai hoac da bi xoa !!!"<<endl;
		sqlite3_close(database);
	}
	else
	{
		string query = "INSERT INTO Message(sender, receiver, content) VALUES ('"+sender+"','"+receiver+"','"+content+"')";
		rc = sqlite3_exec(database, query.c_str(),sqlite3_callback(),0, &zErrMsg);
		if( rc != SQLITE_OK ){
			fprintf(stderr, "\n\tSQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
			sqlite3_close(database);
		}
		else{
			fprintf(stdout, "\n\t\tThem thanh cong !!!\n");
			sqlite3_close(database);
		}
	}
}

void Database::block(string username, string block){
	if(!check(block)){
		cout<<endl<<"Tai khoan ko ton tai hoac da bi xoa !!!"<<endl;
		sqlite3_close(database);
	}
	else
	{
		string query = "delete from Friend where username ='"+username+"' and friend = '"+block+"'";
		rc = sqlite3_exec(database, query.c_str(),sqlite3_callback(),0, &zErrMsg);
		if( rc != SQLITE_OK ){
			fprintf(stderr, "\n\tSQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
			sqlite3_close(database);
		}
		else{
			fprintf(stdout, "\n\t\tThem thanh cong !!!\n");
			sqlite3_close(database);
		}
	}
}

void Database::showMessage(string username){
	string sql = "select receiver, content from Message where sender = '"+username+"'";
	SQLITE_CALLBACK (sqlite3_prepare_v2 (database, sql.c_str(), sql.length() + 1, &stmt, NULL));
	int row = 0;
	while (1) {
		int s;
		s = sqlite3_step (stmt);
		if (s == SQLITE_ROW) {
			int bytes;
			const unsigned char* text0;
			const unsigned char* text1;
			bytes = sqlite3_column_bytes (stmt, 0);
			text0  = sqlite3_column_text (stmt, 0);
			text1  = sqlite3_column_text (stmt, 1);
			printf ("receiver: %s \tcontent: %s\n", text0, text1);
			row++;
		}
		else if (s == SQLITE_DONE) {
			break;
			sqlite3_close(database);
		}
		else {
			sqlite3_close_v2(database);
			fprintf (stderr, "Failed.\n");
			exit (1);
		}
	}
}

void Database::showInfo(string username){
	string sql = "select * from AccountInfo where username = '"+username+"'";
	SQLITE_CALLBACK (sqlite3_prepare_v2 (database, sql.c_str(), sql.length() + 1, &stmt, NULL));
	int row = 0;
	while (1) {
		int s;
		s = sqlite3_step (stmt);
		if (s == SQLITE_ROW) {

			int bytes;
			const unsigned char * text0;
			const unsigned char * text1;
			const unsigned char * text2;
			const unsigned char * text3;
			const unsigned char * text4;
			const unsigned char * text5;

			bytes = sqlite3_column_bytes (stmt, 0);
			text0  = sqlite3_column_text (stmt, 0);
			text1  = sqlite3_column_text (stmt, 1);
			text2  = sqlite3_column_text (stmt, 2);
			text3  = sqlite3_column_text (stmt, 3);
			text4  = sqlite3_column_text (stmt, 4);
			text5  = sqlite3_column_text (stmt, 5);

			printf ("\nusername: %s\npassword: %s\nfullname: %s\nbirthday: %s\nsex: %s\naddress: %s\n", text0, text1, text2, text3, text4, text5);
			row++;
		}
		else if (s == SQLITE_DONE) {
			break;
		}
		else {
			sqlite3_close_v2(database);
			fprintf (stderr, "Failed.\n");
			exit (1);
		}
	}
}