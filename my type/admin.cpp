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
	cout << "�������ԱID:" << endl;
	cin >> in_id;
	cout << "�������Ա����:" << endl;
	cin >> in_password;
	if (in_id == id && in_password == password)
		cout << "��¼�ɹ���" << endl;
	else
		cout << "�����ID����������" << endl;
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
