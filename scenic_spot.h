#include<iostream>
#include<string>

using namespace std;

class scenic_spot
{
public:
	int x, y;//景点的坐标
	int num;//景点的编号
	string name;//景点的名称
	string msg;//景点的简介
	int flag;
	scenic_spot() 
	{
		this->x = -1; this->y = -1; this->flag = 0; this->num = -1;
	}
	scenic_spot(int x,int y,int num, string name, string msg,int flag)
	{
		this->x = x;
		this->y = y;
		this->num = num;
		this->name = name;
		this->msg = msg;
		this->flag = flag;
	}
};

struct arcs
{
	int length;
	int times;
	int road;//1代表人行道 2代表车道 3代表两者都可以
	int score;//景色等级
    arcs()
	{
		this->length = -1; this->road = -1; this->score = -1; this->times = -1;
	}
	arcs(int road,int score,int length, int times)
	{
		this->road = road;
		this->score = score;
		this->length = length;
		this->times = times;
	}
};