#pragma once
#include<iostream>
using namespace std;

class tourist
{
public:
	void menu();//�ο͵Ĳ˵�
	void cheak_scenic_spot();//�鿴������Ϣ
	void cheakshortest();//�鿴����֮����̵�·��
	void touristfunc();//�ο͵Ĺ���
	void walkingroad();//�滮����֮��ֻ�����е���·��
	void carroad();//�滮����֮��ֻ�г�����·��
	void dfs1(int start, int end);//�滮����֮����̵�·��
	void dfs2(int start, int end, int flag); //�滮����֮���·��·��
	void dfs3(int start, int end, int score); //�滮����֮�侰ɫ�ȼ���·��
	void scoreroad();//�滮����֮�侰ɫ�ȼ���·��
	void dfs4(int x); //��������·���滮 
	void planing();//��������·���滮 
	void Dijkstraroad();//�������֮����̵ľ���
};