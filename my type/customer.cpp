#include "Customer.h"	
Customer::Customer()
{
	ifstream pfile("�û�.txt", ios::in);
	if (!pfile)
		cerr << "�ļ���ʧ�ܣ�\n";
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
	ofstream pfile("�û�.txt", ios::out);
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
	cout << "�����û�ID:" << endl;
	cin >> in_id;
	cout << "�����û�����:" << endl;
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
		cout << "��¼�ɹ���" << endl;
	else
		cout << "�����ID����������" << endl;
}
void Customer::Register() 
{
	cout << "customer Register" << endl;
	// TODO
	string  re_id, re_password,repeatPassword;
	cout << "�����û�ID:" << endl;
	cin >> re_id; 
	vector<User>::iterator pv;
	for (pv = userList.begin(); pv != userList.end(); pv++) {
		if (re_id == (*pv).ID) {
			cout << "���û��Ѵ���" << endl;
			return;
		}
	}
	cout << "�����û�����:" << endl;
	cin >> re_password;
	cout << "���ٴ������û�����:" << endl;
	cin >> repeatPassword;
	while (re_password != repeatPassword) {
		cout << "�����������"<<endl;
		cout << "�����������û�����:" << endl;
		cin >> re_password;
		cout << "���ٴ������û�����:" << endl;
		cin >> repeatPassword;
	}
	if (re_password == repeatPassword){
		cout << "ע��ɹ���den" << endl;
	}
	User n;
	n.ID = re_id;
	n.password = re_password;
	userList.push_back(n);
}
void Customer::Opetion()
{
	int ope;
	cout << "1��ע����¼     ";
	cout << "2, �鿴��Ʒ     ";
	cout << "3, ��Ʒ����     ";
	cout << "4, �����Ʒ�����ﳵ     ";
	cout << "5, ɾ�����ﳵ��Ʒ     ";
	cout << "6, �鿴���ﳵ     "; 
	cout << "7, ����     ";
	cout << "8, ��ʷ����     ";
	cout << "9, �㼣" << endl;
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
void Customer::InquireGoods()//��admin��ͬ
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