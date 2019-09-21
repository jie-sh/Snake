#include<iostream>
#include<cstdlib>
#include"start.h"
#include"map.h"
#include "handle.h"
#include"area.h"
using namespace std;

void CStart::Menu()//菜单栏
{
	m_objHandle.WriteChar(10, 29, 0xF, "欢迎玩贪吃蛇小游戏");
	m_objHandle.WriteChar(12, 30, 0xD, "请输入一下选项：");
	m_objHandle.WriteChar(14, 30, 0xB, "1、常规游戏");
	m_objHandle.WriteChar(16, 30, 0xC, "2、退出游戏");
	m_objHandle.WriteChar(18, 30, 0x9, "3、自定义游戏");
	printf("\n\n\n");
}

CStart::CStart() :m_nChoice(1) {}

void CStart::Opetion(CMap& Map)//根据选项开始游戏
{
	while (m_nChoice) {
		Menu();
		cin >> m_nChoice;
		switch (m_nChoice) {
		case STARGAME://开始游戏
			Map.InitMap();
			Map.DrawMap();
			Map.StartGame();
			break;

		case EXIT://退出游戏
			m_nChoice = 0;
			break;

		case AREA://自定义地形
			Map.InitMap();
			Map.DrawMap();
			Map.Landform();
			break;
		}
	}
}
