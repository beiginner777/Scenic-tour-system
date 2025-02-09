#pragma once

class Manager
{
public:
	string name;//管理员的账号
	string pin;//管理员的密码
	void manaage_login();//登录功能
	void hidepin(string& pin);//是否显示在控制台输入的密码
	void superrootmenu();//超级管理员的菜单
	void superrootfunc();//超级管理员的功能
	void addmanager();//添加管理员
	void cheakmanager();//查看所有管理员的信息
	void managerfunc();//普通管理员的功能
	void managermenu();//普通管理员的菜单
	void addspot();//添加景点
	void delspot();//删除景点
	void cheakspot();//查看所有景点信息
	void modspot();//修改景点信息
	void adddis();//添加道路
	void deldis();//删除道路
	void cheakdis();//查看所有道路信息
	void moddis();//修改道理信息
};
