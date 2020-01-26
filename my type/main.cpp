#include "Admin.h"
#include"Goods.h"
#include"customer.h"
void choose();
int main() {
	choose();
	return 0;
}
void choose()
{
	cout << "1,用户登录";
	cout << "       ";
	cout << "2,用户注册";
	cout << "       ";
	cout << "3，管理员登录" << endl;
	int op;
	cin >> op;
	switch (op)
	{
		case 1: {Customer c; c.Login(); break; }
		case 2: {Customer c; c.Register(); break; }
		case 3:
		{ 
			char* id = new char[10];
			char* password = new char[10];
			strcpy(id, "123456789");
			strcpy(password, "123456789");
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
