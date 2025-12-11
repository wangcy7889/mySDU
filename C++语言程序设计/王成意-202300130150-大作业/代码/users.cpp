#include "users.h"
#include "dish.h"
#include<iostream>
#include <fstream>
#include<stdlib.h>
user::user(string name, string account, string password)
{
	this->name = name;
	this->account = account;
	this->password = password;
}

int user::sign_in()
{
	int now = 0, lineCnt = 0;
	string tName, tAccount, tPassword;
	ifstream fin;
	fin.open("users.txt", ios::in);
	if (!fin.is_open())
	{
		cout << "users.txt丢失!" << endl;
		return -1;
	}
	char c;
	while (fin.get(c))
	{
		if (c == '\n')
			lineCnt++;
	};
	lineCnt++;
	fin.close(), fin.clear();
	fin.open("users.txt", ios::in);
	for (int now = 0; now <= lineCnt; now++)
	{
		fin >> tName >> tAccount >> tPassword;
		if (tName == this->name && tAccount == this->account)
		{
			if (tPassword == this->password)
			{
				cout << "登陆成功！" << endl;
				return 1;
			}
			else
			{
				cout << "密码不正确！是否重新输入？(y/n)" << endl;
				return 0;
			}
		}
	}
	cout << "未找到用户！是否重新输入？(y/n)" << endl;
	return 0;
}

int user::browse_dish()
{
	system("cls");
	ifstream f1, f2, f3;
	cout << "----------------- 餐厅现有菜色：-----------------" << endl;
	cout << "炒菜类" << endl;
	f1.open("stir_fry.txt", ios::in);
	f2.open("noodles.txt", ios::in);
	f3.open("staple_food.txt", ios::in);
	if (!f1.is_open() || !f2.is_open() || !f3.is_open())
	{
		return -1;
	}
	else
	{
		string name = "", original = "", canteen = "";
		string floor = "", window = "";
		string price = "";
		string adds = "", flavor = "", noodle = "", size = "";
		while (f1 >> name >> original >> canteen >> floor >> window >> price >> size)
		{
			stir_fry tmp(name, original, canteen, floor, window, price, size);
			tmp.show();
		}
		f1.close(), f1.clear();
		cout << "粉面类" << endl;
		while (f2 >> name >> original >> canteen >> floor >> window >> price >> adds >> flavor >> noodle)
		{
			noodles tmp(name, original, canteen, floor, window, price, adds, flavor, noodle);
			tmp.show();
		}
		f2.close(), f2.clear();
		cout << "主食类" << endl;
		while (f3 >> name >> original >> canteen >> floor >> window >> price)
		{
			staple_food tmp(name, original, canteen, floor, window, price);
			tmp.show();
		}
		f3.close(), f3.clear();
		cout << "------------------------------------------------" << endl;
		system("pause");
		return 1;
	}
}

