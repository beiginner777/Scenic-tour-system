#include"head.h"

void menu()
{
	cout << "***欢迎使用旅游区导览系统****" << endl;
	cout << "*******0-------退出系统******" << endl;
	cout << "*******1-------管理员********" << endl;
	cout << "*******2-------游客**********" << endl;
	cout << "*****************************" << endl;
}

//初始化景点 和 路径
void init()
{
	ifstream ifs;
	ifs.open(scenic_spotfile, ios::in);
	int x, y;
	int num;
	string name, msg;
	int flag;
	memset(map, 0, sizeof(map));
	while (ifs >> x && ifs >> y && ifs >> num && ifs >> name && ifs >> msg && ifs >> flag)
	{
		scenic_spot ss(x, y, num, name, msg, flag);
		map[x][y] = num;
		s[num] = ss;
	}
	ifs.close();
	ifs.open(arcsfile, ios::in);
	int v, w, road, score, length, times;
	while (ifs >> v && ifs >> w && ifs >> road && ifs >> score && ifs >> length && ifs >> times)
	{
		graphs[v][w] = arcs(road, score, length, times);
		graphs[w][v] = arcs(road, score, length, times);
	}
	ifs.close();
}

//保存景点信息
void save()
{
	ofstream ofs;
	ofs.open(scenic_spotfile, ios::out);
	for (int i = 0; i < MAX; ++i)
	{
		if (s[i].flag)
		{
			ofs << s[i].x << " " << s[i].y
				<< " " << s[i].num << " "
				<< s[i].name << " "
				<< s[i].msg << " "
				<< s[i].flag << endl;
		}
	}
	ofs.close();
}

//保存路径信息
void save2()
{
	ofstream ofs;
	ofs.open(arcsfile, ios::out);
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = i; j <  MAX; ++j)
		{
			if (graphs[i][j].times == -1 && graphs[i][j].length == -1) continue;
			ofs << i << " " << j << " " << graphs[i][j].road << " " << graphs[i][j].score << " " << graphs[i][j].length << " " << graphs[i][j].times << endl;
		}
	}
	ofs.close();
}

//二分法将小数转换为sin形式的表达形式(0-90度)
double conversion(double x)//x是sin值 返回弧度
{
	double start = 0;
	double end = PI / 2;
	while (end - start > 0.001)
	{
		double mid = (start + end) / 2;
		double t = sin(mid);
		if (t <= x) start = mid;
		else if (t > x) end = mid;
	}
	return start;
}

//计算从一个点s1到达另一点s2的方向
string dic(scenic_spot s1, scenic_spot s2)
{
	string result;
	//s1和s2在同一条水平直线
	if (s1.x == s2.x)
	{
		if (s1.y < s2.y) result += "正东";
		else if(s1.y > s2.y) result += "正西";
		//建图时 已经保证不会出现两个景点在同一个位置坐标
	}
	//s1和s2在同一条竖直直线
	else if (s1.y == s2.y)
	{
		if (s1.x < s2.x) result += "正南";
		else if (s1.x > s2.x) result += "正北";
		//建图时 已经保证不会出现两个景点在同一个位置坐标
	}
	//s1在s2的上方
	else if (s1.x < s2.x)
	{
		if(s1.y < s2.y )
		{
			double pos = (s2.y - s1.y) / sqrt((s2.y - s1.y) * (s2.y - s1.y) + (s2.x - s1.x) * (s2.x - s1.x));
			double ret = conversion(pos);
			ret *= (180.0 / PI);//角度值
			string ss = to_string(ret);
			result = result + "南偏东" + to_string(ret) + "°";
		}
		else
		{
			double pos = (s1.y - s2.y) / sqrt((s2.y - s1.y) * (s2.y - s1.y) + (s2.x - s1.x) * (s2.x - s1.x));
			double ret = conversion(pos);
			ret *= (180.0 / PI);//角度值
			result = result + "南偏西" + to_string(ret) + "°";
		}
	}
	//s1在s2的下方
	else if (s1.x > s2.x)
	{
		if (s1.y > s2.y)
		{
			double pos = (s1.y - s2.y) / sqrt((s2.y - s1.y) * (s2.y - s1.y) + (s2.x - s1.x) * (s2.x - s1.x));
			double ret = conversion(pos);
			ret *= (180.0 / PI);//角度值
			result = result + "北偏西" + to_string(ret) + "°";
		}
		else
		{
			double pos = (s2.y - s1.y) / sqrt((s2.y - s1.y) * (s2.y - s1.y) + (s2.x - s1.x) * (s2.x - s1.x));
			double ret = conversion(pos);
			ret *= (180.0 / PI);//角度值
			result = result + "北偏东" + to_string(ret) + "°";
		}
	}
	return result;
}

//展示地图
void showmap()
{
	system("cls");
	cout << endl <<"旅游区地图展示" << endl<< endl;
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			if (map[i][j])
			{
				cout << s[map[i][j]].name;
			}
			else cout << "        ";
		}
		cout << endl << endl;
	}
	system("pause"); system("cls");
}