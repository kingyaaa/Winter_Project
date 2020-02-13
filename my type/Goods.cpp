#include"Goods.h"
Goods::Goods()
{
	ifstream p1file("库存.txt", ios::in);
	if (!p1file.is_open())
		cerr << "文件打开失败！\n";
	string a;
	while (getline(p1file, a))
	{
		istringstream inputString(a);
		GoodsList p;
		inputString >> p.ID >> p.name >> p.brand >> p.price >> p.num;
		goods.push_back(p);
	}
	p1file.close();
	//重复的代码
	ifstream p2file("已售清单.txt", ios::in);
	if (!p2file.is_open())
		cerr << "文件打开失败！\n";
	string b;
	while (getline(p2file, b))
	{
		istringstream inputString(b);
		GoodsList p;
		inputString >> p.ID >> p.name >> p.brand >> p.price >> p.num;
		sellList.push_back(p);
	}
	p2file.close();
}
Goods::~Goods()
{
	ofstream p1file("库存.txt", ios::out);
	vector<GoodsList>::iterator pv;
	for (pv = goods.begin(); pv != goods.end(); pv++)
		p1file << (*pv).ID << " " << (*pv).name << " "<<(*pv).brand << " "<<(*pv).price << " "<<(*pv).num <<"\n";
	p1file.close();
	ofstream p2file("已售清单.txt", ios::out);
	for (pv = sellList.begin(); pv != sellList.end(); pv++)
		p2file << (*pv).ID << " " << (*pv).name << " " << (*pv).brand << " " << (*pv).price << " " << (*pv).num << "\n";
	p2file.close();
}
void gotoxy(int x, int y)
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}
void star(int size)
{
	for (int i = 0; i < size; i++) {
		cout << "*";
	}
	cout << endl;
}
void line(int size)
{
	for (int i = 0; i < size; i++) {
		cout << "=";
	}
	cout << endl;
}
void blank(int size) {
	for(int i = 0;i<size;i++){
		cout << " ";
	}
}
