#pragma once
#ifndef FOODH
#define FOODH
#include"handle.h"
class CFood {
public:	
	CFood();
	void CreateFood(char nMap[MAP_X][MAP_Y]);//生成食物
	void SetFoodExist(int nFoodExist);//判断食物是否存在
	int flag;
private:
	int foodX;
	int foodY;
	int m_FoodExist;//食物的状态
	CHandle m_objHandle;
};
#endif