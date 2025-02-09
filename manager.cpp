#include"head.h"

//管理员登录接口
void Manager::manaage_login()
{
	system("pause"); system("cls");
	cout << "请输入您的用户名：" << endl;
	string n;
	cin >> n;
	cout << "输入时，是否显示密码：（0--不显示  1--显示）" << endl;
	int sel; 
	cin >> sel;
	string p; 
	cout << "请输入您的密码：" << endl;
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
			cout << "登录成功,已识别到您是超级管理员" << endl;
			cout << "1--使用超级管理员功能" << endl;
			cout << "2--不使用超级管理员功能" << endl;
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
				cout << "已经为您切换为普通管理员" << endl << endl;
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
			cout << "登录成功" << endl;
			system("pause");
			system("cls");
			this->managerfunc();
			return;
		}
	}
	ifs2.close();
	cout << "用户名或者密码错误" << endl;
	system("pause");
	system("cls");
}

//是否显示登录的密码
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

//超级管理员的菜单
void Manager::superrootmenu()
{
	cout << "***欢迎使用旅游区导览系统*******" << endl;
	cout << "*******0-------注销账号*********" << endl;
	cout << "*******1-------添加管理员*******" << endl;
	cout << "*******2-------查看管理员*******" << endl;
	cout << "********************************" << endl;

}

//超级管理员的功能
void Manager::superrootfunc()
{
	while (true)
	{
		this->superrootmenu();
		cout << endl << "请输入您的选择：" << endl;
		int sel; cin >> sel;
		switch (sel)
		{
		case 0:exit(0); break;
		case 1:this->addmanager(); break;
		case 2:this->cheakmanager(); break;
		default:cout << "输入有误，请重新输入" << endl; system("pause"); system("cls");
		}
	}
}

