
#include <iostream>
#include<windows.h>
//#include <conio.h>
#include "map.h"
#pragma comment(lib, "winmm.lib")



using namespace std;

//CMap::CMap() :map(0) {}

//初始化地图
void CMap::InitMap()
{
	for (int i = 0; i < MAP_X; i++)
	{
		for (int j = 0; j < MAP_Y; j++) {
			if (i == 0 || j == 0 || i == MAP_X - 1 || j == MAP_Y - 1) {
				m_Map[i][j] = BARRIER;
			}
			else				
				m_Map[i][j] = SPACE;
		}
	}
	for (int i = 25; i < 40; i++) {
		m_Map[i][10] = BARRIER;
	}
	for(int j = 10; j < 20; j++)
		m_Map[35][j] = BARRIER;
}

//画地图
void CMap::DrawMap() {
	union _COLOR {
		WORD c0 = 0x8;
	}Color;
	for (int i = 0; i < MAP_X; i++)
	{
		for (int j = 0; j < MAP_Y; j++) {
			if (m_Map[i][j] == BARRIER)
			{
					m_objHandle.WriteChar(i, j, Color.c0++, "※");
			}
				
			if (m_Map[i][j] == SPACE)
				m_objHandle.WriteChar(i, j, 0xF, "  ");

		}
		for (int i = 10; i < 20; i++)
		{
			int n = i % 10;
			if(m_Map[i][10] == BARRIER)
				m_objHandle.WriteChar(i, 10, 0xB, "※");
		}
		for (int j = 25; j < 40; j++) {
			if(m_Map[35][j] == BARRIER)
				m_objHandle.WriteChar(35, j, 0xB, "※");
		}

		//右侧显示操作
		if(i == 10)
			m_objHandle.WriteChar(i, 52, 0xA, "  a: left");
		if (i == 11)
			m_objHandle.WriteChar(i, 52, 0xA, "  d: right");
		if (i == 12)
			m_objHandle.WriteChar(i, 52, 0xA, "  w: up");
		if (i == 13)
			m_objHandle.WriteChar(i, 52, 0xA, "  s: down");
		if (i == 14)
			m_objHandle.WriteChar(i, 52, 0xA, "  e: save");
		if (i == 15)
			m_objHandle.WriteChar(i, 52, 0xA, "  q: pause");
		if (i == 16)
			m_objHandle.WriteChar(i, 52, 0xA, "  space: continue");


		
	}

		
		
}

//开始游戏
void CMap::StartGame() {

	//背景音乐
	PlaySoundA("Sound\\郑秀文 - 冲过去.wav", NULL, SND_ASYNC | SND_NODEFAULT);
	m_objSnake.InitSnake(m_Map);
	m_objFood.SetFoodExist(0);
	int nLive = 1;
	while (nLive) {
		m_objSnake.GetDir();
		nLive = m_objSnake.SnakeMove(m_Map, m_objFood);
		if (nLive) {
			//侧方显示分数
			m_objHandle.WriteChar(18, 52, 0xA, "Score:");
			cout << m_objSnake.Score << " points" << endl;
			//侧方显示蛇的速度
			m_objHandle.WriteChar(20, 52, 0xA, "The speed of the snake:");
			cout << m_objSnake.GetSleepTime() << endl;
			Sleep(m_objSnake.GetSleepTime());
		}
		m_objFood.CreateFood(m_Map);
	}
	m_objSnake.Score = 0;
}

//自定义地形
int CMap::Landform() {
	// 获取控制台输入缓冲区的句柄
	HANDLE InputHandle = GetStdHandle(STD_INPUT_HANDLE);
	// 开启鼠标事件的接受: ENABLE_MOUSE_INPUT
	SetConsoleMode(InputHandle, ENABLE_MOUSE_INPUT);
	DWORD Number = 0;
	// 用于保存读取到的事件
	INPUT_RECORD InputRecord = { 0 };
	// 编写一个循环，不断的获取当前鼠标的事件
	//	- 1: 想要读取哪一个控制台的输入事件
	//	- 2: 一个结构体，保存了获取到的输入事件
	//	- 3: 数量，表示提供的结构体有几个(1)
	//	- 4: 当前读取到了几个事件
	while (ReadConsoleInput(InputHandle, &InputRecord, 1, &Number))
	{
		// 接受的事件不止有鼠标类型,所以需要进行判断
		if (InputRecord.EventType == MOUSE_EVENT)
		{
			// 获取到鼠标的坐标
			COORD MouseCoord = InputRecord.Event.MouseEvent.dwMousePosition;
			// 为所有的鼠标事件进行输出坐标的处理
			CHAR Buffer[0x100] = { 0 };
			// 通常来讲，鼠标的绘制应该直接反映在与绘图相关的数组中，
			// 数组在游戏中扮演的地图，绘制的图形可以是障碍物或者事物。
			// 鼠标事件有非常多，我们可以单独响应某一个事件
			if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				// 鼠标的左键按下了，就执行这里
				m_Map[MouseCoord.Y][MouseCoord.X / 2] = BARRIER;
				int n = MouseCoord.Y % 16;
				m_objHandle.WriteChar(MouseCoord.Y, MouseCoord.X / 2, 0x9 | n, "※");
			}
			else if (InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
			{
				StartGame();//开始游戏
				return 0;

			}

		}
	}
}


