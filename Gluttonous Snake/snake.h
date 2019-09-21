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
	//初始化蛇
	void InitSnake(char nMap[MAP_X][MAP_Y]);
	// 销毁蛇
	void DestroySnake();
	// 添加蛇头
	void AddSnake(int x, int y, char nMap[MAP_X][MAP_Y]);
	//删除蛇尾
	void DeleteSnake(char nMap[MAP_X][MAP_Y]);
	// 获取用户的输入，修改方向
	int GetDir();
	//蛇移动
	int SnakeMove(char nMap[MAP_X][MAP_Y], CFood& Food);
	//获取蛇长
	int CountSnake();
	//获取速度
	int GetSleepTime();
	//分数
	int Score;	
private:
	CHandle m_objHandle;
	Point *pHead;
	int Dir;
};

#endif