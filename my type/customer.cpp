#include "Customer.h"	
Customer::Customer()
{
	ID = 0, password = 0;
	ifstream pfile("用户.txt", ios::in);
	if (!pfile)
		cerr << "文件打开失败！\n";
	string t;
	while (getline(pfile, t))
	{
		istringstream inputString(t);
		User p;
		inputString >> p.ID >> p.password;
		userList.push_back(p);
	}
	pfile.close();
}
Customer::~Customer()
{
	ofstream p1file("用户.txt", ios::out);
	vector<User>::iterator pv;
	for (pv = userList.begin(); pv != userList.end(); pv++)
		p1file << (*pv).ID << " " << (*pv).password << "\n";
	p1file.close();
}
void Customer::Login()
{
	cout << "customer Login" << endl;
	// TODO
	char in_id[20], in_password[20];
	cout << "输入用户ID:";
	cin >> in_id;
	cout << "输入用户密码:";
	cin >> in_password;
	vector<User>::iterator pv;
	bool userExisting = 0;
	for (pv = userList.begin(); pv != userList.end(); pv++) {
		if (in_id == (*pv).ID && in_password == (*pv).password) {
			userExisting = 1;
			ID = in_id;
			password = in_password;
			break;
		}
	}
	if (userExisting) {
		star(20);
		cout << "登录成功！" << endl;
		//用户登录的同时导入购物车文件；
		char data1_name[50] = { 0 };
		sprintf_s(data1_name, "%s%s", in_id, ".txt");
		ifstream p1file(data1_name, ios::in);
		if (!p1file.is_open())
			cerr << "购物车文件创建中...\n";
		string o;
		while (getline(p1file, o))
		{
			istringstream inputString(o);
			GoodsList p;
			inputString >> p.ID >> p.name >> p.brand >> p.price >> p.num;
			a.Cart.push_back(p);
		}
		p1file.close();
		//建立
		char data2_name[50] = { 0 };
		sprintf_s(data2_name, "%s%s", in_id, "_order.txt");
		ifstream p2file(data2_name, ios::in);
		if (!p2file.is_open())
			cerr << "历史订单文件创建中...！\n";
		string n;
		while (getline(p2file, n))
		{
			istringstream inputString(n);
			GoodsList p;
			inputString >> p.ID >> p.name >> p.brand >> p.price >> p.num;
			a.historyOrder.push_back(p);
		}
		p2file.close();

		char data3_name[50] = { 0 };
		sprintf_s(data3_name, "%s%s", in_id, "_foot.txt");
		ifstream p3file(data3_name, ios::in);
		if (!p3file.is_open())
			cerr << "足迹文件创建中...！\n";
		string m;
		while (getline(p3file, m))
		{
			istringstream inputString(m);
			GoodsList p;
			inputString >> p.ID >> p.name >> p.brand >> p.price >> p.num;
			a.footPrint.push_back(p);
		}
		p3file.close();

		star(20);
		Sleep(1000);
		system("cls");
		Opetion();
	}
	else {
		cout << "输入的ID或密码有误,请注册账号或重新登录" << endl;
		Sleep(1000);
		system("cls");
	}
}
void Customer::Register() 
{
	cout << "customer Register" << endl;
	// TODO
	char re_id[20],re_password[20],repeatPassword[20];
	cout << "输入用户ID:";
	cin >> re_id; 
	vector<User>::iterator pv;
	for (pv = userList.begin(); pv != userList.end(); pv++) {
		if (re_id == (*pv).ID) {
			cout << "该用户已存在" << endl;
			Sleep(1000);
			system("cls");
			return;
		}
	}
	cout << "输入用户密码:";
	cin >> re_password;
	cout << "请再次输入用户密码:";
	cin >> repeatPassword;
	while (strcmp(re_password,repeatPassword)!=0) {
		gotoxy(0, 6);
		cout << "密码输入错误";
		blank(40);
		cout << endl; 
		blank(40);
		gotoxy(0, 7);
		cout << "请重新输入用户密码:";
		cin >> re_password;
		cout << "请再次输入用户密码:";
		cin >> repeatPassword;
	}
	if (strcmp(re_password,repeatPassword)==0){
		ID = re_id;
		password = re_password;
		star(10);
		cout << "注册成功！" << endl;
		star(10);
		Sleep(1000);
		system("cls");
	}
	User n;
	n.ID = ID;
	n.password = re_password;
	userList.push_back(n);
}
void Customer::Opetion()
{
	int t = 1;
	while (t)
	{
		Title();
		int ope;
		cin >> ope;
		switch (ope)
		{
		case 1: {Logout(); t = 0; break; }
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
}
void Customer::Logout()
{
	char data1_name[20] = { 0 };
	char data2_name[20] = { 0 };
	char data3_name[20] = { 0 };
	char userName[20];
	strcpy_s(userName,ID);
	sprintf_s(data1_name, "%s%s",userName , ".txt");
	sprintf_s(data2_name, "%s%s", userName, "_order.txt");
	sprintf_s(data3_name, "%s%s", userName, "_foot.txt");
	ofstream p1file(data1_name, ios::out);
	vector<GoodsList>::iterator i,j,k;
	for (i = a.Cart.begin(); i != a.Cart.end(); i++) 
		p1file << (*i).ID << " " << (*i).name << " " << (*i).brand << " " << (*i).price << " " << (*i).num << " " << "\n";
	p1file.close();
	ofstream p2file(data2_name, ios::out);
	for (j = a.historyOrder.begin();j != a.historyOrder.end(); j++)
		p2file << (*j).ID << " " << (*j).name << " " << (*j).brand << " " << (*j).price << " " << (*j).num << " " << "\n";
	p2file.close();
	ofstream p3file(data3_name, ios::out);
	for(k = a.footPrint.begin(); k != a.footPrint.end(); k++)
		p3file << (*k).ID << " " << (*k).name << " " << (*k).brand << " " << (*k).price << " " << (*k).num << " " << "\n";
	p3file.close();

	cout << "欢迎下次光临！" << endl;
	Sleep(1000);
	system("cls");
	return;
}
void Customer::CheckGoods()
{
	cout.setf(std::ios::left);
	vector<GoodsList>::iterator pv = a.goods.begin();
	star(100);
	cout << setw(20) << (*pv).ID << setw(20) << (*pv).name << setw(20) << (*pv).brand << setw(20) << (*pv).price << setw(20) << (*pv).num << endl;
	for (pv = a.goods.begin()+1; pv != a.goods.end(); pv++) {
		if(stoi((*pv).num) >0)
			cout << setw(20) << (*pv).ID << setw(20) << (*pv).name << setw(20) << (*pv).brand << setw(20) << (*pv).price << setw(20) << (*pv).num << endl;
	}
	star(100);
	system("pause");
	system("cls");
}
void Customer::InquireGoods()
{
	//搜索商品，通过商品名称,通过搜索商品，写下足迹
	cout.setf(std::ios::left);
	cout << "商品名称：";
	GoodsList t;
	cin >> t.name;
	vector<GoodsList>::iterator pv = a.goods.begin();
	int count = 0;
	star(100);
	cout << setw(20) << (*pv).ID << setw(20) << (*pv).name << setw(20) << (*pv).brand << setw(20) << (*pv).price << setw(20) << (*pv).num << endl;
	for (pv = a.goods.begin() + 1; pv != a.goods.end(); pv++) {
		if (t.name == (*pv).name) {
			count++;
			cout << setw(20) << (*pv).ID << setw(20) << (*pv).name << setw(20) << (*pv).brand << setw(20) << (*pv).price << setw(20) << (*pv).num << endl;
			if (a.footPrint.empty()) {
				GoodsList e;
				e.ID = "ID";
				e.name = "名称";
				e.brand = "品牌";
				e.price = "价格";
				e.num = "数量";
				a.Cart.push_back(e);
			}
			a.footPrint.push_back(*pv);
		}
	}
	if (count == 0) {
		gotoxy(0, 6);
		blank(120);
		cout << endl;
		blank(120);
		gotoxy(0, 6);
		star(14);
		cout << "商品不存在" << endl;
		star(14);
		Sleep(1000);
		system("cls");
		return;
	}
	star(100);
	system("pause");
	system("cls");
}
void Customer::FootPrint()
{
	star(100);
	cout.setf(std::ios::left);
	vector<GoodsList>::iterator pv;
	for (pv = a.footPrint.begin(); pv != a.footPrint.end(); pv++) {
		cout << setw(20) << (*pv).ID << setw(20) << (*pv).name << setw(20) << (*pv).brand << setw(20) << (*pv).price << endl;
	}
	star(100);
	system("pause");
	system("cls");
}
void Customer::AddGoodsToCart()
{
	cout << "输入商品ID" << endl;
	GoodsList t;
	cout << "ID:";
	cin >> t.ID;
	bool GoodExistng = 0;
	vector<GoodsList>::iterator pv;
	for (pv = a.Cart.begin(); pv != a.Cart.end(); pv++) {
		if ((*pv).ID == t.ID) {
			GoodExistng = 1;
			cout << "该商品已存在" << endl;
			cout << "确定商品数量:";
			string num;
			cin >> num;
			(*pv).num.erase((*pv).num.begin(), (*pv).num.end() - 1);
			(*pv).num = num;
			break;
		}
	}
	if (!GoodExistng) {
		if (a.Cart.empty()) {
			GoodsList e;
			e.ID = "ID";
			e.name = "名称";
			e.brand = "品牌";
			e.price = "价格";
			e.num = "数量";
			a.Cart.push_back(e);
		}
		vector<GoodsList>::iterator p;
		for (p = a.goods.begin(); p != a.goods.end(); p++) {
			if ((*p).ID == t.ID) {
				t.name = (*p).name;
				t.brand = (*p).brand;
				t.price = (*p).price;
				cout << "确定商品数量:";
				cin >> t.num;
				a.Cart.push_back(t);
				break;
			}
		}
	}
	star(20);
	cout <<"已经添加至购物车！"<<endl;
	star(20);
	cout << "购物车中有";
	cout << endl;
	CheckCart();
}
void Customer::DeleteGoodsInCart()
{
	CheckCart();
	cout << "要删除的商品编号:" << endl;
	GoodsList t;
	cin >> t.ID;
	vector<GoodsList>::iterator pv = a.Cart.begin();
	while (pv != a.Cart.end()) {
		if ((*pv).ID == t.ID)
			pv = a.Cart.erase(pv);
		else
			pv++;
	}
	star(10);
	cout << "删除成功！";
	star(10);
	cout << "购物车中有";
	CheckCart();
}
void Customer::CheckCart()
{
	if (a.Cart.empty()) {
		GoodsList e;
		e.ID = "ID";
		e.name = "名称";
		e.brand = "品牌";
		e.price = "价格";
		e.num = "数量";
		a.Cart.push_back(e);
	}
	star(100);
	vector<GoodsList>::iterator pv = a.goods.begin()+1;
	while(pv!=a.goods.end()){
		if ((*pv).num == "-1") {
			vector<GoodsList>::iterator t = a.Cart.begin();
			while (t != a.Cart.end()) {
				if ((*t).ID == (*pv).ID) {
					cout << (*t).name << "(" << (*t).brand << ")已下架" << endl;
					t = a.Cart.erase(t);
				}
				else
					t++;
			}
			/*for (t = a.Cart.begin(); t != a.Cart.end(); t++) {
				if((*t).ID==(*pv).ID)
				a.Cart.erase(t);
			}*/
		}
		pv++;
	}
	cout.setf(std::ios::left);
	vector<GoodsList>::iterator i; 
	for (i = a.Cart.begin(); i != a.Cart.end();i++) {
		cout << setw(20) << (*i).ID << setw(20) << (*i).name << setw(20) << (*i).brand << setw(20) << (*i).price << setw(20) << (*i).num << endl;
	}
	star(100);
	system("pause");
	system("cls");
}
void Customer::SettleAmounts()
{
	star(100);
	cout.setf(std::ios::left);
	vector<GoodsList>::iterator i;
	for (i = a.Cart.begin(); i != a.Cart.end(); i++) {
		cout << setw(20) << (*i).ID << setw(20) << (*i).name << setw(20) << (*i).brand << setw(20) << (*i).price << setw(20) << (*i).num << endl;
	}
	star(100);
	double sum = 0;
	vector<GoodsList>::iterator pv;
	for (pv = a.Cart.begin() + 1; pv != a.Cart.end(); pv++) {
		sum += stod((*pv).price) * stod((*pv).num);
	}
	cout << endl;
	line(50);
	cout << "一共需要付款" << sum << "元。";
	cout << "如需付款请按 1，退出请按 0" << endl;
	line(50);
	int ope;
	cin >> ope;
	if (ope) {
		star(10);
		cout << "付款成功！" << endl;
		star(10);
		vector<GoodsList>::iterator pv;
		vector<GoodsList>::iterator i;
		int num = 0, inum = 0, pnum = 0;
		for (pv = a.Cart.begin() + 1; pv != a.Cart.end(); pv++) {
			a.sellList.push_back(*pv);
			a.historyOrder.push_back(*pv);
			for (i = a.goods.begin() + 1; i != a.goods.end(); i++) {
				if ((*pv).ID == (*i).ID) {
					inum = std::stoi((*i).num);
					pnum = std::stoi((*pv).num);
					num = inum - pnum;
					(*i).num = to_string(num);
				}
			}
		}
		a.Cart.clear();
		Sleep(2000);
		system("cls");
	}
	else {
		system("cls");
		return;
	}
}
void Customer::Order()
{
	star(100);
	vector<GoodsList>::iterator pv;
	for (pv = a.historyOrder.begin(); pv != a.historyOrder.end(); pv++) {
		cout <<setw(20)<< (*pv).ID << setw(20) << (*pv).name << setw(20) << (*pv).brand << setw(20) << (*pv).price <<endl;
	}
	star(100);
	system("pause");
	system("cls");
}
void Customer::Title()
{
	line(120);
	cout << "1，注销登录\t";
	cout << "2, 查看商品\t";
	cout << "3, 商品搜索\t";
	cout << "4, 添加商品至购物车\t";
	cout << "5, 删除购物车商品\t";
	cout << "6, 查看购物车\t";
	cout << "7, 结账\t";
	cout << "8, 历史订单\t";
	cout << "9, 足迹" << endl;
	line(120);
	cout << "输入操作：";
}
