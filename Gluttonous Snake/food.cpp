#include<cstdio>
#include"food.h"
#include"windows.h"

CFood::CFood():m_FoodExist(0), flag(0){}//初始化食物不存在

//生成食物
void CFood::CreateFood(char nMap[MAP_X][MAP_Y]) {
	
	if (m_FoodExist == 0) {
		while (true) {
			//随机生成食物
			foodX = rand() % (MAP_X - 2) + 1;
			foodY = rand() % (MAP_Y - 2) + 1;
			// 如果随机的位置是蛇头或蛇身，就重新生成随机数
			if (nMap[foodX][foodY] == SPACE) {
				nMap[foodX][foodY] = FOOD;
				int n = foodX % 5;
				if (n == 0){	//根据食物产生的X坐标不同而生成不同的食物
					flag = 星形;
					m_objHandle.WriteChar(foodX, foodY, 0x9, "★");
					m_FoodExist = 1;
				}
				else if (n == 1){	
					flag = 三角;
					m_objHandle.WriteChar(foodX, foodY, 0xA, "▲");
					m_FoodExist = 1;
				}
				else if (n == 2) {
					flag = 菱形;
					m_objHandle.WriteChar(foodX, foodY, 0xF, "◆");
					m_FoodExist = 1;
				}
				else if (n == 3) {
					flag = 方形;
					m_objHandle.WriteChar(foodX, foodY, 0xD, "■");
					m_FoodExist = 1;
				}
				else if (n == 4) {
					flag = 圆形;
					m_objHandle.WriteChar(foodX, foodY, 0xC, "●");
					m_FoodExist = 1;
				}
					
				return;
				
			}
		}
	}
	
}
//设置食物的不同状态
void CFood::SetFoodExist(int nFoodExist) {
	m_FoodExist = nFoodExist;
}