//添加管理员
void Manager::addmanager()
{
	ofstream ofs;
	ofs.open(managerfile, ios::out | ios::app);
	string n, p;
	cout << "请输入您要添加的管理员的用户名：" << endl;
	cin >> n;
	cout << "请输入您要添加的管理员的密码:" << endl;
	cin >> p;
	ifstream ifs;
	string name, pin;
	ifs.open(managerfile, ios::in);
	while (ifs >> name && ifs >> pin)
	{
		if (name == n)
		{
			cout << "用户名已存在" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	ofs << n << " " << p << endl;
	ofs.close();
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
}

//查看所有管理员的账号密码
void Manager::cheakmanager()
{
	ifstream ifs;
	string name, pin;
	ifs.open(managerfile, ios::in);
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空，没有管理员记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	ifs.putback(ch);
	cout<<"用户名\t\t\t"<<"密码\t\t\t"<<endl;
	while (ifs >> name && ifs >> pin)
	{
		cout << name << "\t\t\t" << pin << "\t\t\t" << endl;
	}
	system("pause");
	system("cls");
}

//管理员菜单
void Manager::managermenu()
{
	cout << "***欢迎使用旅游区导览系统*******" << endl;
	cout << "*******0-------注销账号*******" << endl;
	cout << "*******1-------增加景点信息*******" << endl;
	cout << "*******2-------删除景点信息*****" << endl;
	cout << "*******3-------查看景点信息*****" << endl;
	cout << "*******4-------修改景点信息*****" << endl;
	cout << "*******5-------增加道路信息*****" << endl;
	cout << "*******6-------删除道路信息*****" << endl;
	cout << "*******7-------查看道路信息*****" << endl;
	cout << "*******8-------修改道路信息*****" << endl;
	cout << "*******9-------旅游区地图展示***" << endl;
	cout << "********************************" << endl;
}

//添加景点信息
void Manager::addspot()
{
	int x, y;
	int num;
	string name, msg;
	while (true)
	{
		cout << "请输入景点的编号1 - 1004：(退出当前程序可按0)" << endl;
		cin >> num;
		if (num == 0)
		{
			system("cls"); return;
		}
		else if (num > 1004 || num < 1)
		{
			cout << "景点的编号在1 - 1004之间：(退出当前程序可按0)" << endl;
		}
		else if (s[num].flag) cout << "该编号已经存在，请重新输入" << endl;
		else if (!s[num].flag) break;
		
	}
	cout << "请输入景点的位置坐标：(以逗号分隔)" << endl;
	while (true)
	{
		cin >> x; getchar(); cin >> y;
		if (map[x][y]) cout << "景点坐标与  "<< s[map[x][y]].name <<"  重复，请重新输入" << endl;
		else break;
	}
	cout << "请输入景点的名称：" << endl;
	cin >> name;
	cout << "请输入景点的信息：" << endl;
	cin >> msg;
	s[num] = scenic_spot(x,y,num, name, msg,1);
	save();
	map[x][y] = num;
	cout << "已成功添加" << endl;
	system("pause");
	system("cls");
}

//删除景点信息
void Manager::delspot()
{
	cout << "请输入您要删除的景点的编号(1--1004)：" << endl;
	int num;
	while (true)
	{
		cin >> num;
		if (num < 1 || num > 1004)
		{
			cout << "输入有误，请重新输入：" << endl;
			continue;
		}
		else if (s[num].flag == 1)
		{
			s[num].flag = 0;
			save();
			map[s[num].x][s[num].y] = 0;
			cout << "成功删除编号为" << num << "号的景点" << endl;
			system("pause");
			system("cls");
			return;
		}
		else if(s[num].flag == 0)
		{
			cout << "暂时没有此编号的景点" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	
}

//查看所有景点信息
void Manager::cheakspot()
{
	ifstream ifs;
	ifs.open(scenic_spotfile, ios::in);
	char ch;
	ifs >> ch;
	if (ifs.eof()) 
	{
		cout << "暂时没有任何景点信息" << endl;
		system("pause");
		system("cls");
		return;
	}
	ifs.putback(ch);
	int x, y;
	int num;
	string name, msg;
	int flag;
	cout << "景点编号：" << "\t\t\t" << "景点的位置坐标：" << "\t\t" << "景点名称：" << "\t\t" << "景点信息：" << endl;
	int cnt = 0;
	while (ifs >> x && ifs >> y && ifs >> num && ifs >> name && ifs >> msg && ifs >> flag)
	{
		cout << num << "\t\t\t\t" << x << "," << y << "\t\t\t\t" << name << "\t\t\t" << msg << endl;
		cnt++;
	}
	cout << "共计" << cnt << "个景点的信息" << endl;
	ifs.close();
	system("pause");
	system("cls");
}

//修改景点的信息
void Manager::modspot()
{
	int x, y;
	int num;
	cout << "请输入您要修改的景点的编号：(输入0可退出当前程序)" << endl;
	cin >> num;
	if (num == 0)
	{
		system("pause");
		system("cls");
		return;
	}
	else if (num < 1 || num > 1004)
	{
		cout << "景点编号应该在1--1004之间" << endl;
		system("pause");
		system("cls");
		return;
	}
	else if(s[num].flag != 1)
	{
	   cout << "该景点不存在" << endl;
	   system("pause");
	   system("cls");
	   return;
	}
	string name, msg;
	cout << "景点的编号：" << s[num].num << endl;
	cout << "景点的坐标：" << s[num].x << "," << s[num].y << endl;
	cout << "景点的名称：" << s[num].name << endl;
	cout << "景点的简介：" << s[num].msg << endl;
	s[num].x = -1;
	s[num].y = -1;
	s[num].num = -1;
	s[num].name = "";
	s[num].msg = "";
	s[num].flag = 0;
	cout << "请输入景点新的编号：" << endl;
	cin >> num;
	cout << "请输入景点的位置坐标：(以逗号分隔)" << endl;
	cin >> x; getchar(); cin >> y;
	cout << "请输入景点新的名称：" << endl;
	cin >> name;
	cout << "请输入景点新的简介：" << endl;
	cin >> msg;
	s[num].x = x;
	s[num].y = y;
	s[num].num = num;
	s[num].name = name;
	s[num].msg = msg;
	s[num].flag = 1;
	save();
	cout << "已成功修改" << endl;
	system("pause");
	system("cls");
}

//普通管理员的功能
void Manager::managerfunc()
{
	int sel;
	while (true)
	{
		this->managermenu();
		cout << endl << "请输入您的选择：" << endl;
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
		default:cout << "输入有误，请重新输入" << endl; system("pause"); system("cls");
		}
	}
}

//增加景点之间的信息
void Manager::adddis()
{
	int v, w;
	cout << "请分别输入道路上的起止景点的编号：(1--1004)" << endl;
	while (cin >> v && cin >> w && v == w || v > 1004 || v < 1 || w > 1004 || w < 1)
	{
		cout << "您输入了的景点不合法，请重新输入" << endl;
	}
	if (graphs[v][w].length != -1 && graphs[v][w].times != -1)
	{
		cout << "此路径已经存在，无法添加" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入这两个景点之间的距离：" << endl;
	int length;
	cin >> length;
	cout << "请输入通过两个景点之间所需要的时间：" << endl;
	int times;
	cin >> times;
	cout << "请输入这两个景点之间的道路类型：（1--人行道 2--车道 3--人行道和车道均有）" << endl;
	int road;
	cin >> road;
	cout << "请输入两个景点之间道路的景色等级：" << endl;
	int score;
	cin >> score;
	graphs[v][w] = arcs(road,score, length, times);
	graphs[w][v] = arcs(road, score, length, times);
	save2();
	cout << "成功添加" << endl;
	system("pause");
	system("cls");
	return;
}

//删除顶点之间的路径
void Manager::deldis()
{
	int v, w;
	cout << "请输入您要删除的路径上的两个景点的编号：(1--1004)" << endl;
	cin >> v >> w;
	if (v > 1004 || w > 1004 || v < 1 || w < 1)
	{
		cout << "景点编号应在1--1004之间" << endl;	
		system("pause");
		system("cls");
		return;
	}
	else if (graphs[v][w].length == -1 && graphs[v][w].times == -1)
	{
		cout << "此路径不存在，无法删除" << endl;
		system("pause");
		system("cls");
		return;
	}
	graphs[v][w] = arcs(-1, -1, -1, -1);
	save2();
	cout << "已成功删除" << endl;
	system("pause");
	system("cls");
	return;
}

//查看所有路径
void Manager::cheakdis()
{
	int cnt = 0;
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = i; j < MAX; ++j)
		{
			if (graphs[i][j].length == -1) continue;
			cout << "景点的编号 ： " << i << " " << j << "       ";
			if (graphs[i][j].road == 1) cout << "道路类型 ： 人行道          ";
			else if(graphs[i][j].road == 2)cout << "道路类型 ： 车道            ";
			else cout << "道路类型 : 车道或人行道     ";
			cout << "沿途的景色等级：" << graphs[i][j].score << "     ";
			cout << "景点之间的路程：" << graphs[i][j].length << "m      ";
			cout << "所需时间为：" << graphs[i][j].times << "min"; 
			cout << endl;
			cnt++;
		}
	}
	cout << "共计" << cnt << "条路径的信息" << endl;
	system("pause");
	system("cls");
}

//修改路径信息
void Manager::moddis()
{
	int v, w;
	cout << "请输入您要修改的两个景点的编号：( 1 -- 1004)" << endl;
	cin >> v >> w;
	if (v > 1004 || w > 1004 || v < 1 || w < 1)
	{
		cout << "景点编号应该在1--1004之间" << endl;
		system("pause");
		system("cls");
		return;
	}
	else if (graphs[v][w].length == -1 && graphs[v][w].times == -1)
	{
		cout << "此路径不存在，无法修改" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "道路类型 : 车道或人行道 "<<endl;
	cout << "沿途的景色等级：" << graphs[v][w].score << endl;
	cout << "景点之间的路程：" << graphs[v][w].length << "m" << endl;
	cout << "所需时间为：" << graphs[v][w].times << "min" << endl;
	cout << endl;
	cout << "请输入这两个景点之间的距离：" << endl;
	int length;
	cin >> length;
	cout << "请输入通过两个景点之间所需要的时间：" << endl;
	int times;
	cin >> times;
	cout << "请输入这两个景点之间的道路类型：（1--人行道 2--车道 3--人行道和车道均有）" << endl;
	int road;
	cin >> road;
	cout << "请输入两个景点之间道路的景色等级：" << endl;
	int score;
	cin >> score;
	graphs[v][w] = arcs(road, score, length, times);
	graphs[w][v] = arcs(road, score, length, times);
	save2();
	cout << "已成功修改" << endl;
	system("pause");
	system("cls");
	return;
}