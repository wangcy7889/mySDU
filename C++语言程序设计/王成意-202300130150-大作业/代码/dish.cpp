#include "dish.h"
#include <fstream>
dish::dish(string name, string originals, string canteen, string floor, string window, string price)
{
	this->name = name;
	this->canteen = canteen;
	this->originals = originals;
	this->floor = floor;
	this->window = window;
	this->price = price;
}

dish::dish(const dish& x)
{
	this->name = x.name;
	this->canteen = x.canteen;
	this->window = x.window;
	this->floor = x.floor;
	this->price = x.price;
	this->originals = x.originals;
}

dish::~dish()
{

}

string dish::getName() const
{
	return this->name;
}

string dish::getOriginals() const
{
	return this->originals;
}

string dish::getCanteen() const
{
	return this->canteen;
}

string dish::getFloor() const
{
	return this->floor;
}

string dish::getWindow() const
{
	return this->window;
}

string dish::getPrice() const
{
	return this->price;
}

void dish::show()
{
	cout << "菜色名称：" << this->name << "   ";
	cout << "菜色原料：" << this->originals << endl;
	cout << "所在餐厅：" << this->canteen << "   ";
	cout << "所在楼层：" << this->floor << endl;
	cout << "所在窗口：" << this->window << "   ";
	cout << "菜色价格：" << this->price << endl;
	cout << endl;
}

noodles::noodles(string name, string originals, string canteen, string floor, string window, string price, string adds, string flavor,string noodle):dish(name,originals,canteen,floor,window,price)
{
	this->adds = adds;
	this->flavor = flavor;
	this->noodle = noodle;
}

noodles::noodles(const noodles& x):dish(x)
{
	this->adds = x.adds;
	this->flavor = x.flavor;
	this->noodle = x.noodle;
}

string noodles::getAdds() const
{
	return this->adds;
}

string noodles::getFlavor() const
{
	return this->flavor;
}

string noodles::getNoodle() const
{
	return this->noodle;
}

int noodles::add_feedback()
{
	cout << "请输入您的反馈：" << endl;
	string feedback;
	cin >> feedback;
	ofstream fout;
	fout.open("comments.txt", ios::out | ios::app);
	if (!fout.is_open())
	{
		return -1;
	}
	else
	{
		fout << "\n" << 1 << " " << this->getName() << " " << this->adds << " " << this->flavor << " " << this->noodle << " " << feedback;
		fout.close(), fout.clear();
		return 3;
	}
	return 0;
}

staple_food::staple_food(string name, string originals, string canteen, string floor, string window, string price):dish(name, originals, canteen, floor, window, price)
{
	
}

staple_food::staple_food(const staple_food& x):dish(x)
{

}

int staple_food::add_feedback()
{
	cout << "请输入您的反馈：" << endl;
	string feedback;
	cin >> feedback;
	ofstream fout;
	fout.open("comments.txt", ios::out | ios::app);
	if (!fout.is_open())
	{
		return -1;
	}
	else
	{
		fout << "\n" << 2 << " " << this->getName() << " " << feedback;
		fout.close(), fout.clear();
		return 3;
	}
}

stir_fry::stir_fry(string name, string originals, string canteen, string floor, string window, string price, string size) :dish(name, originals, canteen, floor, window, price)
{
	this->size = size;
}

stir_fry::stir_fry(const stir_fry& x):dish(x)
{
	this->size = x.size;
}

string stir_fry::getSize() const
{
	return this->size;
}

int stir_fry::add_feedback()
{
	cout << "请输入您的反馈：" << endl;
	string feedback;
	cin >> feedback;
	ofstream fout;
	fout.open("comments.txt", ios::out | ios::app);
	if (!fout.is_open())
	{
		return -1;
	}
	else
	{
		fout << "\n" << 3 << " " << this->getName() << " " << this->size << " " << feedback;
		fout.close(), fout.clear();
		return 3;
	}
}
