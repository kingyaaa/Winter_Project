#include "Customer.h"	
Customer::Customer()
{
	ifstream pfile("用户.txt", ios::in);
	if (!pfile)
		cerr << "文件打开失败！\n";
	string in;
	while (getline(pfile, in))
	{
		istringstream inputString(in);
		User p;
		inputString >> p.ID >> p.password;
		userList.push_back(p);
	}
	pfile.close();
}
Customer::~Customer()
{
	ofstream pfile("用户.txt", ios::out);
	vector<User>::iterator pv;
	for (pv = userList.begin(); pv != userList.end(); pv++)
		pfile << (*pv).ID << " " << (*pv).password << "\n";
	pfile.close();
}
void Customer::Login()
{
	cout << "customer Login" << endl;
	// TODO
	char in_id[20], in_password[20];
	cout << "输入用户ID:" << endl;
	cin >> in_id;
	cout << "输入用户密码:" << endl;
	cin >> in_password;
	vector<User>::iterator pv;
	bool userExisting = 0;
	for (pv = userList.begin(); pv != userList.end(); pv++){
		if (in_id == (*pv).ID && in_password == (*pv).password){
			userExisting = 1; 
			break;
		}
	}
	if(userExisting)
		cout << "登录成功！" << endl;
	else
		cout << "输入的ID或密码有误" << endl;
}
void Customer::Register() 
{
	cout << "customer Register" << endl;
	// TODO
	string  re_id, re_password,repeatPassword;
	cout << "输入用户ID:" << endl;
	cin >> re_id; 
	vector<User>::iterator pv;
	for (pv = userList.begin(); pv != userList.end(); pv++) {
		if (re_id == (*pv).ID) {
			cout << "该用户已存在" << endl;
			return;
		}
	}
	cout << "输入用户密码:" << endl;
	cin >> re_password;
	cout << "请再次输入用户密码:" << endl;
	cin >> repeatPassword;
	while (re_password != repeatPassword) {
		cout << "密码输入错误"<<endl;
		cout << "请重新输入用户密码:" << endl;
		cin >> re_password;
		cout << "请再次输入用户密码:" << endl;
		cin >> repeatPassword;
	}
	if (re_password == repeatPassword){
		cout << "注册成功！den" << endl;
	}
	User n;
	n.ID = re_id;
	n.password = re_password;
	userList.push_back(n);
}
void Customer::Opetion()
{
	int ope;
	cout << "1，注销登录     ";
	cout << "2, 查看商品     ";
	cout << "3, 商品搜索     ";
	cout << "4, 添加商品至购物车     ";
	cout << "5, 删除购物车商品     ";
	cout << "6, 查看购物车     "; 
	cout << "7, 结账     ";
	cout << "8, 历史订单     ";
	cout << "9, 足迹" << endl;
	cin >> ope;
	switch (ope)
	{
	case 1: {Logout(); break; }
	case 2: {CheckGoods(); break; }
	case 3: {InquireGoods(); break; }
	case 4: {AddGoodsToCart(); break; }
	case 5: {DeleteGoodsInCart(); break; }
	case 6: {CheckCart(); break; }
	case 7: {SettleAmounts(); break; }
	case 8: {Order(); break; }
	case 9: {FootPrint(); break; }
	default:
		break;
	}
}
void Customer::Logout()
{
}
void Customer::CheckGoods()
{

}
void Customer::InquireGoods()//与admin相同
{
}
void Customer::FootPrint()
{
}
void Customer::AddGoodsToCart()
{
}
void Customer::DeleteGoodsInCart()
{
}
void Customer::CheckCart()
{
}
void Customer::SettleAmounts()
{
}
void Customer::Order()
{

}