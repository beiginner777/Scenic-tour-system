#include"head.h"

void tourist::menu()
{
	cout << "******欢迎使用旅游区导览系统*******" << endl;
	cout << "********0-------注销登录***********" << endl;
	cout << "********1-------查看最短路径*******" << endl;
	cout << "********2-------查看景点信息*******" << endl;
	cout << "********3-------搜索人行道路径*****" << endl;
	cout << "********4-------搜索车道路径*******" << endl;
	cout << "********5-------搜索景色路径*******" << endl;
	cout << "********6-------游览方案规划*******" << endl;
	cout << "********7-------旅游区地图展示*****" << endl;
	cout << "********8-------景点最短路程*******" << endl;
	cout << "***********************************" << endl;
}

//游客的功能
void tourist::touristfunc()
{
	system("pause");
	system("cls");
	while (true)
	{
		this->menu();
		int sel;
		cout << "请输入您的选择:" << endl;
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
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
		}
	}
}

//查看景点的信息
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
		cout << "当前没有任何景点信息" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "所有的景点如下：" << endl << endl;
	for (int i = 0; i < MAX; ++i)
	{
		if (s[i].flag) cout << s[i].num  <<"           " << s[i].name << endl;
	}
	cout << endl;
	cout << "请输入您要查看的景点的名称:" << endl;
	string name;
	cin >> name;
	cout << endl << endl << endl;
	for (int i = 0; i < MAX; ++i)
	{
		if (s[i].flag == 1 && s[i].name == name)
		{
			cout << "                 " << name << "                       " << endl << endl;
			cout << "景点的简介如下：" << endl << endl;
			cout << "  ";
			for (int j = 0; j < s[i].msg.size(); ++j)
			{
				cout << s[i].msg[j];
				if (j != 0 && j % 20 == 0) cout << endl;
			}
			cout << endl << endl;
			cout << name << "附近的景点还有：" << endl;
			for (int k = 0; k < MAX; ++k)
			{
				if (graphs[i][k].length != -1 && graphs[i][k].times != -1)
				{
					cout << "   " << s[k].name << "\t\t" << "在当前位置的 " << dic(s[i], s[k]) <<" " << graphs[i][k].length << "m处\t";
					cout << "沿途的景色等级为：" << graphs[i][k].score << "\t\t";
					if (graphs[i][k].road == 1)
					{
						cout << "道路类型 ：人行道" << endl;
					}
					else cout << "道路类型 ：车道" << endl;
				}
			}
			cout << endl;
			Sleep(2000);
			system("pause");
			system("cls");
			return;
		}
	}
	cout << "您输入的景点名称有误" << endl; 
	system("pause");
	system("cls");
}

//最短路径dfs
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

//查看景点之间的最短路径
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
	cout << "请输入出发景点的编号:" << endl;
	cin >> v;
	cout << "请输入目的景点的编号:" << endl;
	cin >> w;
	if (s[v].flag == 0 || s[w].flag == 0)
	{
		cout << "编号输入错误" << endl;
		system("pause");
		system("cls");
		return;
	}
	path.push_back(v);
	visited[v] = true;
	dfs1(v,w);
	for (int i = 0; i < ans.size() - 1; ++i)
	{
		cout << s[ans[i]].name <<" 往 " << dic(s[ans[i]], s[ans[i+1]])<< " 走 " << graphs[ans[i]][ans[i + 1]].length << "m 到" << s[ans[i + 1]].name << "   "  << endl;
	}
	cout << "一共有 " << result << " m" << endl;
	system("pause");
	system("cls");
}

//dfs2 道路类型
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

//查询人行路径
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
	cout << "请输入出发景点的编号:" << endl;
	cin >> v;
	cout << "请输入目的景点的编号:" << endl;
	cin >> w;
	if (s[v].flag == 0 || s[w].flag == 0)
	{
		cout << "编号输入错误" << endl;
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
		cout << "第" << cnt << "条方案：" << endl << endl;
		for (int i = 0; i < elem.size() - 1; ++i)
		{
			cout << s[elem[i]].name << " 往 " << dic(s[elem[i]], s[elem[i + 1]])
				<< " 走 " << graphs[elem[i]][elem[i + 1]].length << "m 到"
				<< s[elem[i + 1]].name << "   " << endl;
		}
	}
	cout << "一共有" << cnt << "个人行道行走方案" << endl;
	system("pause");
	system("cls");
}

//查询车道路径
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
	cout << "请输入出发景点的编号:" << endl;
	cin >> v;
	cout << "请输入目的景点的编号:" << endl;
	cin >> w;
	if (s[v].flag == 0 || s[w].flag == 0)
	{
		cout << "编号输入错误" << endl;
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
		cout << "第" << cnt << "条方案：" << endl;
		for (int i = 0; i < elem.size() - 1; ++i)
		{
			cout << s[elem[i]].name << " 往 " << dic(s[elem[i]], s[elem[i + 1]])
				<< " 走 " << graphs[elem[i]][elem[i + 1]].length << "m 到"
				<< s[elem[i + 1]].name << "   " << endl;
		}
		cout << endl;
	}
	cout << "一共有" << cnt << "个车道行驶方案" << endl;
	system("pause");
	system("cls");
}

