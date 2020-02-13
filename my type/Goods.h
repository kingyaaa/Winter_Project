#pragma once
#include <iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<Windows.h>
using namespace std;
void gotoxy(int x, int y);
void star(int size);
void line(int size);
void blank(int size);
struct GoodsList 
{
	string ID;
	string name;
	string brand;
	string price;
	string num;
};
class Goods
{
private:
	vector<GoodsList> goods;//库存.txt
	vector<GoodsList>sellList;//售货清单.txt
	vector<GoodsList>Cart;//user1.txt
	vector<GoodsList>historyOrder;//user1_order.txt
	vector<GoodsList>footPrint;//user1_foot.txt
	friend class Customer;
	friend class Admin;
public:
	Goods();
	~Goods();
};
