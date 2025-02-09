#include"head.h"

scenic_spot s[MAX];
struct arcs graphs[MAX][MAX];
Manager man;
tourist tis;
int map[15][15];
vector<int>plan;
vector<vector<int>>RES;
vector<bool>visited;
vector<int>path;
vector<int>ans;
int result;
int sum;
int minDist[MAX];
int vis[MAX];

int main()
{
	cout << "  班级：23计科9" << endl;
	cout << "  学号：3123008759" << endl;
	cout << "  姓名：郭锐杰" << endl << endl;
	system("pause");
	system("cls");
	init();
	while (true)
	{
		menu();
		cout << "请输入您的选择：" << endl;
		int sel; cin >> sel;
		switch (sel)
		{
		case 0: cout << "即将退出程序" << endl; Sleep(500); exit(0); break;
		case 1: man.manaage_login(); break;
		case 2: tis.touristfunc(); break;
		default:cout << "输入有误，请重新输入" << endl; system("pause"); system("cls");
		}
	}
	return 0;
}