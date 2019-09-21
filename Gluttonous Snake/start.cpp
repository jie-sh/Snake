#include<iostream>
#include<cstdlib>
#include"start.h"
#include"map.h"
#include "handle.h"
#include"area.h"
using namespace std;

void CStart::Menu()//�˵���
{
	m_objHandle.WriteChar(10, 29, 0xF, "��ӭ��̰����С��Ϸ");
	m_objHandle.WriteChar(12, 30, 0xD, "������һ��ѡ�");
	m_objHandle.WriteChar(14, 30, 0xB, "1��������Ϸ");
	m_objHandle.WriteChar(16, 30, 0xC, "2���˳���Ϸ");
	m_objHandle.WriteChar(18, 30, 0x9, "3���Զ�����Ϸ");
	printf("\n\n\n");
}

CStart::CStart() :m_nChoice(1) {}

void CStart::Opetion(CMap& Map)//����ѡ�ʼ��Ϸ
{
	while (m_nChoice) {
		Menu();
		cin >> m_nChoice;
		switch (m_nChoice) {
		case STARGAME://��ʼ��Ϸ
			Map.InitMap();
			Map.DrawMap();
			Map.StartGame();
			break;

		case EXIT://�˳���Ϸ
			m_nChoice = 0;
			break;

		case AREA://�Զ������
			Map.InitMap();
			Map.DrawMap();
			Map.Landform();
			break;
		}
	}
}
