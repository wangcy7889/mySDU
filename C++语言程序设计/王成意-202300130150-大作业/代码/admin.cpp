#include "admin.h"
#include "dish.h"
#include <fstream>
#include <iostream>
#include <map>
administrator::administrator(string name, string password)
{
	this->name = name;
	this->password = password;
}

int administrator::deleteNow(string name, string password)
{
	ifstream fin;
	fin.open("admin.txt", ios::in);
	string nowname, nowpassword;
	int check = 0;
	string fileData = "";
	while (fin >> nowname >> nowpassword)
	{
		if (nowname == name)
		{
			check = 1;
			if (nowpassword == password)
			{
				cout << "是否确定删除管理员：" << name << " " << "?(y/n)" << endl;
				char pd_user;
				cin >> pd_user;
				if (pd_user == 'y')
				{
					continue;
				}
				else
				{
					fin.close(), fin.clear();
					return 8;
				}
			}
			else
			{
				cout << "要删除的管理员：" << name << " " << "对应的密码不正确！" << endl;
				cout << "是否重新输入？(y/n)" << endl;
				char pd_user;
				cin >> pd_user;
				if (pd_user == 'y')
				{
					fin.close(), fin.clear();
					return 666;
				}
				else
				{
					fin.close(), fin.clear();
					return 8;
				}
			}
		}
		else
		{
			fileData += nowname + " " + nowpassword + "\n";
		}
	}
	if (!check)
	{
		cout << "待删除的管理员不存在！" << endl;
		cout << "是否重新输入？(y/n)" << endl;
		char pd_user;
		cin >> pd_user;
		if (pd_user == 'y')
		{
			fin.close(), fin.clear();
			return 666;
		}
		else
		{
			fin.close(), fin.clear();
			return 8;
		}
	}
	else
	{
		fileData.erase(fileData.end() - 1);
		fin.close(), fin.clear();
		ofstream fout;
		fout.open("admin.txt", ios::out);
		fout.flush();
		fout << fileData;
		fout.close(), fout.clear();
		return 2;
	}
}

int administrator::addNew(string name, string password)
{
	ofstream fout;
	fout.open("admin.txt", ios::out | ios::app);
	if (!fout.is_open())
	{
		cout << "admin.txt丢失!" << endl;
		return -1;
	}
	else
	{
		ifstream fin;
		fin.open("admin.txt", ios::in);
		string nowname, nowpassword;
		while (fin >> nowname >> nowpassword)
		{
			if (nowname == name)
			{
				cout << "此管理员已存在，请勿重复添加！" << endl;
				cout << "是否重新添加？(y/n)" << endl;
				char pd_cs2;
				cin >> pd_cs2;
				if (pd_cs2 == 'y')
				{
					fout.close(), fout.clear();
					fin.close(), fin.clear();
					return 666;
				}
				else
				{
					return 8;
				}
			}
		}
		fout << endl << name << " " << password;
		return 1;
	}
}

int administrator::changePassword(string name, string password)
{
	ifstream fin;
	fin.open("admin.txt", ios::in);
	string nowname, nowpassword;
	string fileData = "";
	int check = 0;
	while (fin >> nowname >> nowpassword)
	{
		if (nowname == name)
		{
			if (nowpassword == password)
			{
				check = 1;
				string newPassword;
				cout << "请输入新的密码：" << endl;
				cin >> newPassword;
				fileData += nowname + " " + newPassword + "\n";
			}
			else
			{
				cout << "要更改密码的管理员：" << name << " " << "对应的密码不正确！" << endl;
				cout << "是否重新输入？(y/n)" << endl;
				char pd_user;
				cin >> pd_user;
				if (pd_user == 'y')
				{
					fin.close(), fin.clear();
					return 666;
				}
				else
				{
					fin.close(), fin.clear();
					return 8;
				}
			}
		}
		else
		{
			fileData += nowname + " " + nowpassword + "\n";
		}
	}
	if (!check)
	{
		cout << "待修改的管理员不存在！" << endl;
		cout << "是否重新输入？(y/n)" << endl;
		char pd_user;
		cin >> pd_user;
		if (pd_user == 'y')
		{
			fin.close(), fin.clear();
			return 666;
		}
		else
		{
			fin.close(), fin.clear();
			return 8;
		}
	}
	else
	{
		fileData.erase(fileData.end() - 1);
		fin.close(), fin.clear();
		ofstream fout;
		fout.open("admin.txt", ios::out);
		fout.flush();
		fout << fileData;
		fout.close(), fout.clear();
		return 3;
	}
}