int user::search_dish(string dish_name)
{
	ifstream f1, f2, f3;
	bool exist = 0;
	f1.open("noodles.txt", ios::in);
	f3.open("staple_food.txt", ios::in);
	f2.open("stir_fry.txt", ios::in);
	if (!f1.is_open() || !f2.is_open() || !f3.is_open())
	{
		return -1;
	}
	string name = "", original = "", canteen = "";
	string floor = "", window = "";
	string price = "";
	string adds = "", flavor = "", noodle = "", size = "";
	while (f1 >> name >> original >> canteen >> floor >> window >> price >> adds >> flavor >> noodle)
	{
		if (dish_name == name)
		{
			exist = 1;
			f1.clear(), f1.close();
			break;
		}
	}
	if (f1.is_open()) f1.clear(), f1.close();
	if (exist)//in noodles
	{
		ifstream fin;
		fin.open("noodles.txt", ios::in);
		while (fin >> name >> original >> canteen >> floor >> window >> price >> adds >> flavor >> noodle)
		{
			if (name == dish_name)
			{
				noodles tmp(name, original, canteen, floor, window, price, adds, flavor, noodle);
				cout << "您查询的菜色信息如下：" << endl;
				tmp.show();
				break;
			}
		}
		f2.close(), f2.clear();
		f3.close(), f3.clear();
		fin.close(), fin.clear();
		cout << "------------------------------------------------" << endl;
		system("pause");
		return 2;
	}
	else
	{
		while (f2 >> name >> original >> canteen >> floor >> window >> price >> size)
		{
			if (dish_name == name)
			{
				exist = 1;
				f2.close(), f2.clear();
				break;
			}
		}
	}
	if (f2.is_open()) f2.close(), f2.clear();
	if (exist)//in stir_fry
	{
		ifstream fin;
		fin.open("stir_fry.txt", ios::in);
		while (fin >> name >> original >> canteen >> floor >> window >> price >> size)
		{
			if (name == dish_name)
			{
				stir_fry tmp(name, original, canteen, floor, window, price, size);
				cout << "您查询的菜色信息如下：" << endl;
				tmp.show();
				break;
			}
		}
		f3.close(), f3.clear();
		fin.close(), fin.clear();
		cout << "------------------------------------------------" << endl;
		system("pause");
		return 2;
	}
	else
	{
		while (f3 >> name >> original >> canteen >> floor >> window >> price)
		{
			if (dish_name == name)
			{
				exist = 1;
				f3.close(), f3.clear();
				break;
			}
		}
	}
	if (f3.is_open()) f3.close(), f3.clear();
	if (exist)//in staple_food
	{
		ifstream fin;
		fin.open("staple_food.txt", ios::in);
		while (fin >> name >> original >> canteen >> floor >> window >> price)
		{
			if (name == dish_name)
			{
				staple_food tmp(name, original, canteen, floor, window, price);
				cout << "您查询的菜色信息如下：" << endl;
				tmp.show();
				break;
			}
		}
		fin.close(), fin.clear();
		cout << "------------------------------------------------" << endl;
		system("pause");
		return 2;
	}
	else
	{
		cout << "未找到要查询的菜色！是否重新输入？（y/n）" << endl;
		char pd_user;
		cin >> pd_user;
		if (pd_user == 'y')
		{
			return 666;
		}
		else
		{
			return 8;
		}
	}
}

int user::feedback(string dish_name)
{
	ifstream f1, f2, f3;
	bool ex1 = 0, ex2 = 0, ex3 = 0;
	f1.open("noodles.txt", ios::in);
	f2.open("staple_food.txt", ios::in);
	f3.open("stir_fry.txt", ios::in);
	if (!f1.is_open() || !f2.is_open() || !f3.is_open())
	{
		return -1;
	}
	else
	{
		string name = "", original = "", canteen = "";
		string floor = "", window = "";
		string price = "";
		string adds = "", flavor = "", noodle = "", size = "";
		while (f1 >> name >> original >> canteen >> floor >> window >> price >> adds >> flavor >> noodle)
		{
			if (dish_name == name)
			{
				ex1 = 1;
			ADDS:
				cout << "请输入加料名字（请选择数字，0：无，1：鸡蛋，2：牛肉，3：鸡肉，4：火腿）：" << endl;
				cin >> adds;
				if (adds > "4" || adds < "0" || adds.size() > 1)
				{
					cout << "请在给定值中选择！" << endl;
					goto ADDS;
				}
			FLAVOR:
				cout << "请输入口味名字（请选择数字，0：原味, 1：番茄味, 2：麻辣, 3：酸辣, 4：香辣）" << endl;
				cin >> flavor;
				if (flavor > "4" || flavor < "0" || flavor.size() > 1)
				{
					cout << "请在给定值中选择！" << endl;
					goto FLAVOR;
				}
			NOODLE:
				cout << "请输入粉面的形式（请选择数字，0：干拌面，1：汤面，2：炒面）" << endl;
				cin >> noodle;
				if (noodle < "0" || noodle > "2" || noodle.size() > 1)
				{
					cout << "请在给定值中选择！" << endl;
					goto NOODLE;
				}
				noodles tmp(name, original, canteen, floor, window, price, adds, flavor, noodle);
				return tmp.add_feedback();
			}
		}
		while (f2 >> name >> original >> canteen >> floor >> window >> price)
		{
			if (dish_name == name)
			{
				ex2 = 1;
				staple_food tmp(name, original, canteen, floor, window, price);
				return tmp.add_feedback();
			}
		}
		while (f3 >> name >> original >> canteen >> floor >> window >> price >> size)
		{
			if (name == dish_name)
			{
				ex3 = 1;
			SIZE:
				cout << "请输入菜色份量大小（请选择数字，0：小份，1：大份）" << endl;
				cin >> size;
				if (size > "1" || size.size() > 1 || size < "0")
				{
					cout << "请在给定值中选择！" << endl;
					goto SIZE;
				}
				stir_fry tmp(name, original, canteen, floor, window, price, size);
				return tmp.add_feedback();
			}
		}
		if ((ex1 | ex2 | ex3) == 0)
		{
			cout << "未找到要反馈的菜色！是否重新输入？（y/n）" << endl;
			char pd_user;
			cin >> pd_user;
			if (pd_user == 'y')
			{
				return 666;
			}
			else
			{
				return 8;
			}
		}
	}
}

