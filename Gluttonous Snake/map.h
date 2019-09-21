#pragma once
#ifndef MAPH
#define MAPH
#include"handle.h"
#include"snake.h"
#include"food.h"

class CMap {
public:
	void InitMap();//初始化地图
	void DrawMap();//画地图
	void StartGame();//开始游戏
	int Landform();//自定义地形
	char m_Map[MAP_X][MAP_Y];
private:
	CHandle m_objHandle;
	CSnake m_objSnake;
	CFood m_objFood;
};

#endif