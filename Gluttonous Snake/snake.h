#pragma once
#ifndef SNAKEH
#define SNAKEH
#include"handle.h"
#include"food.h"
#include"start.h"

class CSnake {
public:
	struct Point {
		short x;
		short y;
		Point *next;
	};
	CSnake();
	//��ʼ����
	void InitSnake(char nMap[MAP_X][MAP_Y]);
	// ������
	void DestroySnake();
	// �����ͷ
	void AddSnake(int x, int y, char nMap[MAP_X][MAP_Y]);
	//ɾ����β
	void DeleteSnake(char nMap[MAP_X][MAP_Y]);
	// ��ȡ�û������룬�޸ķ���
	int GetDir();
	//���ƶ�
	int SnakeMove(char nMap[MAP_X][MAP_Y], CFood& Food);
	//��ȡ�߳�
	int CountSnake();
	//��ȡ�ٶ�
	int GetSleepTime();
	//����
	int Score;	
private:
	CHandle m_objHandle;
	Point *pHead;
	int Dir;
};

#endif