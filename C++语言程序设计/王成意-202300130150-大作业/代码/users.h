#pragma once
#ifndef USERS_H
#define USERS_H


#include<string>
using namespace std;
class user {
private:
	string name;
	string account;
	string password;
public:
	user(string name, string account, string password);
	int sign_in();
	int browse_dish();
	int search_dish(string dish_name);
	int feedback(string dish_name);
	int work(string s);
	void changepassword(string nowpassword);
	~user();
};

#endif // !USERS_H
