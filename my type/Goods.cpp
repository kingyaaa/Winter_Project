#include"Goods.h"
#include <iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;
Goods::Goods()
{
	ifstream pfile("库存.txt", ios::in);
	if (!pfile)
		cerr << "文件打开失败！\n";
	string in;
	while (getline(pfile, in))
	{
		istringstream inputString(in);
		GoodsList p;
		inputString >> p.ID >> p.name >> p.brand >> p.price >> p.num;
		goods.push_back(p);
	}
	pfile.close();
	//重复的代码？？
	ifstream pfile("已售清单.txt", ios::in);
	if (!pfile)
		cerr << "文件打开失败！\n";
	string in;
	while (getline(pfile, in))
	{
		istringstream inputString(in);
		GoodsList p;
		inputString >> p.ID >> p.name >> p.brand >> p.price >> p.num;
		sellList.push_back(p);
	}
	pfile.close();
	for (int i = 0; i <= 2; i++) {
		char data_name[20];
		sprintf_s(data_name, "%s%d%s", "user", i+1, ".txt");
		ifstream pfile(data_name);
		if (!pfile)
			cerr << "文件打开失败！\n";
		string in;
		while (getline(pfile, in))
		{
			istringstream inputString(in);
			GoodsList p;
			inputString >> p.ID >> p.name >> p.brand >> p.price >> p.num;
			cart[i].push_back(p);
		}
		pfile.close();
	}
}
Goods::~Goods()
{
	ofstream pfile("用户.txt", ios::out);
	vector<GoodsList>::iterator pv;
	for (pv = sellList.begin(); pv != sellList.end(); pv++)
		pfile << (*pv).ID << " " << (*pv).name << " "<<(*pv).brand << " "<<(*pv).price << " "<<(*pv).num <<"\n";
	pfile.close();
	ofstream pfile("已售清单.txt", ios::out);
	for (pv = sellList.begin(); pv != sellList.end(); pv++)
		pfile << (*pv).ID << " " << (*pv).name << " " << (*pv).brand << " " << (*pv).price << " " << (*pv).num << "\n";
	pfile.close();
	//TODO cart的析构函数
}