
#include <iostream>
#include<windows.h>
//#include <conio.h>
#include "map.h"
#pragma comment(lib, "winmm.lib")



using namespace std;

//CMap::CMap() :map(0) {}

//��ʼ����ͼ
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

//����ͼ
void CMap::DrawMap() {
	union _COLOR {
		WORD c0 = 0x8;
	}Color;
	for (int i = 0; i < MAP_X; i++)
	{
		for (int j = 0; j < MAP_Y; j++) {
			if (m_Map[i][j] == BARRIER)
			{
					m_objHandle.WriteChar(i, j, Color.c0++, "��");
			}
				
			if (m_Map[i][j] == SPACE)
				m_objHandle.WriteChar(i, j, 0xF, "  ");

		}
		for (int i = 10; i < 20; i++)
		{
			int n = i % 10;
			if(m_Map[i][10] == BARRIER)
				m_objHandle.WriteChar(i, 10, 0xB, "��");
		}
		for (int j = 25; j < 40; j++) {
			if(m_Map[35][j] == BARRIER)
				m_objHandle.WriteChar(35, j, 0xB, "��");
		}

		//�Ҳ���ʾ����
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

//��ʼ��Ϸ
void CMap::StartGame() {

	//��������
	PlaySoundA("Sound\\֣���� - ���ȥ.wav", NULL, SND_ASYNC | SND_NODEFAULT);
	m_objSnake.InitSnake(m_Map);
	m_objFood.SetFoodExist(0);
	int nLive = 1;
	while (nLive) {
		m_objSnake.GetDir();
		nLive = m_objSnake.SnakeMove(m_Map, m_objFood);
		if (nLive) {
			//�෽��ʾ����
			m_objHandle.WriteChar(18, 52, 0xA, "Score:");
			cout << m_objSnake.Score << " points" << endl;
			//�෽��ʾ�ߵ��ٶ�
			m_objHandle.WriteChar(20, 52, 0xA, "The speed of the snake:");
			cout << m_objSnake.GetSleepTime() << endl;
			Sleep(m_objSnake.GetSleepTime());
		}
		m_objFood.CreateFood(m_Map);
	}
	m_objSnake.Score = 0;
}

//�Զ������
int CMap::Landform() {
	// ��ȡ����̨���뻺�����ľ��
	HANDLE InputHandle = GetStdHandle(STD_INPUT_HANDLE);
	// ��������¼��Ľ���: ENABLE_MOUSE_INPUT
	SetConsoleMode(InputHandle, ENABLE_MOUSE_INPUT);
	DWORD Number = 0;
	// ���ڱ����ȡ�����¼�
	INPUT_RECORD InputRecord = { 0 };
	// ��дһ��ѭ�������ϵĻ�ȡ��ǰ�����¼�
	//	- 1: ��Ҫ��ȡ��һ������̨�������¼�
	//	- 2: һ���ṹ�壬�����˻�ȡ���������¼�
	//	- 3: ��������ʾ�ṩ�Ľṹ���м���(1)
	//	- 4: ��ǰ��ȡ���˼����¼�
	while (ReadConsoleInput(InputHandle, &InputRecord, 1, &Number))
	{
		// ���ܵ��¼���ֹ���������,������Ҫ�����ж�
		if (InputRecord.EventType == MOUSE_EVENT)
		{
			// ��ȡ����������
			COORD MouseCoord = InputRecord.Event.MouseEvent.dwMousePosition;
			// Ϊ���е�����¼������������Ĵ���
			CHAR Buffer[0x100] = { 0 };
			// ͨ�����������Ļ���Ӧ��ֱ�ӷ�ӳ�����ͼ��ص������У�
			// ��������Ϸ�а��ݵĵ�ͼ�����Ƶ�ͼ�ο������ϰ���������
			// ����¼��зǳ��࣬���ǿ��Ե�����Ӧĳһ���¼�
			if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				// ������������ˣ���ִ������
				m_Map[MouseCoord.Y][MouseCoord.X / 2] = BARRIER;
				int n = MouseCoord.Y % 16;
				m_objHandle.WriteChar(MouseCoord.Y, MouseCoord.X / 2, 0x9 | n, "��");
			}
			else if (InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
			{
				StartGame();//��ʼ��Ϸ
				return 0;

			}

		}
	}
}


