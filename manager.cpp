#include"head.h"

//����Ա��¼�ӿ�
void Manager::manaage_login()
{
	system("pause"); system("cls");
	cout << "�����������û�����" << endl;
	string n;
	cin >> n;
	cout << "����ʱ���Ƿ���ʾ���룺��0--����ʾ  1--��ʾ��" << endl;
	int sel; 
	cin >> sel;
	string p; 
	cout << "�������������룺" << endl;
	switch (sel)
	{
	case 0:this->hidepin(p); break;
	case 1: cin >> p; break;
	}
	string name;
	string pin;
	ifstream ifs1, ifs2;
	ifs1.open(rootfile, ios::in);
	while (ifs1 >> name && ifs1 >> pin)
	{
		if (name == n && pin == p)
		{
			cout << "��¼�ɹ�,��ʶ�����ǳ�������Ա" << endl;
			cout << "1--ʹ�ó�������Ա����" << endl;
			cout << "2--��ʹ�ó�������Ա����" << endl;
			int choice; cin >> choice;
			system("pause");
			system("cls");
			if (choice == 1)
			{
				this->superrootfunc();
				return;
			}
			else if (choice == 2)
			{
				cout << "�Ѿ�Ϊ���л�Ϊ��ͨ����Ա" << endl << endl;
				this->managerfunc();
				return;
			}
		}
	}
	ifs1.close();
	ifs2.open(managerfile, ios::in);
	while (ifs2 >> name && ifs2 >> pin)
	{
		if (name == n && pin == p)
		{
			cout << "��¼�ɹ�" << endl;
			system("pause");
			system("cls");
			this->managerfunc();
			return;
		}
	}
	ifs2.close();
	cout << "�û��������������" << endl;
	system("pause");
	system("cls");
}

//�Ƿ���ʾ��¼������
void Manager::hidepin(string& pin)
{
	char ch;
	while ((ch = _getch()) != '\r')
	{
		if (ch == 8)
		{
			if (!pin.empty())
			{
				pin.pop_back();
				cout << "\b \b";
			}
		}
		else
		{
			pin += ch;
			cout << "*";
		}
	}
	cout << endl;
}

//��������Ա�Ĳ˵�
void Manager::superrootmenu()
{
	cout << "***��ӭʹ������������ϵͳ*******" << endl;
	cout << "*******0-------ע���˺�*********" << endl;
	cout << "*******1-------��ӹ���Ա*******" << endl;
	cout << "*******2-------�鿴����Ա*******" << endl;
	cout << "********************************" << endl;

}

//��������Ա�Ĺ���
void Manager::superrootfunc()
{
	while (true)
	{
		this->superrootmenu();
		cout << endl << "����������ѡ��" << endl;
		int sel; cin >> sel;
		switch (sel)
		{
		case 0:exit(0); break;
		case 1:this->addmanager(); break;
		case 2:this->cheakmanager(); break;
		default:cout << "������������������" << endl; system("pause"); system("cls");
		}
	}
}

