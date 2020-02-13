#pragma once
#include"Goods.h"
#include <iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<iomanip>
using namespace std;
struct User
{
	string ID;
	string password;
};
class Customer
{
private:vector<User>userList;
		Goods a;
		char* ID;
		char* password;
public:
	Customer();
	~Customer();
	void Login();
	void Register();
	void Opetion();
	void Logout();
	void CheckGoods();
	void InquireGoods();
	void FootPrint();
	void AddGoodsToCart();
	void DeleteGoodsInCart();
	void CheckCart();
	void SettleAmounts();
	void Order();
	void Title();
};
