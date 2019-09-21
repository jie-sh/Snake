#pragma once
#ifndef MAPH
#define MAPH
#include"handle.h"
#include"snake.h"
#include"food.h"

class CMap {
public:
	void InitMap();//��ʼ����ͼ
	void DrawMap();//����ͼ
	void StartGame();//��ʼ��Ϸ
	int Landform();//�Զ������
	char m_Map[MAP_X][MAP_Y];
private:
	CHandle m_objHandle;
	CSnake m_objSnake;
	CFood m_objFood;
};

#endif