//��ӹ���Ա
void Manager::addmanager()
{
	ofstream ofs;
	ofs.open(managerfile, ios::out | ios::app);
	string n, p;
	cout << "��������Ҫ��ӵĹ���Ա���û�����" << endl;
	cin >> n;
	cout << "��������Ҫ��ӵĹ���Ա������:" << endl;
	cin >> p;
	ifstream ifs;
	string name, pin;
	ifs.open(managerfile, ios::in);
	while (ifs >> name && ifs >> pin)
	{
		if (name == n)
		{
			cout << "�û����Ѵ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	ofs << n << " " << p << endl;
	ofs.close();
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
}

//�鿴���й���Ա���˺�����
void Manager::cheakmanager()
{
	ifstream ifs;
	string name, pin;
	ifs.open(managerfile, ios::in);
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ�գ�û�й���Ա��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	ifs.putback(ch);
	cout<<"�û���\t\t\t"<<"����\t\t\t"<<endl;
	while (ifs >> name && ifs >> pin)
	{
		cout << name << "\t\t\t" << pin << "\t\t\t" << endl;
	}
	system("pause");
	system("cls");
}

//����Ա�˵�
void Manager::managermenu()
{
	cout << "***��ӭʹ������������ϵͳ*******" << endl;
	cout << "*******0-------ע���˺�*******" << endl;
	cout << "*******1-------���Ӿ�����Ϣ*******" << endl;
	cout << "*******2-------ɾ��������Ϣ*****" << endl;
	cout << "*******3-------�鿴������Ϣ*****" << endl;
	cout << "*******4-------�޸ľ�����Ϣ*****" << endl;
	cout << "*******5-------���ӵ�·��Ϣ*****" << endl;
	cout << "*******6-------ɾ����·��Ϣ*****" << endl;
	cout << "*******7-------�鿴��·��Ϣ*****" << endl;
	cout << "*******8-------�޸ĵ�·��Ϣ*****" << endl;
	cout << "*******9-------��������ͼչʾ***" << endl;
	cout << "********************************" << endl;
}

//��Ӿ�����Ϣ
void Manager::addspot()
{
	int x, y;
	int num;
	string name, msg;
	while (true)
	{
		cout << "�����뾰��ı��1 - 1004��(�˳���ǰ����ɰ�0)" << endl;
		cin >> num;
		if (num == 0)
		{
			system("cls"); return;
		}
		else if (num > 1004 || num < 1)
		{
			cout << "����ı����1 - 1004֮�䣺(�˳���ǰ����ɰ�0)" << endl;
		}
		else if (s[num].flag) cout << "�ñ���Ѿ����ڣ�����������" << endl;
		else if (!s[num].flag) break;
		
	}
	cout << "�����뾰���λ�����꣺(�Զ��ŷָ�)" << endl;
	while (true)
	{
		cin >> x; getchar(); cin >> y;
		if (map[x][y]) cout << "����������  "<< s[map[x][y]].name <<"  �ظ�������������" << endl;
		else break;
	}
	cout << "�����뾰������ƣ�" << endl;
	cin >> name;
	cout << "�����뾰�����Ϣ��" << endl;
	cin >> msg;
	s[num] = scenic_spot(x,y,num, name, msg,1);
	save();
	map[x][y] = num;
	cout << "�ѳɹ����" << endl;
	system("pause");
	system("cls");
}

//ɾ��������Ϣ
void Manager::delspot()
{
	cout << "��������Ҫɾ���ľ���ı��(1--1004)��" << endl;
	int num;
	while (true)
	{
		cin >> num;
		if (num < 1 || num > 1004)
		{
			cout << "�����������������룺" << endl;
			continue;
		}
		else if (s[num].flag == 1)
		{
			s[num].flag = 0;
			save();
			map[s[num].x][s[num].y] = 0;
			cout << "�ɹ�ɾ�����Ϊ" << num << "�ŵľ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		else if(s[num].flag == 0)
		{
			cout << "��ʱû�д˱�ŵľ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	
}

//�鿴���о�����Ϣ
void Manager::cheakspot()
{
	ifstream ifs;
	ifs.open(scenic_spotfile, ios::in);
	char ch;
	ifs >> ch;
	if (ifs.eof()) 
	{
		cout << "��ʱû���κξ�����Ϣ" << endl;
		system("pause");
		system("cls");
		return;
	}
	ifs.putback(ch);
	int x, y;
	int num;
	string name, msg;
	int flag;
	cout << "�����ţ�" << "\t\t\t" << "�����λ�����꣺" << "\t\t" << "�������ƣ�" << "\t\t" << "������Ϣ��" << endl;
	int cnt = 0;
	while (ifs >> x && ifs >> y && ifs >> num && ifs >> name && ifs >> msg && ifs >> flag)
	{
		cout << num << "\t\t\t\t" << x << "," << y << "\t\t\t\t" << name << "\t\t\t" << msg << endl;
		cnt++;
	}
	cout << "����" << cnt << "���������Ϣ" << endl;
	ifs.close();
	system("pause");
	system("cls");
}

//�޸ľ������Ϣ
void Manager::modspot()
{
	int x, y;
	int num;
	cout << "��������Ҫ�޸ĵľ���ı�ţ�(����0���˳���ǰ����)" << endl;
	cin >> num;
	if (num == 0)
	{
		system("pause");
		system("cls");
		return;
	}
	else if (num < 1 || num > 1004)
	{
		cout << "������Ӧ����1--1004֮��" << endl;
		system("pause");
		system("cls");
		return;
	}
	else if(s[num].flag != 1)
	{
	   cout << "�þ��㲻����" << endl;
	   system("pause");
	   system("cls");
	   return;
	}
	string name, msg;
	cout << "����ı�ţ�" << s[num].num << endl;
	cout << "��������꣺" << s[num].x << "," << s[num].y << endl;
	cout << "��������ƣ�" << s[num].name << endl;
	cout << "����ļ�飺" << s[num].msg << endl;
	s[num].x = -1;
	s[num].y = -1;
	s[num].num = -1;
	s[num].name = "";
	s[num].msg = "";
	s[num].flag = 0;
	cout << "�����뾰���µı�ţ�" << endl;
	cin >> num;
	cout << "�����뾰���λ�����꣺(�Զ��ŷָ�)" << endl;
	cin >> x; getchar(); cin >> y;
	cout << "�����뾰���µ����ƣ�" << endl;
	cin >> name;
	cout << "�����뾰���µļ�飺" << endl;
	cin >> msg;
	s[num].x = x;
	s[num].y = y;
	s[num].num = num;
	s[num].name = name;
	s[num].msg = msg;
	s[num].flag = 1;
	save();
	cout << "�ѳɹ��޸�" << endl;
	system("pause");
	system("cls");
}

//��ͨ����Ա�Ĺ���
void Manager::managerfunc()
{
	int sel;
	while (true)
	{
		this->managermenu();
		cout << endl << "����������ѡ��" << endl;
		cin >> sel;
		switch (sel)
		{
		case 0: exit(0); break;
		case 1 :this->addspot(); break;
		case 2: this->delspot(); break;
		case 3: this->cheakspot(); break;
		case 4: this->modspot(); break;
		case 5: this->adddis(); break;
		case 6: this->deldis(); break;
		case 7: this->cheakdis(); break;
		case 8: this->moddis(); break;
		case 9: showmap(); break;
		default:cout << "������������������" << endl; system("pause"); system("cls");
		}
	}
}

//���Ӿ���֮�����Ϣ
void Manager::adddis()
{
	int v, w;
	cout << "��ֱ������·�ϵ���ֹ����ı�ţ�(1--1004)" << endl;
	while (cin >> v && cin >> w && v == w || v > 1004 || v < 1 || w > 1004 || w < 1)
	{
		cout << "�������˵ľ��㲻�Ϸ�������������" << endl;
	}
	if (graphs[v][w].length != -1 && graphs[v][w].times != -1)
	{
		cout << "��·���Ѿ����ڣ��޷����" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����������������֮��ľ��룺" << endl;
	int length;
	cin >> length;
	cout << "������ͨ����������֮������Ҫ��ʱ�䣺" << endl;
	int times;
	cin >> times;
	cout << "����������������֮��ĵ�·���ͣ���1--���е� 2--���� 3--���е��ͳ������У�" << endl;
	int road;
	cin >> road;
	cout << "��������������֮���·�ľ�ɫ�ȼ���" << endl;
	int score;
	cin >> score;
	graphs[v][w] = arcs(road,score, length, times);
	graphs[w][v] = arcs(road, score, length, times);
	save2();
	cout << "�ɹ����" << endl;
	system("pause");
	system("cls");
	return;
}

//ɾ������֮���·��
void Manager::deldis()
{
	int v, w;
	cout << "��������Ҫɾ����·���ϵ���������ı�ţ�(1--1004)" << endl;
	cin >> v >> w;
	if (v > 1004 || w > 1004 || v < 1 || w < 1)
	{
		cout << "������Ӧ��1--1004֮��" << endl;	
		system("pause");
		system("cls");
		return;
	}
	else if (graphs[v][w].length == -1 && graphs[v][w].times == -1)
	{
		cout << "��·�������ڣ��޷�ɾ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	graphs[v][w] = arcs(-1, -1, -1, -1);
	save2();
	cout << "�ѳɹ�ɾ��" << endl;
	system("pause");
	system("cls");
	return;
}

//�鿴����·��
void Manager::cheakdis()
{
	int cnt = 0;
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = i; j < MAX; ++j)
		{
			if (graphs[i][j].length == -1) continue;
			cout << "����ı�� �� " << i << " " << j << "       ";
			if (graphs[i][j].road == 1) cout << "��·���� �� ���е�          ";
			else if(graphs[i][j].road == 2)cout << "��·���� �� ����            ";
			else cout << "��·���� : ���������е�     ";
			cout << "��;�ľ�ɫ�ȼ���" << graphs[i][j].score << "     ";
			cout << "����֮���·�̣�" << graphs[i][j].length << "m      ";
			cout << "����ʱ��Ϊ��" << graphs[i][j].times << "min"; 
			cout << endl;
			cnt++;
		}
	}
	cout << "����" << cnt << "��·������Ϣ" << endl;
	system("pause");
	system("cls");
}

//�޸�·����Ϣ
void Manager::moddis()
{
	int v, w;
	cout << "��������Ҫ�޸ĵ���������ı�ţ�( 1 -- 1004)" << endl;
	cin >> v >> w;
	if (v > 1004 || w > 1004 || v < 1 || w < 1)
	{
		cout << "������Ӧ����1--1004֮��" << endl;
		system("pause");
		system("cls");
		return;
	}
	else if (graphs[v][w].length == -1 && graphs[v][w].times == -1)
	{
		cout << "��·�������ڣ��޷��޸�" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��·���� : ���������е� "<<endl;
	cout << "��;�ľ�ɫ�ȼ���" << graphs[v][w].score << endl;
	cout << "����֮���·�̣�" << graphs[v][w].length << "m" << endl;
	cout << "����ʱ��Ϊ��" << graphs[v][w].times << "min" << endl;
	cout << endl;
	cout << "����������������֮��ľ��룺" << endl;
	int length;
	cin >> length;
	cout << "������ͨ����������֮������Ҫ��ʱ�䣺" << endl;
	int times;
	cin >> times;
	cout << "����������������֮��ĵ�·���ͣ���1--���е� 2--���� 3--���е��ͳ������У�" << endl;
	int road;
	cin >> road;
	cout << "��������������֮���·�ľ�ɫ�ȼ���" << endl;
	int score;
	cin >> score;
	graphs[v][w] = arcs(road, score, length, times);
	graphs[w][v] = arcs(road, score, length, times);
	save2();
	cout << "�ѳɹ��޸�" << endl;
	system("pause");
	system("cls");
	return;
}