int administrator::check_feedback()
{
	ifstream fin;
	fin.open("comments.txt", ios::in);
	if (!fin.is_open())
	{
		return -1;
	}
	else
	{
		system("cls");
		int kind;
		string name = "", adds = "", flavor = "", noodle = "", size = "", feedback = "";
		map<string, string> jl, kw, mt, sz;
		//0：无，1：鸡蛋，2：牛肉，3：鸡肉，4：火腿
		jl["0"] = "无", jl["1"] = "鸡蛋", jl["2"] = "牛肉", jl["3"] = "鸡肉", jl["4"] = "火腿";
		//0：原味, 1：番茄味, 2：麻辣, 3：酸辣, 4：香辣
		kw["0"] = "原", kw["1"] = "番茄", kw["2"] = "麻辣", kw["3"] = "酸辣", kw["4"] = "香辣";
		//0：干拌面，1：汤面，2：炒面
		mt["0"] = "干拌面", mt["1"] = "汤面", mt["2"] = "炒面";
		//0：小份，1：大份
		sz["0"] = "小份", sz["1"] = "大份";
		while (fin >> kind)
		{
			switch (kind)
			{
			case 1://noodles
			{
				fin >> name >> adds >> flavor >> noodle >> feedback;
				cout << "关于加料为 " << jl[adds] << " 的 " << kw[flavor] << "味 " << name << " (" << mt[noodle] << ") 的反馈如下：" << endl;
				cout << feedback << endl << endl;
				break;
			}
			case 2://staple_food
			{
				fin >> name >> feedback;
				cout << "关于" << name << " 的反馈如下：" << endl;
				cout << feedback << endl << endl;
				break;
			}
			case 3://stir_fry
			{
				fin >> name >> size >> feedback;
				cout << "关于 " << sz[size] << " " << name << " 的反馈如下：" << endl;
				cout << feedback << endl << endl;
				break;
			}
			default:
			{
				break;
			}
			}
		}
		cout << "------------------------------------------------" << endl;
		fin.close(), fin.clear();
		system("pause");
		return 6;
	}
}

