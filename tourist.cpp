#include"head.h"

void tourist::menu()
{
	cout << "******��ӭʹ������������ϵͳ*******" << endl;
	cout << "********0-------ע����¼***********" << endl;
	cout << "********1-------�鿴���·��*******" << endl;
	cout << "********2-------�鿴������Ϣ*******" << endl;
	cout << "********3-------�������е�·��*****" << endl;
	cout << "********4-------��������·��*******" << endl;
	cout << "********5-------������ɫ·��*******" << endl;
	cout << "********6-------���������滮*******" << endl;
	cout << "********7-------��������ͼչʾ*****" << endl;
	cout << "********8-------�������·��*******" << endl;
	cout << "***********************************" << endl;
}

//�ο͵Ĺ���
void tourist::touristfunc()
{
	system("pause");
	system("cls");
	while (true)
	{
		this->menu();
		int sel;
		cout << "����������ѡ��:" << endl;
		cin >> sel;
		if (sel == 0)	   exit(0);
		else if (sel == 1) this->cheakshortest();
		else if (sel == 2) this->cheak_scenic_spot();
		else if (sel == 3) this->walkingroad();
		else if (sel == 4) this->carroad();
		else if (sel == 5) this->scoreroad();
		else if (sel == 6) this->planing();
		else if (sel == 7) showmap();
		else if (sel == 8) Dijkstraroad();
		else
		{
			cout << "������������������" << endl;
			system("pause");
			system("cls");
		}
	}
}