//dfs3 景色等级
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

//景点的景色等级路径
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
	cout << "请输入出发景点的编号:" << endl;
	cin >> v;
	cout << "请输入目的景点的编号:" << endl;
	cin >> w;
	if (s[v].flag == 0 || s[w].flag == 0)
	{
		cout << "编号输入错误" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入路途中最少的景色等级：(1--10)" << endl;
	int score; cin >> score;
	path.push_back(v);
	visited[v] = true;
	dfs3(v, w,score);
	int cnt = 0;
	for (auto& elem : RES)
	{
		cnt++;
		cout << "第" << cnt << "条方案：" << endl ;
		for (int i = 0; i < elem.size() - 1; ++i)
		{
			cout << s[elem[i]].name << " 往 " << dic(s[elem[i]], s[elem[i + 1]])
				<< " 走 " << graphs[elem[i]][elem[i + 1]].length << "m 到"
				<< s[elem[i + 1]].name << "   " << endl;
		}
		cout << endl;
	}
	cout << "一共有" << cnt << "个方案" << endl;
	system("pause");
	system("cls");
}

//求简单路径
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

//多个景点的路径规划
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
		cout << "当前没有任何景点信息" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "所有的景点如下：" << endl << endl;
	for (int i = 0; i < MAX; ++i)
	{
		if (s[i].flag) cout << s[i].num << "           " << s[i].name << endl;
	}
	cout << endl;
	RES.clear();
	path.clear();
	plan.clear();
	visited.assign(MAX, false);
	cout << "请输入您要游览的开始景点的编号:" << endl;
	int start = 0;
	cin >> start;
	if (!s[start].flag)
	{
		cout << "编号输入错误" << endl;
		system("pause");
		system("cls");
		return;
	}
	visited[start] = true;
	plan.push_back(start);
	path.push_back(start);
	dfs4(start);
	string ch;
	cout << "请输入您接下来要游览的景点的编号(包含终点，以空格分隔,最后以0结尾)：" << endl;
	while (cin >> ch && ch != "0")
	{
		if (!s[atoi(ch.c_str())].flag)
		{
			cout << "编号输入错误" << endl;
			system("pause");
			system("cls");
			return;
		}
		plan.push_back(atoi(ch.c_str()));
	}
	sort(plan.begin(), plan.end());
	int end = 0;
	cout << "请输入您将最后游览的景点的编号：" << endl;
	cin >> end;
	if (!s[end].flag)
	{
		cout << "编号输入错误" << endl;
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
		cout << "第" << cnt << "个方案：" << endl;
		for (int j = 0; j < temp.size() - 1; ++j)
		{
			cout << s[temp[j]].name << " 往 " << dic(s[temp[j]], s[temp[j + 1]])
				<< " 走 " << graphs[temp[j]][temp[j + 1]].length << "m 到"
				<< s[temp[j + 1]].name << "   " << endl;
		}

	}
	cout << "一共有" << cnt << "个游览方案" << endl;
	system("pause");
	system("cls");
}

//实现两个景点之间最短路径的查询(Dijkstra实现单源最短路径)
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
		cout << "当前没有任何景点信息" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "所有的景点如下：" << endl << endl;
	for (int i = 0; i < MAX; ++i)
	{
		if (s[i].flag) cout << s[i].num << "           " << s[i].name << endl;
	}
	cout << endl << endl;
	memset(minDist,1000005,sizeof(minDist));
	memset(vis, 0, sizeof(vis));
	system("pause");
	cout << "请输入您要查看的两个景点的编号:(以空格分割即可)" << endl;
	int x, y;
	cin >> x >> y;
	cout << endl;
	//初始化起点
	minDist[x] = 0;
	priority_queue<pair<int,int>>que;
	que.push(pair<int,int>(0,x));
	while (!que.empty())
	{
		auto cur = que.top();
		que.pop();
		if (vis[cur.second]) continue;//此句是为了防止重复访问，提高效率
		if (cur.second == y) break;
		vis[cur.second] = 1;
		for (int i = 0; i < MAX; ++i)
		{
			if (graphs[cur.second][i].length == -1) continue;//标志不存在这么一条邻接边
			if (vis[i]) continue;//标志这个邻接点 以及被访问过了
			if (minDist[i] > minDist[cur.second] + graphs[cur.second][i].length)
			{
				minDist[i] = minDist[cur.second] + graphs[cur.second][i].length;
				que.push(pair<int,int>(minDist[i],i));
			}
		}
	}
	cout << "您要查询的两个景点之间的最短路径为：" << minDist[y] << "m" << endl;
	system("pause");
	system("cls");
}
