#include "Admin.h"
Admin::Admin() {
	id = new char[ADMIN_ID_MAX];
	password = new char[ADMIN_PASSWORD_MAX];
}
Admin::Admin(char* cid, char* cpassword) {
	id = new char[strlen(cid) + 1];
	password = new char[strlen(cpassword) + 1];
	strcpy_s(id,strlen(cid)+1,cid);
	strcpy_s(password,strlen(cpassword)+1, cpassword);
}
void Admin::Login() {
	cout << "Admin Login" << endl;
	// TODO
	char _id[20], _password[20];
	cout << "输入管理员ID:";
	cin >> _id;
	cout << "输入管理员密码:";
	cin >> _password;
	char* in_id = _id, * in_password = _password;
	while(strcmp(in_id, id) != 0 || strcmp(in_password, password) != 0){
		gotoxy(0, 4);
		cout << "输入的ID或密码有误" << endl;
		blank(40);
		cout << endl;
		blank(40);
		gotoxy(0, 5);
		cout << "输入管理员ID:";
		cin >> _id;
		cout << "输入管理员密码:";
		cin >> _password;
		in_id = _id, in_password = _password;
	}
	if (strcmp(in_id, id) == 0 && strcmp(in_password, password) == 0) {
		star(9);
		cout << "登录成功！" << endl;
		star(9);
		Sleep(1000);
		system("cls");
	}
	Opetion();
}
void Admin::Opetion()
{
	int t = 1;
	while (t) {
		Title();
		int ope;
		cin >> ope;
		switch (ope)
		{
		case 0: {Logout(); t = 0; break; }
		case 1: {InquireGoods(); break; }
		case 2: {AddGoods(); break; }
		case 3: {DeleteGoods(); break; }
		case 4: {ModifyGoodsNum(); break; }
		case 5: {InquireSaleList(); break; }
		case 6: {HotList(); break; }
		case 7: {UnpopList(); break; }
		case 8: {SupplyAlarm(); break; }
		default:
			break;
		}
	}
}
void Admin::Logout() {
	system("cls");
	return;
}
void Admin::InquireGoods() {
	cout.setf(std::ios::left);
	vector<GoodsList>::iterator pv = a.goods.begin();
	star(100);
	cout << setw(20) << (*pv).ID << setw(20) << (*pv).name << setw(20) << (*pv).brand << setw(20) << (*pv).price << setw(20) << (*pv).num << endl;
	for (pv = a.goods.begin()+1; pv != a.goods.end(); pv++) {
		if((*pv).num!="-1")
		cout << setw(20)<<(*pv).ID << setw(20) << (*pv).name << setw(20) << (*pv).brand << setw(20) << (*pv).price << setw(20) << (*pv).num<<endl;
	}
	star(100);
	system("pause");
	system("cls");
}
void Admin::AddGoods() {
	// TODO
	GoodsList t;
	cout << "ID:\t"<<endl;
	cin >> t.ID;
	bool GoodExistng = 0;
	vector<GoodsList>::iterator pv;
	for (pv = a.goods.begin(); pv != a.goods.end(); pv++) {
		if ((*pv).ID == t.ID) {
			GoodExistng = 1;
			cout << "该商品已存在" << endl;
			cout << "1，修改商品数量     2，修改商品价格" << endl;
			int ope;
			cin >> ope;
			switch (ope) {
			case 1: {
				(*pv).num.erase((*pv).num.begin(), (*pv).num.end() - 1);
				string num;
				cout << "修改商品数量为" << endl;
				cin >> num;
				(*pv).num = num;
				cout << "修改成功！" << endl;
				break;
			}
			case 2: {
				(*pv).price.erase((*pv).price.begin(), (*pv).price.end() - 1);
				string price;
				cout << "修改商品价格为" << endl;
				cin >> price;
				(*pv).price = price;
				cout << "修改成功！" << endl;
				break;
			}
			default:break;
			}
		}
	}
	if (GoodExistng == 0) {
		//ModifyGoodsNum();
		//TODO
		cout << "name:\t" << endl;
		cin >> t.name;
		cout << "brand:\t" << endl;
		cin >> t.brand;
		cout << "price:\t" << endl;
		cin >> t.price;
		cout << "num:\t" << endl;
		cin >> t.num;
		a.goods.push_back(t);
		cout << "商品添加成功！" << endl;
	}
	Sleep(1000);
	system("cls");
}
void Admin::DeleteGoods() {
	// TODO
	GoodsList t;
	cout << "需要删除的商品ID:" << endl;
	cin >> t.ID;
	//可以根据ID写入下架商品文件了;
	vector<GoodsList>::iterator pv;
	for (pv = a.goods.begin(); pv != a.goods.end(); pv++) {
		if (t.ID == (*pv).ID) {
			cout << "该商品的数量将被修改为 -1 " << endl;
			(*pv).num = "-1";
			break;
		}
	}
	/*pv = a.goods.begin();
	while (pv != a.goods.end()) {
		if ((*pv).num == "-1")
			pv = a.goods.erase(pv);
		else
			pv++;
	}*/
	/*for (pv = a.goods.begin(); pv != a.goods.end(); pv++) {
		if ((*pv).num=="-1"){
			a.goods.erase(pv);
		}
	}*/
	Sleep(1000);
	system("cls");
}
void Admin::ModifyGoodsNum() {
	// TODO
	GoodsList t;
	cout << "ID:";
	cin >> t.ID;
	cout << "1，只修改商品数量     2，只修改商品价格     3，同时修改数量和价格" << endl;
	vector<GoodsList>::iterator pv;
	int ope;
	cin >> ope;
	switch (ope) {
	case 1: {
		for (pv = a.goods.begin(); pv != a.goods.end(); pv++) {
			if ((*pv).ID == t.ID) {
				(*pv).num.erase((*pv).num.begin(), (*pv).num.end() - 1);
				string num;
				cout << "修改商品数量为" << endl;
				cin >> num;
				(*pv).num = num;
			}
		}
		break;
	}
	case 2: {
		for (pv = a.goods.begin(); pv != a.goods.end(); pv++) {
			if ((*pv).ID == t.ID) {
				(*pv).price.erase((*pv).price.begin(), (*pv).price.end() - 1);
				string price;
				cout << "修改商品价格为" << endl;
				cin >> price;
				(*pv).price = price;
			}
		}
		break; 
	}
	case 3: {
		for (pv = a.goods.begin(); pv != a.goods.end(); pv++) {
			if ((*pv).ID == t.ID) {
				(*pv).num.erase((*pv).num.begin(), (*pv).num.end() - 1);
				string num;
				cout << "修改商品数量为" << endl;
				cin >> num;
				(*pv).num = num;
				(*pv).price.erase((*pv).price.begin(), (*pv).price.end() - 1);
				string price;
				cout << "修改商品价格为" << endl;
				cin >> price;
				(*pv).price = price;
			}
		}
		break;
	}
	default:break;
	}
	Sleep(1500);
	system("cls");

}
bool compID(const GoodsList& p, const GoodsList& q) {
	return
		p.ID.compare(q.ID) < 0;
}
void Admin::InquireSaleList() {
	// TODO
	cout.setf(std::ios::left);
	vector<GoodsList>::iterator pv = a.sellList.begin();
	sort(a.sellList.begin() + 1, a.sellList.end(), compID);
	star(100);
	cout << setw(20) << (*pv).ID << setw(20) << (*pv).name << setw(20) << (*pv).brand << setw(20) << (*pv).price << setw(20) << (*pv).num << endl;
	double sum = 0;
	int num = 0,i=1,j=1,size = a.sellList.size();
	while (i != size + 1) {
		sum = 0;
		num = 0;
		while (a.sellList[i].ID == a.sellList[j].ID) {
			sum += stod(a.sellList[j].price) * stoi(a.sellList[j].num);
			num += stoi(a.sellList[j].num);
			j++;
			if (j == size)
				break;
		}
		a.sellList[i].price = to_string(sum);
		a.sellList[i].num = to_string(num);
		a.sellList[i].price = a.sellList[i].price.substr(0, a.sellList[i].price.size() - 5);//保留一位小数
		cout << setw(20) << a.sellList[i].ID << setw(20) << a.sellList[i].name << setw(20) << a.sellList[i].brand;
		cout << setw(20) << a.sellList[i].price << setw(20) << a.sellList[i].num << endl;
		j++;
		i = j;
	}
	star(100);
	system("pause");
	system("cls");
	/*for (; pv != a.sellList.end(); pv++) {
			cout << setw(20) << (*pv).ID << setw(20) << (*pv).name << setw(20) << (*pv).brand << setw(20) << (*pv).price << setw(20) << (*pv).num << endl;
		}*/
}
bool compBig(const GoodsList& p, const GoodsList& q) {
	return
		(stoi(p.num) > stoi(q.num));
	/*else if (p.num == q.num && p.ID < q.ID)
		return true;*/
}
bool compSmall(const GoodsList& p, const GoodsList& q) {
	return (stoi(p.num) < stoi(q.num));
}
void Admin::HotList() {
	cout.setf(std::ios::left);
	sort(a.sellList.begin()+1, a.sellList.end(), compBig);//排序避开开头的中文名称
	int count = 4;
	vector<GoodsList>::iterator pv;
	star(100);
	for (pv = a.sellList.begin(); count> 0; pv++,count--) {
		cout << setw(20) <<(*pv).ID << setw(20) << (*pv).name << setw(20) << (*pv).brand << setw(20) << (*pv).price << setw(20) << (*pv).num << endl;
	}
	star(100);
	system("pause");
	system("cls");
}
void Admin::UnpopList() {
	cout.setf(std::ios::left);
	sort(a.sellList.begin()+1, a.sellList.end(),compSmall);
	int count = 4;
	vector<GoodsList>::iterator pv;
	star(100);
	for (pv = a.sellList.begin();count > 0; pv++,count--) {
		cout << setw(20)<<(*pv).ID << setw(20) << (*pv).name << setw(20) << (*pv).brand << setw(20) << (*pv).price << setw(20) << (*pv).num << endl;
	}
	star(100);
	system("pause");
	system("cls");
}
void Admin::SupplyAlarm() {
	vector<GoodsList>::iterator pv = a.goods.begin();
	star(100);
	cout << setw(20) << (*pv).ID << setw(20) << (*pv).name << setw(20) << (*pv).brand << setw(20) << (*pv).price << setw(20) << (*pv).num << endl;
	for (pv = a.goods.begin()+1; pv!=a.goods.end(); pv++) {
		if(stoi(pv->num) < 5 && stoi(pv->num)>=0)
			cout << setw(20) << (*pv).ID << setw(20) << (*pv).name << setw(20) << (*pv).brand << setw(20) << (*pv).price << setw(20) << (*pv).num << endl;
	}
	star(100);
	system("pause");
	system("cls");
}
Admin::~Admin() {
	delete[]id;
	delete[]password;
}
void Admin::Title() {
	line(100);
	cout << "0，注销登录\t";
	cout << "1, 查询商品\t";
	cout << "2, 增加商品\t";
	cout << "3, 删除商品\t";
	cout << "4, 修改商品数量\t" << endl;
	cout << "5, 售货清单\t";
	cout << "6, 热销排行\t";
	cout << "7, 冷门商品\t";
	cout << "8, 库存报警" << endl;
	line(100);
	cout << "输入操作：";
}
