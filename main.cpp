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
	cout << "  �༶��23�ƿ�9" << endl;
	cout << "  ѧ�ţ�3123008759" << endl;
	cout << "  �����������" << endl << endl;
	system("pause");
	system("cls");
	init();
	while (true)
	{
		menu();
		cout << "����������ѡ��" << endl;
		int sel; cin >> sel;
		switch (sel)
		{
		case 0: cout << "�����˳�����" << endl; Sleep(500); exit(0); break;
		case 1: man.manaage_login(); break;
		case 2: tis.touristfunc(); break;
		default:cout << "������������������" << endl; system("pause"); system("cls");
		}
	}
	return 0;
}