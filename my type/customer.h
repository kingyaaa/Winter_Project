#pragma once
#include"Goods.h"
#include <iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;
struct User
{
	string ID;
	string password;
};
class Customer
{
	Goods g;
private:vector<User>userList;
public:
	Customer();
	~Customer();
	void Login();
	void Register();
	void Opetion();
	void Logout();
	void CheckGoods();
	void InquireGoods();//”Îadminœ‡Õ¨
	void FootPrint();
	void AddGoodsToCart();
	void DeleteGoodsInCart();
	void CheckCart();
	void SettleAmounts();
	void Order();
};
