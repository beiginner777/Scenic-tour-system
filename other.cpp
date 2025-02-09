#include"head.h"

void menu()
{
	cout << "***��ӭʹ������������ϵͳ****" << endl;
	cout << "*******0-------�˳�ϵͳ******" << endl;
	cout << "*******1-------����Ա********" << endl;
	cout << "*******2-------�ο�**********" << endl;
	cout << "*****************************" << endl;
}

//��ʼ������ �� ·��
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

//���澰����Ϣ
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

//����·����Ϣ
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

//���ַ���С��ת��Ϊsin��ʽ�ı����ʽ(0-90��)
double conversion(double x)//x��sinֵ ���ػ���
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

//�����һ����s1������һ��s2�ķ���
string dic(scenic_spot s1, scenic_spot s2)
{
	string result;
	//s1��s2��ͬһ��ˮƽֱ��
	if (s1.x == s2.x)
	{
		if (s1.y < s2.y) result += "����";
		else if(s1.y > s2.y) result += "����";
		//��ͼʱ �Ѿ���֤�����������������ͬһ��λ������
	}
	//s1��s2��ͬһ����ֱֱ��
	else if (s1.y == s2.y)
	{
		if (s1.x < s2.x) result += "����";
		else if (s1.x > s2.x) result += "����";
		//��ͼʱ �Ѿ���֤�����������������ͬһ��λ������
	}
	//s1��s2���Ϸ�
	else if (s1.x < s2.x)
	{
		if(s1.y < s2.y )
		{
			double pos = (s2.y - s1.y) / sqrt((s2.y - s1.y) * (s2.y - s1.y) + (s2.x - s1.x) * (s2.x - s1.x));
			double ret = conversion(pos);
			ret *= (180.0 / PI);//�Ƕ�ֵ
			string ss = to_string(ret);
			result = result + "��ƫ��" + to_string(ret) + "��";
		}
		else
		{
			double pos = (s1.y - s2.y) / sqrt((s2.y - s1.y) * (s2.y - s1.y) + (s2.x - s1.x) * (s2.x - s1.x));
			double ret = conversion(pos);
			ret *= (180.0 / PI);//�Ƕ�ֵ
			result = result + "��ƫ��" + to_string(ret) + "��";
		}
	}
	//s1��s2���·�
	else if (s1.x > s2.x)
	{
		if (s1.y > s2.y)
		{
			double pos = (s1.y - s2.y) / sqrt((s2.y - s1.y) * (s2.y - s1.y) + (s2.x - s1.x) * (s2.x - s1.x));
			double ret = conversion(pos);
			ret *= (180.0 / PI);//�Ƕ�ֵ
			result = result + "��ƫ��" + to_string(ret) + "��";
		}
		else
		{
			double pos = (s2.y - s1.y) / sqrt((s2.y - s1.y) * (s2.y - s1.y) + (s2.x - s1.x) * (s2.x - s1.x));
			double ret = conversion(pos);
			ret *= (180.0 / PI);//�Ƕ�ֵ
			result = result + "��ƫ��" + to_string(ret) + "��";
		}
	}
	return result;
}

//չʾ��ͼ
void showmap()
{
	system("cls");
	cout << endl <<"��������ͼչʾ" << endl<< endl;
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