int administrator::sign_in()
{
	int now = 0, lineCnt = 0;
	string tName, tPassword;
	ifstream fin;
	fin.open("admin.txt", ios::in);
	if (!fin.is_open())
	{
		cout << "admin.txt丢失!" << endl;
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
	fin.open("admin.txt", ios::in);
	for (int now = 0; now <= lineCnt; now++)
	{
		fin >> tName >> tPassword;
		if (tName == this->name)
		{
			if (tPassword == this->password)
			{
				cout << "登陆成功！" << endl;
				fin.close(), fin.clear();
				return 1;
			}
			else
			{
				cout << "密码不正确！是否重新输入？(y/n)" << endl;
				fin.close(), fin.clear();
				return 0;
			}
		}
	}
	cout << "未找到账号！是否重新输入？(y/n)" << endl;
	fin.close(), fin.clear();
	return 0;
}

int administrator::add_dish(noodles eat)
{
	ifstream fin;
	fin.open("noodles.txt", ios::in);
	if (!fin.is_open())
	{
		return -1;
	}
	else
	{
		string name = "", original = "", canteen = "";
		string floor = "", window = "";
		string price = "";
		string adds = "", flavor = "", noodle = "";
		bool exist = 0;
		while (fin >> name >> original >> canteen >> floor >> window >> price >> adds >> flavor >> noodle)
		{
			if (name == eat.getName())
			{
				exist = 1;
				break;
			}
		}
		if (exist)
		{
			cout << " " << endl;
			cout << "此菜色已存在，请勿重复添加！" << endl;
			cout << "是否重新添加？(y/n)" << endl;
			char pd_cs2;
			cin >> pd_cs2;
			if (pd_cs2 == 'y')
			{
				fin.close(), fin.clear();
				return 666;
			}
			else
			{
				fin.close(), fin.clear();
				return 8;
			}
		}
		else
		{
			ofstream fout;
			fout.open("noodles.txt", ios::out | ios::app);
			fout << "\n" << eat.getName() << " " << eat.getOriginals() << " " << eat.getCanteen() << " " << eat.getFloor() << " " << eat.getWindow() << " " << eat.getPrice() << " " << eat.getAdds() << " " << eat.getFlavor() << " " << eat.getNoodle();
			fout.clear(), fout.close();
			return 4;
		}
	}
}

int administrator::add_dish(stir_fry eat)
{
	ifstream fin;
	fin.open("stir_fry.txt", ios::in);
	if (!fin.is_open())
	{
		return -1;
	}
	else
	{
		string name = "", original = "", canteen = "";
		string floor = "", window = "";
		string price = "";
		string size = "";
		bool exist = 0;
		while (fin >> name >> original >> canteen >> floor >> window >> price >> size)
		{
			if (name == eat.getName())
			{
				exist = 1;
				break;
			}
		}
		if (exist)
		{
			cout << " " << endl;
			cout << "此菜色已存在，请勿重复添加！" << endl;
			cout << "是否重新添加？(y/n)" << endl;
			char pd_cs2;
			cin >> pd_cs2;
			if (pd_cs2 == 'y')
			{
				fin.close(), fin.clear();
				return 666;
			}
			else
			{
				fin.close(), fin.clear();
				return 8;
			}
		}
		else
		{
			ofstream fout;
			fout.open("stir_fry.txt", ios::out | ios::app);
			fout << "\n" << eat.getName() << " " << eat.getOriginals() << " " << eat.getCanteen() << " " << eat.getFloor() << " " << eat.getWindow() << " " << eat.getPrice() << " " << eat.getSize();
			fout.clear(), fout.close();
			return 4;
		}
	}
}

int administrator::add_dish(staple_food eat)
{
	ifstream fin;
	fin.open("staple_food.txt", ios::in);
	if (!fin.is_open())
	{
		return -1;
	}
	else
	{
		string name = "", original = "", canteen = "";
		string floor = "", window = "";
		string price = "";
		bool exist = 0;
		while (fin >> name >> original >> canteen >> floor >> window >> price)
		{
			if (name == eat.getName())
			{
				exist = 1;
				break;
			}
		}
		if (exist)
		{
			cout << " " << endl;
			cout << "此菜色已存在，请勿重复添加！" << endl;
			cout << "是否重新添加？(y/n)" << endl;
			char pd_cs2;
			cin >> pd_cs2;
			if (pd_cs2 == 'y')
			{
				fin.close(), fin.clear();
				return 666;
			}
			else
			{
				fin.close(), fin.clear();
				return 8;
			}
		}
		else
		{
			ofstream fout;
			fout.open("staple_food.txt", ios::out | ios::app);
			fout << "\n" << eat.getName() << " " << eat.getOriginals() << " " << eat.getCanteen() << " " << eat.getFloor() << " " << eat.getWindow() << " " << eat.getPrice();
			fout.clear(), fout.close();
			return 4;
		}
	}
}

int administrator::delete_dish(string dish_name)
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
	string feedback = "";
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
		cout << "请确认是否删除菜色： " << dish_name << " ？（y/n）" << endl;
		char pd_user;
		cin >> pd_user;
		if (pd_user == 'y')
		{
			ofstream fout;
			ifstream fin;
			string fileData = "";
			fin.open("noodles.txt", ios::in);
			while (fin >> name >> original >> canteen >> floor >> window >> price >> adds >> flavor >> noodle)
			{
				if (name == dish_name)
				{
					continue;
				}
				else fileData += name + " " + original + " " + canteen + " " + floor + " " + window + " " + price + " " + adds + " " + flavor + " " + noodle + "\n";
			}
			fin.clear(), fin.close();
			fileData.erase(fileData.end() - 1);
			fout.open("noodles.txt", ios::out);
			fout.flush();
			fout << fileData;
			fout.clear(), fout.close();
			//下面是增加的删除评论部分
			fin.open("comments.txt");
			fileData = "";
			int kind;
			while (fin >> kind)
			{
				switch (kind)
				{
				case 1://noodles
				{
					fin >> name >> adds >> flavor >> noodle >> feedback;
					if (name == dish_name) continue;
					else fileData+= "1 " + name + " " + adds + " " + flavor + " " + noodle + " " + feedback + "\n";
					break;
				}
				case 2://staple_food
				{
					fin >> name >> feedback;
					fileData += "2 " + name + " " + feedback + "\n";
					break;
				}
				case 3://stir_fry
				{
					fin >> name >> size >> feedback;
					fileData += "3 " + name + " " + size + " " + feedback + "\n";
					break;
				}
				default:
				{
					break;
				}
				}
			}
			fin.clear(), fin.close();
			fileData.erase(fileData.end() - 1);
			fout.open("comments.txt", ios::out);
			fout.flush();
			fout << fileData;
			fout.clear(), fout.close();
			return 5;
		}
		else
		{
			f2.close(), f2.clear();
			f3.close(), f3.clear();
			return 8;
		}
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
	if(f2.is_open()) f2.close(), f2.clear();
	if (exist)//in stir_fry
	{
		cout << "请确认是否删除菜色： " << dish_name << " ？（y/n）" << endl;
		char pd_user;
		cin >> pd_user;
		if (pd_user == 'y')
		{
			ofstream fout;
			ifstream fin;
			string fileData = "";
			fin.open("stir_fry.txt", ios::in);
			while (fin >> name >> original >> canteen >> floor >> window >> price >> size)
			{
				if (name == dish_name)
				{
					continue;
				}
				else fileData += name + " " + original + " " + canteen + " " + floor + " " + window + " " + price + " " + size + "\n";
			}
			fin.clear(), fin.close();
			fileData.erase(fileData.end() - 1);
			fout.open("stir_fry.txt", ios::out);
			fout.flush();
			fout << fileData;
			fout.clear(), fout.close();
			fin.open("comments.txt");
			fileData = "";
			int kind;
			while (fin >> kind)
			{
				switch (kind)
				{
				case 1://noodles
				{
					fin >> name >> adds >> flavor >> noodle >> feedback;
					fileData+= "1 " + name + " " + adds + " " + flavor + " " + noodle + " " + feedback + "\n";
					break;
				}
				case 2://staple_food
				{
					fin >> name >> feedback;
					fileData += "2 " + name + " " + feedback + "\n";
					break;
				}
				case 3://stir_fry
				{
					fin >> name >> size >> feedback;
					if (name == dish_name) continue;
					else fileData += "3 " + name + " " + size + " " + feedback + "\n";
					break;
				}
				default:
				{
					break;
				}
				}
			}
			fin.clear(), fin.close();
			fileData.erase(fileData.end() - 1);
			fout.open("comments.txt", ios::out);
			fout.flush();
			fout << fileData;
			fout.clear(), fout.close();
			return 5;
		}
		else
		{
			f3.close(), f3.clear();
			return 8;
		}
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
		cout << "请确认是否删除菜色： " << dish_name << " ？（y/n）" << endl;
		char pd_user;
		cin >> pd_user;
		if (pd_user == 'y')
		{
			ofstream fout;
			ifstream fin;
			string fileData = "";
			fin.open("staple_food.txt", ios::in);
			while (fin >> name >> original >> canteen >> floor >> window >> price >> size)
			{
				if (name == dish_name)
				{
					continue;
				}
				else fileData += name + " " + original + " " + canteen + " " + floor + " " + window + " " + price + "\n";
			}
			fin.clear(), fin.close();
			fileData.erase(fileData.end() - 1);
			fout.open("staple_food.txt", ios::out);
			fout.flush();
			fout << fileData;
			fout.clear(), fout.close();
			fin.open("comments.txt");
			fileData = "";
			int kind;
			while (fin >> kind)
			{
				switch (kind)
				{
				case 1://noodles
				{
					fin >> name >> adds >> flavor >> noodle >> feedback;
					if (name == dish_name) continue;
					else fileData+= "1 " + name + " " + adds + " " + flavor + " " + noodle + " " + feedback + "\n";
					break;
				}
				case 2://staple_food
				{
					fin >> name >> feedback;
					fileData += "2 " + name + " " + feedback + "\n";
					break;
				}
				case 3://stir_fry
				{
					fin >> name >> size >> feedback;
					fileData += "3 " + name + " " + size + " " + feedback + "\n";
					break;
				}
				default:
				{
					break;
				}
				}
			}
			fin.clear(), fin.close();
			fileData.erase(fileData.end() - 1);
			fout.open("comments.txt", ios::out);
			fout.flush();
			fout << fileData;
			fout.clear(), fout.close();
			return 5;
		}
		else
		{
			return 8;
		}
	}
	else
	{
		cout << "未找到要删除的菜色！是否重新输入？（y/n）" << endl;
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

int administrator::work(string s)
{
	system("cls");
	cout << s << endl;
	cout << "***************************" << endl;
	cout << "请选择相应功能：" << endl;
	cout << "1.增加管理员" << endl;
	cout << "2.删除管理员" << endl;
	cout << "3.修改管理员密码" << endl;
	cout << "4.增加菜色信息" << endl;
	cout << "5.删除菜色信息" << endl;
	cout << "6.查看菜色反馈" << endl;
	cout << "7.增加用户" << endl;
	cout << "8.删除用户" << endl;
	cout << "9.退出管理员账号" << endl;
	int choose_admin_work;
	cin >> choose_admin_work;
	switch (choose_admin_work)
	{
	case 1://1.增加管理员
	{
	ADD_NEW:
		string newname, newpassword;
		cout << "请输入需要添加的管理员的账号（8位数字）：" << endl;
		cin >> newname;
		cout << "请输入需要添加的管理员的密码（9位数字）：" << endl;
		cin >> newpassword;
		int www = this->addNew(newname, newpassword);
		if (www == 666)
		{
			goto ADD_NEW;
		}
		else return www;
	}
	case 2://2.删除管理员
	{
	DELETE_NOW:
		string newname, newpassword;
		cout << "请输入需要删除的管理员的账号（8位数字）：" << endl;
		cin >> newname;
		if (newname == this->name)
		{
			cout << "是否要删除自己？(y/n)" << endl;
			char pd_user;
			cin >> pd_user;
			if (pd_user == 'y')
			{
				system("cls");
				cout << "删除成功！请重新登录！" << endl;
				ifstream fin;
				fin.open("admin.txt", ios::in);
				string nowname, nowpassword;
				string fileData = "";
				while (fin >> nowname >> nowpassword)
				{
					if (nowname == this->name)
					{
						continue;
					}
					else fileData += nowname + " " + nowpassword + "\n";
				}
				fileData.erase(fileData.end() - 1);
				fin.close(), fin.clear();
				ofstream fout;
				fout.open("admin.txt", ios::out);
				fout.flush();
				fout << fileData;
				fout.close(), fout.clear();
				system("pause");
				return -2;
			}
			else
			{
				return 8;
			}
		}
		cout << "请输入需要删除的管理员的密码（9位数字）：" << endl;
		cin >> newpassword;
		int kkk = this->deleteNow(newname, newpassword);
		if (kkk == 666)
		{
			goto DELETE_NOW;
		}
		else return kkk;
	}
	case 3://3.修改管理员密码
	{
	CHANGE:
		int ck = 0;
		string changename, changepassword;
		cout << "请输入需要修改的管理员的账号（8位数字）：" << endl;
		cin >> changename;
		if (changename == this->name)
		{
			ck = 1;
		}
		cout << "请输入需要修改的管理员的原密码（9位数字）：" << endl;
		cin >> changepassword;
		int kkk = this->changePassword(changename, changepassword);
		if (kkk == 666)
		{
			goto CHANGE;
		}
		else if (kkk != 8 && ck)
		{
			system("cls");
			cout << "管理员密码修改成功!" << endl;
			cout << "您更改了自己的密码，请重新登录！" << endl;
			system("pause");
			return -2;
		}
		else return kkk;
	}
	case 4://4.增加菜色信息
	{
	ADDDISH:
		cout << "***************************" << endl;
		cout << "炒菜类菜色（输入1）" << endl;
		cout << "粉面类菜色（输入2）" << endl;
		cout << "主食类菜色（输入3）" << endl;
		cout << "请选择添加的菜色类别：" << endl;
		int kind;
		cin >> kind;
		if (kind > 3 || kind <= 0)
		{
			cout << "输入错误！是否重新输入？(y/n)" << endl;
			char pd_user;
			cin >> pd_user;
			if (pd_user == 'y')
			{
				goto ADDDISH;
			}
			else
			{
				return 8;
			}
		}
		else
		{
			string name = "", original = "", canteen = "";
			string floor = "", window = "";
			string price = "";
			string adds = "", flavor = "", noodle = "";
			string size = "";
			if (kind == 1)
			{
				cout << "请输入菜色名字：" << endl;
				cin >> name;
				cout << "请输入菜色包含的食材（多个食材请以逗号分隔）：" << endl;
				cin >> original;
				cout << "请输入菜色所在餐厅：" << endl;
				cin >> canteen;
				cout << "请输入菜色所在楼层（数字）：" << endl;
				cin >> floor;
				cout << "请输入菜色所在窗口（数字）：" << endl;
				cin >> window;
				cout << "请输入菜色的价格：" << endl;
				cin >> price;
			SIZE:
				cout << "请输入菜色份量大小（请选择数字，0：小份，1：大份）" << endl;
				cin >> size;
				if (size > "1" || size.size() > 1 || size<"0")
				{
					cout << "请在给定值中选择！" << endl;
					goto SIZE;
				}
				stir_fry eat(name, original, canteen, floor, window, price, size);
				int kkk = this->add_dish(eat);
				if (kkk == 666)
				{
					goto ADDDISH;
				}
				else return kkk;
			}
			else if (kind == 2)
			{
				cout << "请输入粉面名字：" << endl;
				cin >> name;
				cout << "请输入粉面包含的食材（多个食材请以逗号分隔）：" << endl;
				cin >> original;
				cout << "请输入粉面所在餐厅：" << endl;
				cin >> canteen;
				cout << "请输入粉面所在楼层（数字）：" << endl;
				cin >> floor;
				cout << "请输入粉面所在窗口（数字）：" << endl;
				cin >> window;
				cout << "请输入粉面的价格：" << endl;
				cin >> price;
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
				noodles eat(name, original, canteen, floor, window, price, adds, flavor, noodle);
				int kkk = this->add_dish(eat);
				if (kkk == 666)
				{
					goto ADDDISH;
				}
				else return kkk;
			}
			else if (kind == 3)
			{
				cout << "请输入主食名字：" << endl;
				cin >> name;
				cout << "请输入主食包含的食材（多个食材请以逗号分隔）：" << endl;
				cin >> original;
				cout << "请输入主食所在餐厅：" << endl;
				cin >> canteen;
				cout << "请输入主食所在楼层（数字）：" << endl;
				cin >> floor;
				cout << "请输入主食所在窗口（数字）：" << endl;
				cin >> window;
				cout << "请输入主食的价格：" << endl;
				cin >> price;
				staple_food eat(name, original, canteen, floor, window, price);
				int kkk = this->add_dish(eat);
				if (kkk == 666)
				{
					goto ADDDISH;
				}
				else return kkk;
			}
		}
	}
	case 5://5.删除菜色信息
	{
	DELETE_DISH:
		cout << "***************************" << endl;
		cout << "请输入需要删除的菜色的名字：" << endl;
		string dish_name;
		cin >> dish_name;
		int kkk=this->delete_dish(dish_name);
		if (kkk == 666)
		{
			goto DELETE_DISH;
		}
		else return kkk;
	}
	case 6://6.查看菜色反馈
	{
		cout << "***************************" << endl;
		cout << "用户反馈意见如下:" << endl;
		return this->check_feedback();
	}
	case 7://7.增加用户
	{
	ADD_NEW_USER:
		string newname, newpassword, newnum;
		cout << "请输入需要添加的用户的拼音（例：张三一，请输入SanyiZhang）:" << endl;
		cin >> newname;
		cout << "请输入需要添加的用户的账号（学号或职工号）:" << endl;
		cin >> newnum;
		cout << "请输入需要添加的用户的密码（该用户的身份证号后六位）：" << endl;
		cin >> newpassword;
		int www = this->addNew_USER(newname, newnum,newpassword);
		if (www == 666)
		{
			goto ADD_NEW_USER;
		}
		else return www;
	}
	case 8://8.删除用户，8被占用改成88
	{
	DELETE_NOW_USER:
		string nowname;
		cout << "请输入需要删除的用户的拼音（例：张三一，请输入SanyiZhang）：" << endl;
		cin >> nowname;
		int kkk = this->deleteNow_USER(nowname);
		if (kkk == 666)
		{
			goto DELETE_NOW_USER;
		}
		else return kkk;
	}
	case 9://9.退出管理员账号
	{
		return 9;
	}
	}
}

int administrator::addNew_USER(string name, string num, string password)
{
	ofstream fout;
	fout.open("users.txt", ios::out | ios::app);
	if (!fout.is_open())
	{
		cout << "users.txt丢失!" << endl;
		return -1;
	}
	else
	{
		ifstream fin;
		fin.open("users.txt", ios::in);
		string nowname, nowpassword, nownum;
		while (fin >> nowname >> nownum>> nowpassword)
		{
			if (nowname == name)
			{
				cout << "此用户已存在，请勿重复添加！" << endl;
				cout << "是否重新添加？(y/n)" << endl;
				char pd_cs2;
				cin >> pd_cs2;
				if (pd_cs2 == 'y')
				{
					fout.close(), fout.clear();
					fin.close(), fin.clear();
					return 666;
				}
				else
				{
					return 8;
				}
			}
		}
		fout << endl << name << " " << num << " " << password;
		fin.clear(), fin.close();
		fout.clear(), fout.close();
		return 7;
	}
}

int administrator::deleteNow_USER(string name)
{
	ifstream fin;
	fin.open("users.txt", ios::in);
	string nowname, nowpassword, nownum;
	int check = 0;
	string fileData = "";
	while (fin >> nowname >> nownum >> nowpassword)
	{
		if (nowname == name)
		{
			check = 1;
			cout << "是否确定删除用户：" << name << " " << "?(y/n)" << endl;
			char pd_user;
			cin >> pd_user;
			if (pd_user == 'y')
			{
				continue;
			}
			else
			{
				fin.close(), fin.clear();
				return 8;
			}
		}
		else
		{
			fileData += nowname + " " + nownum + " " + nowpassword + "\n";
		}
	}
	if (!check)
	{
		cout << "待删除的用户不存在！" << endl;
		cout << "是否重新输入？(y/n)" << endl;
		char pd_user;
		cin >> pd_user;
		if (pd_user == 'y')
		{
			fin.close(), fin.clear();
			return 666;
		}
		else
		{
			fin.close(), fin.clear();
			return 8;
		}
	}
	else
	{
		fileData.erase(fileData.end() - 1);
		fin.close(), fin.clear();
		ofstream fout;
		fout.open("users.txt", ios::out);
		fout.flush();
		fout << fileData;
		fout.close(), fout.clear();
		return 88;
	}
}

administrator::~administrator()
{
	this->name = "";
	this->password = "";
}