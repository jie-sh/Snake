#pragma once
#ifndef FOODH
#define FOODH
#include"handle.h"
class CFood {
public:	
	CFood();
	void CreateFood(char nMap[MAP_X][MAP_Y]);//����ʳ��
	void SetFoodExist(int nFoodExist);//�ж�ʳ���Ƿ����
	int flag;
private:
	int foodX;
	int foodY;
	int m_FoodExist;//ʳ���״̬
	CHandle m_objHandle;
};
#endif