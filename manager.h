#pragma once

class Manager
{
public:
	string name;//����Ա���˺�
	string pin;//����Ա������
	void manaage_login();//��¼����
	void hidepin(string& pin);//�Ƿ���ʾ�ڿ���̨���������
	void superrootmenu();//��������Ա�Ĳ˵�
	void superrootfunc();//��������Ա�Ĺ���
	void addmanager();//��ӹ���Ա
	void cheakmanager();//�鿴���й���Ա����Ϣ
	void managerfunc();//��ͨ����Ա�Ĺ���
	void managermenu();//��ͨ����Ա�Ĳ˵�
	void addspot();//��Ӿ���
	void delspot();//ɾ������
	void cheakspot();//�鿴���о�����Ϣ
	void modspot();//�޸ľ�����Ϣ
	void adddis();//��ӵ�·
	void deldis();//ɾ����·
	void cheakdis();//�鿴���е�·��Ϣ
	void moddis();//�޸ĵ�����Ϣ
};
