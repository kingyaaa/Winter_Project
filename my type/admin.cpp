#include "Admin.h"



Admin::Admin() {
	id = new char[ADMIN_ID_MAX];
	password = new char[ADMIN_PASSWORD_MAX];
}
Admin::Admin(char* cid, char* cpassword) {
	id = new char[strlen(cid) + 1];
	password = new char[strlen(cpassword) + 1];
	strcpy(id, cid);
	strcpy(password, cpassword);
}

void Admin::Login() {
	cout << "Admin Login" << endl;
	// TODO
	char in_id[20], in_password[20];
	cout << "输入管理员ID:" << endl;
	cin >> in_id;
	cout << "输入管理员密码:" << endl;
	cin >> in_password;
	if (in_id == id && in_password == password)
		cout << "登录成功！" << endl;
	else
		cout << "输入的ID或密码有误" << endl;
}
void Admin::Logout() {
	// TODO
}
void Admin::InquireGoods() {
	// TODO
}
void Admin::AddGoods() {
	// TODO
}
void Admin::DeleteGoods() {
	// TODO
}
void Admin::ModifyGoodsNum() {
	// TODO
}
void Admin::InquireSaleList() {
	// TODO
}

Admin::~Admin() {
	delete[]id;
	delete[]password;
}