//�鿴�������Ϣ
void tourist::cheak_scenic_spot()
{
	system("pause");
	system("cls");
	int cnt = 0;
	for (int i = 0; i < MAX; ++i)
	{
		if (s[i].flag) cnt++;
	}
	if (cnt == 0)
	{
		cout << "��ǰû���κξ�����Ϣ" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "���еľ������£�" << endl << endl;
	for (int i = 0; i < MAX; ++i)
	{
		if (s[i].flag) cout << s[i].num  <<"           " << s[i].name << endl;
	}
	cout << endl;
	cout << "��������Ҫ�鿴�ľ��������:" << endl;
	string name;
	cin >> name;
	cout << endl << endl << endl;
	for (int i = 0; i < MAX; ++i)
	{
		if (s[i].flag == 1 && s[i].name == name)
		{
			cout << "                 " << name << "                       " << endl << endl;
			cout << "����ļ�����£�" << endl << endl;
			cout << "  ";
			for (int j = 0; j < s[i].msg.size(); ++j)
			{
				cout << s[i].msg[j];
				if (j != 0 && j % 20 == 0) cout << endl;
			}
			cout << endl << endl;
			cout << name << "�����ľ��㻹�У�" << endl;
			for (int k = 0; k < MAX; ++k)
			{
				if (graphs[i][k].length != -1 && graphs[i][k].times != -1)
				{
					cout << "   " << s[k].name << "\t\t" << "�ڵ�ǰλ�õ� " << dic(s[i], s[k]) <<" " << graphs[i][k].length << "m��\t";
					cout << "��;�ľ�ɫ�ȼ�Ϊ��" << graphs[i][k].score << "\t\t";
					if (graphs[i][k].road == 1)
					{
						cout << "��·���� �����е�" << endl;
					}
					else cout << "��·���� ������" << endl;
				}
			}
			cout << endl;
			Sleep(2000);
			system("pause");
			system("cls");
			return;
		}
	}
	cout << "������ľ�����������" << endl; 
	system("pause");
	system("cls");
}

//���·��dfs
void tourist::dfs1(int start,int end)
{
	if (start == end)
	{
		if (sum < result)
		{
			result = sum;
			ans = path;
	    }
		return;
	}
	for (int j = 0; j < MAX; ++j)
	{
		if (!visited[j] && graphs[start][j].length > 0)
		{
			sum += graphs[start][j].length;
			if (sum > result)
			{
				sum -= graphs[start][j].length;
				return;
			}
			path.push_back(j);
			visited[j] = true;
			dfs1(j, end);
			visited[j] = false;
			path.pop_back();
			sum -= graphs[start][j].length;
		}
	}
}

//�鿴����֮������·��
void tourist::cheakshortest()
{
	system("pause");
	system("cls");
	visited.assign(MAX, false);
	path.clear();
	ans.clear();
	result = INT_MAX;
	sum = 0;
	int v, w;
	cout << "�������������ı��:" << endl;
	cin >> v;
	cout << "������Ŀ�ľ���ı��:" << endl;
	cin >> w;
	if (s[v].flag == 0 || s[w].flag == 0)
	{
		cout << "����������" << endl;
		system("pause");
		system("cls");
		return;
	}
	path.push_back(v);
	visited[v] = true;
	dfs1(v,w);
	for (int i = 0; i < ans.size() - 1; ++i)
	{
		cout << s[ans[i]].name <<" �� " << dic(s[ans[i]], s[ans[i+1]])<< " �� " << graphs[ans[i]][ans[i + 1]].length << "m ��" << s[ans[i + 1]].name << "   "  << endl;
	}
	cout << "һ���� " << result << " m" << endl;
	system("pause");
	system("cls");
}

//dfs2 ��·����
void tourist::dfs2(int start,int end,int flag)
{
	if (start == end)
	{
		RES.push_back(path);
		return;
	}
	for (int j = 0; j < MAX; ++j)
	{
		if (!visited[j] && (graphs[start][j].road == flag || graphs[start][j].road == 3))
		{
			path.push_back(j);
			visited[j] = true;
			dfs2(j, end,flag);
			visited[j] = false;
			path.pop_back();
		}
	}
}

//��ѯ����·��
void tourist::walkingroad()
{
	system("pause");
	system("cls");
	visited.assign(MAX, false);
	path.clear();
	ans.clear();
	result = INT_MAX;
	sum = 0;
	int v, w;
	cout << "�������������ı��:" << endl;
	cin >> v;
	cout << "������Ŀ�ľ���ı��:" << endl;
	cin >> w;
	if (s[v].flag == 0 || s[w].flag == 0)
	{
		cout << "����������" << endl;
		system("pause");
		system("cls");
		return;
	}
	path.push_back(v);
	visited[v] = true;
	dfs2(v, w, 1);
	int cnt = 0;
	for (auto& elem : RES)
	{
		cnt++;
		cout << "��" << cnt << "��������" << endl << endl;
		for (int i = 0; i < elem.size() - 1; ++i)
		{
			cout << s[elem[i]].name << " �� " << dic(s[elem[i]], s[elem[i + 1]])
				<< " �� " << graphs[elem[i]][elem[i + 1]].length << "m ��"
				<< s[elem[i + 1]].name << "   " << endl;
		}
	}
	cout << "һ����" << cnt << "�����е����߷���" << endl;
	system("pause");
	system("cls");
}

//��ѯ����·��
void tourist::carroad()
{
	system("pause");
	system("cls");
	RES.clear();
	visited.assign(MAX, false);
	path.clear();
	result = INT_MAX;
	sum = 0;
	int v, w;
	cout << "�������������ı��:" << endl;
	cin >> v;
	cout << "������Ŀ�ľ���ı��:" << endl;
	cin >> w;
	if (s[v].flag == 0 || s[w].flag == 0)
	{
		cout << "����������" << endl;
		system("pause");
		system("cls");
		return;
	}
	path.push_back(v);
	visited[v] = true;
	dfs2(v, w, 2);
	int cnt = 0;
	for (auto& elem : RES)
	{
		cnt++;
		cout << "��" << cnt << "��������" << endl;
		for (int i = 0; i < elem.size() - 1; ++i)
		{
			cout << s[elem[i]].name << " �� " << dic(s[elem[i]], s[elem[i + 1]])
				<< " �� " << graphs[elem[i]][elem[i + 1]].length << "m ��"
				<< s[elem[i + 1]].name << "   " << endl;
		}
		cout << endl;
	}
	cout << "һ����" << cnt << "��������ʻ����" << endl;
	system("pause");
	system("cls");
}

//dfs3 ��ɫ�ȼ�
void tourist::dfs3(int start, int end,int score)
{
	if (start == end)
	{
		RES.push_back(path);
		return;
	}
	for (int j = 0; j < MAX; ++j)
	{
		if (!visited[j] && graphs[start][j].score >= score)
		{
			path.push_back(j);
			visited[j] = true;
			dfs3(j, end,score);
			visited[j] = false;
			path.pop_back();
		}
	}
}

//����ľ�ɫ�ȼ�·��
void tourist::scoreroad()
{
	system("pause");
	system("cls");
	visited.assign(MAX, false);
	path.clear();
	ans.clear();
	result = INT_MAX;
	sum = 0;
	int v, w;
	cout << "�������������ı��:" << endl;
	cin >> v;
	cout << "������Ŀ�ľ���ı��:" << endl;
	cin >> w;
	if (s[v].flag == 0 || s[w].flag == 0)
	{
		cout << "����������" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "������·;�����ٵľ�ɫ�ȼ���(1--10)" << endl;
	int score; cin >> score;
	path.push_back(v);
	visited[v] = true;
	dfs3(v, w,score);
	int cnt = 0;
	for (auto& elem : RES)
	{
		cnt++;
		cout << "��" << cnt << "��������" << endl ;
		for (int i = 0; i < elem.size() - 1; ++i)
		{
			cout << s[elem[i]].name << " �� " << dic(s[elem[i]], s[elem[i + 1]])
				<< " �� " << graphs[elem[i]][elem[i + 1]].length << "m ��"
				<< s[elem[i + 1]].name << "   " << endl;
		}
		cout << endl;
	}
	cout << "һ����" << cnt << "������" << endl;
	system("pause");
	system("cls");
}

//���·��
void tourist::dfs4(int x)
{
	if (path.size() >= 2)
	{
		RES.push_back(path);
	}
	for (int j = 0; j < MAX; ++j)
	{
		if (!visited[j] && graphs[x][j].length > 0)
		{
			path.push_back(j);
			visited[j] = true;
			dfs4(j);
			visited[j] = false;
			path.pop_back();
		}
	}
}

//��������·���滮
void tourist::planing()
{
	system("pause");
	system("cls");
	int cnt = 0;
	for (int i = 0; i < MAX; ++i)
	{
		if (s[i].flag) cnt++;
	}
	if (cnt == 0)
	{
		cout << "��ǰû���κξ�����Ϣ" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "���еľ������£�" << endl << endl;
	for (int i = 0; i < MAX; ++i)
	{
		if (s[i].flag) cout << s[i].num << "           " << s[i].name << endl;
	}
	cout << endl;
	RES.clear();
	path.clear();
	plan.clear();
	visited.assign(MAX, false);
	cout << "��������Ҫ�����Ŀ�ʼ����ı��:" << endl;
	int start = 0;
	cin >> start;
	if (!s[start].flag)
	{
		cout << "����������" << endl;
		system("pause");
		system("cls");
		return;
	}
	visited[start] = true;
	plan.push_back(start);
	path.push_back(start);
	dfs4(start);
	string ch;
	cout << "��������������Ҫ�����ľ���ı��(�����յ㣬�Կո�ָ�,�����0��β)��" << endl;
	while (cin >> ch && ch != "0")
	{
		if (!s[atoi(ch.c_str())].flag)
		{
			cout << "����������" << endl;
			system("pause");
			system("cls");
			return;
		}
		plan.push_back(atoi(ch.c_str()));
	}
	sort(plan.begin(), plan.end());
	int end = 0;
	cout << "������������������ľ���ı�ţ�" << endl;
	cin >> end;
	if (!s[end].flag)
	{
		cout << "����������" << endl;
		system("pause");
		system("cls");
		return;
	}
	cnt = 0;
	for (int i = 0; i < RES.size(); ++i)
	{
		if (RES[i][RES[i].size() - 1] != end) continue;
		if (RES[i].size() != plan.size()) continue;
		vector<int>temp = RES[i];
		sort(RES[i].begin(), RES[i].end());
		if (!equal(RES[i].begin(), RES[i].end(), plan.begin(), plan.end())) continue;
		cnt++;
		cout << "��" << cnt << "��������" << endl;
		for (int j = 0; j < temp.size() - 1; ++j)
		{
			cout << s[temp[j]].name << " �� " << dic(s[temp[j]], s[temp[j + 1]])
				<< " �� " << graphs[temp[j]][temp[j + 1]].length << "m ��"
				<< s[temp[j + 1]].name << "   " << endl;
		}

	}
	cout << "һ����" << cnt << "����������" << endl;
	system("pause");
	system("cls");
}

//ʵ����������֮�����·���Ĳ�ѯ(Dijkstraʵ�ֵ�Դ���·��)
void tourist::Dijkstraroad()
{
	system("pause");
	system("cls");
	int cnt = 0;
	for (int i = 0; i < MAX; ++i)
	{
		if (s[i].flag) cnt++;
	}
	if (cnt == 0)
	{
		cout << "��ǰû���κξ�����Ϣ" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "���еľ������£�" << endl << endl;
	for (int i = 0; i < MAX; ++i)
	{
		if (s[i].flag) cout << s[i].num << "           " << s[i].name << endl;
	}
	cout << endl << endl;
	memset(minDist,1000005,sizeof(minDist));
	memset(vis, 0, sizeof(vis));
	system("pause");
	cout << "��������Ҫ�鿴����������ı��:(�Կո�ָ��)" << endl;
	int x, y;
	cin >> x >> y;
	cout << endl;
	//��ʼ�����
	minDist[x] = 0;
	priority_queue<pair<int,int>>que;
	que.push(pair<int,int>(0,x));
	while (!que.empty())
	{
		auto cur = que.top();
		que.pop();
		if (vis[cur.second]) continue;//�˾���Ϊ�˷�ֹ�ظ����ʣ����Ч��
		if (cur.second == y) break;
		vis[cur.second] = 1;
		for (int i = 0; i < MAX; ++i)
		{
			if (graphs[cur.second][i].length == -1) continue;//��־��������ôһ���ڽӱ�
			if (vis[i]) continue;//��־����ڽӵ� �Լ������ʹ���
			if (minDist[i] > minDist[cur.second] + graphs[cur.second][i].length)
			{
				minDist[i] = minDist[cur.second] + graphs[cur.second][i].length;
				que.push(pair<int,int>(minDist[i],i));
			}
		}
	}
	cout << "��Ҫ��ѯ����������֮������·��Ϊ��" << minDist[y] << "m" << endl;
	system("pause");
	system("cls");
}
