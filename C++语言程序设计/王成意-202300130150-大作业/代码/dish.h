#pragma once
#ifndef DISH_H
#define DISH_H
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
class dish {
private:
	string name;
	string originals;
	string canteen;
	string floor;
	string window;
	string price;
public:
	
	dish(string name, string originals, string canteen, string floor, string window, string price);
	dish(const dish& x);
	~dish();
	string getName() const;
	string getOriginals() const;
	string getCanteen() const;
	string getFloor() const;
	string getWindow() const;
	string getPrice() const;
	void show();
};

class staple_food : public dish
{
public:
	staple_food(string name, string originals, string canteen, string floor, string window, string price);
	staple_food(const staple_food& x);
	int add_feedback();
};

class stir_fry :public dish
{
private:
	string size;
public:
	stir_fry(string name, string originals, string canteen, string floor, string window, string price, string size);
	stir_fry(const stir_fry& x);
	string getSize() const;
	int add_feedback();
};
class noodles :public dish {
private:
	string adds;
	string flavor;
	string noodle;
public:
	noodles(string name, string originals, string canteen, string floor, string window, string price, string adds, string flavor,string noodle);
	noodles(const noodles& x);
	string getAdds() const;
	string getFlavor() const;
	string getNoodle() const;
	int add_feedback();
};
#endif // !DISH_H
