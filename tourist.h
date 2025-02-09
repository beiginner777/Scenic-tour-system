#pragma once
#include<iostream>
using namespace std;

class tourist
{
public:
	void menu();//游客的菜单
	void cheak_scenic_spot();//查看景点信息
	void cheakshortest();//查看景点之间最短的路线
	void touristfunc();//游客的功能
	void walkingroad();//规划景点之间只有人行道的路线
	void carroad();//规划景点之间只有车道的路线
	void dfs1(int start, int end);//规划景点之间最短的路线
	void dfs2(int start, int end, int flag); //规划景点之间道路的路线
	void dfs3(int start, int end, int score); //规划景点之间景色等级的路线
	void scoreroad();//规划景点之间景色等级的路线
	void dfs4(int x); //多个景点的路径规划 
	void planing();//多个景点的路径规划 
	void Dijkstraroad();//输出景点之间最短的距离
};