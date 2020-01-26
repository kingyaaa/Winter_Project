#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;
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
private:vector<GoodsList> goods;
		vector<GoodsList>sellList;
		vector<vector<GoodsList>>cart;
public:
	Goods();
	~Goods();
};
