#pragma once
#ifndef ADMIN_H
#define ADMIN_H
#include<string>
#include<cstring>
#include"dish.h"
using namespace std;
class administrator {
private:
	string name;
	string password;
public:
	administrator(string name, string password);
	int deleteNow(string name,string password);
	int addNew(string name, string password);
	int changePassword(string name, string password);
	int check_feedback();
	int sign_in();
	int add_dish(noodles eat);
	int add_dish(stir_fry eat);
	int add_dish(staple_food eat);
	int delete_dish(string dish_name);
	int work(string s);
	int addNew_USER(string name, string num, string password);
	int deleteNow_USER(string name);
	~administrator();
};

#endif // !ADMIN_H
