#pragma once
#include"Goods.h"
#include <iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#define ADMIN_ID_MAX 100
#define ADMIN_PASSWORD_MAX 100
using namespace std;
class Admin
{
private:
	char* id;
	char* password;
	Goods a;
public:
	Admin();
	Admin(char* cid, char* cpassword);
	void Opetion();
	void Title();
	void Login();
	void Logout();
	void InquireGoods();
	void AddGoods();
	void DeleteGoods();
	void ModifyGoodsNum();
	void InquireSaleList();
	void HotList();
	void UnpopList();
	void SupplyAlarm();
	~Admin();
};
