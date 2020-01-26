#pragma once
#include"Goods.h"
#include <iostream>
#define ADMIN_ID_MAX 100
#define ADMIN_PASSWORD_MAX 100
using namespace std;
class Admin
{
	Goods g;
private:
	char* id;
	char* password;
public:
	Admin();
	Admin(char* cid, char* cpassword);
	void Login();
	void Logout();
	void InquireGoods();
	void AddGoods();
	void DeleteGoods();
	void ModifyGoodsNum();
	void InquireSaleList();
	~Admin();
};