int user::work(string s)
{
	system("cls");
	cout << s << endl;
	cout << "请选择相应功能(请输入相应数字)：" << endl;
	cout << "1.浏览所有菜色信息" << endl;
	cout << "2.查询菜色" << endl;
	cout << "3.提交菜色反馈意见" << endl;
	cout << "4.修改密码" << endl;
	cout << "5.退出登录" << endl;
	int choose_user_work;
	cin >> choose_user_work;
	switch (choose_user_work)
	{
	case 1://1.查看所有菜色信息
	{
		int kkk = this->browse_dish();
		return kkk;
	}
	case 2://2.查询菜色
	{
	SEARCH_DISH:
		system("cls");
		cout << "***************************" << endl;
		cout << "请输入需要查询的菜色的名字：" << endl;
		string dish_name;
		cin >> dish_name;
		int kkk = this->search_dish(dish_name);
		if (kkk == 666)
		{
			goto SEARCH_DISH;
		}
		else return kkk;
		break;
	}
	case 3://3.提交菜色反馈意见
	{
	FEEDBACK:
		system("cls");
		cout << "***************************" << endl;
		cout << "请输入您要评价的菜色名：" << endl;
		string dish_name;
		cin >> dish_name;
		int kkk = this->feedback(dish_name);
		if (kkk == 666)
		{
			goto FEEDBACK;
		}
		else return kkk;
		break;
	}
	case 4://4.修改密码
	{
	CHANGE:
		cout << "请输入原来的密码：" << endl;
		string nowpassword;
		cin >> nowpassword;
		if (nowpassword != this->password)
		{
			cout << "原密码错误！" << endl;
			cout << "是否重新输入？(y/n)" << endl;
			char pd_user;
			cin >> pd_user;
			if (pd_user == 'y')
			{
				goto CHANGE;
			}
			else
			{
				return 8;
			}
		}
		else
		{
			cout << "请输入新密码：" << endl;
			string newpassword;
			cin >> newpassword;
			this->changepassword(newpassword);
			system("cls");
			cout << "修改密码成功，请重新登录！" << endl;
			system("pause");
			return 4;
		}
		break;
	}
	case 5://5.退出登录
	{
		return 5;
		break;
	}
	default:
		break;
	}
}

void user::changepassword(string newpassword)
{
	ifstream fin;
	fin.open("users.txt", ios::in);
	string nowname, nowaccount, nowpassword;
	string filedata = "";
	while (fin >> nowname >> nowaccount >> nowpassword)
	{
		if (nowname == this->name && nowaccount == this->account)
		{
			filedata += nowname + " " + nowaccount + " " + newpassword + "\n";
		}
		else
		{
			filedata += nowname + " " + nowaccount + " " + nowpassword + "\n";
		}
	}
	fin.clear(), fin.close();
	ofstream fout;
	fout.open("users.txt", ios::out);
	fout.flush();
	filedata.erase(filedata.end() - 1);
	fout << filedata;
	fout.clear(), fout.close();
}

user::~user()
{
	this->name = "";
	this->password = "";
	this->account = "";
}
