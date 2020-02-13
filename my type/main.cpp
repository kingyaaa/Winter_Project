#include"Goods.h"
#include"customer.h"
#include"admin.h"
#include<iostream>
using namespace std;
void choose();
int main() {
	while (1) {
		choose();
	}
}
void choose()
{
	line(50);
	cout << "1,用户登录";
	cout << "       ";
	cout << "2,用户注册";
	cout << "       ";
	cout << "3，管理员登录" << endl;
	line(50);
	cout << "输入操作:";
	int op;
	cin >> op;
	switch (op)
	{
		case 1: {Customer c; c.Login(); break; }
		case 2: {Customer c; c.Register(); break; }
		case 3:
		{ 
			char* id = new char[100];
			char* password = new char[100];
			strcpy_s(id,100, "123456");
			strcpy_s(password,100, "123456");
			Admin a(id, password);
			a.Login();
			delete[]id;
			delete[]password;
			break;
		}
		default:
			break;
	}
}
