#include<cstdio>
#include <conio.h>
#include<windows.h>
#include"snake.h"

#pragma comment(lib, "winmm.lib")

CSnake::CSnake():Score(0)
{
	pHead = nullptr;
}

//初始化蛇
void CSnake::InitSnake(char nMap[MAP_X][MAP_Y]) {
	DestroySnake();
	Dir = RIGHT;//初始化方向向右
	AddSnake(4, 4, nMap);
	AddSnake(4, 5, nMap);
	AddSnake(4, 6, nMap);
}

// 销毁蛇
void CSnake::DestroySnake() {
	Point *pCur = pHead;
	while (pHead != nullptr) {
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	}
}

// 添加蛇头
void CSnake::AddSnake(int x, int y, char nMap[MAP_X][MAP_Y]) {//将头节点变为身子节点
									 
	Point *newPoint = new Point;
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = nullptr;
	//若原头节点不为空，则变为身子节点
	if (pHead != nullptr) {	
		nMap[x][y] = SNAKE;
		int n = x % 11;
		if (n == 0) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0xC, "■");
		}
		else if (n == 1) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0xA, "◇");
		}
		else if (n == 2) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0xB, "★");
		}
		else if (n == 3) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0xD, "△");
		}
		else if (n == 4) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0xE, "◆");
		}
		else if (n == 5) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0x9, "○");
		}
		else if (n == 6) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0x8, "▼");
		}
		else if (n == 7) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0xB, "□");
		}
		else if (n == 8) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0x9, "▲");
		}
		else if (n == 8) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0xA, "▽");
		}
		else if (n == 9) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0xD, "●");
		}
		else if (n == 10) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0x8, "☆");
		}
			
	}
	newPoint->next = pHead;
	pHead = newPoint;
	m_objHandle.WriteChar(pHead->x, pHead->y, 0xF, "●");
	
}

//删除蛇尾
void CSnake::DeleteSnake(char nMap[MAP_X][MAP_Y]) {
	if (pHead == nullptr || pHead->next == nullptr)
		return;
	Point *pCur = pHead->next, *pPre = pHead;
	while (pCur->next != nullptr) {
		pPre = pPre->next;
		pCur = pCur->next;
	}
	nMap[pCur->x][pCur->y] = SPACE;
	m_objHandle.WriteChar(pCur->x, pCur->y, 0xF, "  ");
	delete pCur;
	pCur = nullptr;
	pPre->next = nullptr;
}


// 获取用户的输入，修改方向和控制
int CSnake::GetDir() {
	
	// 游戏本身不能被阻塞，所以使用过的函数不能是阻塞函数
	if (_kbhit())
	{		
		// 这是一个非阻塞函数，一旦按下任何按键，返回 true
		// _getch 是无回显输入，不能使用带回显的函数
		switch (_getch())
		{
		case 'w': Dir = UP; break;
		case 's': Dir = DOWN; break;
		case 'a': Dir = LEFT; break;
		case 'd': Dir = RIGHT; break;
		case 'q':              //暂停			
			while (true) {
				if (_getch() == ' ')				
					break;													
			}break;				
		case 'e': 
			return 0;
		//	SaveSnake(); 
		//	//m_objFile.SaveSnake(Food, Map);
		//	m_objHandle.WriteChar(MAP_X / 2, MAP_Y / 3, 0xA, "游戏存档");
		//	system("pause");			
		//	system("cls");
		//	break;

		//default: break;
		}
	}
}
//蛇移动
int CSnake::SnakeMove(char nMap[MAP_X][MAP_Y], CFood& Food) {
	int x = pHead->x;//x,y为蛇头的坐标
	int y = pHead->y;
	
	// 根据蛇的方向移动蛇的位置
	switch (Dir)
	{
	case UP: x--; break;
	case DOWN: x++; break;
	case LEFT: y--; break;
	case RIGHT: y++; break;

	}
	//判断蛇头触碰到什么
	if (nMap[x][y] == SPACE) {	
		AddSnake(x, y, nMap);
		DeleteSnake(nMap);
	}
	else if (nMap[x][y] == FOOD) {//蛇吃不同的食物加不同的分数
		if (Food.flag == 星形) {
			Score += 10;
		}
		else if (Food.flag == 三角) {			
			Score += 15;
		}
		else if (Food.flag == 菱形) {			
			Score += 20;
		}
		else if (Food.flag == 方形) {			
			Score += -10;
		}
		else if (Food.flag == 圆形) {			
			Score += 0;
		}

		AddSnake(x, y, nMap);
		Food.SetFoodExist(0);
	}
	else if (nMap[x][y] == BARRIER || nMap[x][y] == SNAKE) {		
		PlaySoundA("Sound\\爆炸.wav", NULL, SND_ASYNC | SND_NODEFAULT);//撞击声
		m_objHandle.WriteChar(MAP_X / 2, MAP_Y / 3, 0xA, "GAME OVER!");
		system("pause");
		system("cls");
		return 0; 
	}
	return true;
}

//获取蛇长
int CSnake::CountSnake() {
	int size = 0;
	Point *tPoint = pHead;
	while (tPoint != nullptr) {
		size++;
		tPoint = tPoint->next;
	}
	return size;
}

// 获取刷屏时间
int CSnake::GetSleepTime() {
	int sleeptime = 0;
	int size = CountSnake();
	if (size <= 5)
		sleeptime = 300;
	else if (size > 5 && size <= 10)
		sleeptime = 250;
	else if (size > 10 && size <= 15)
		sleeptime = 200;
	else if (size > 15 && size <= 20)
		sleeptime = 150;
	else
		sleeptime = 100;
	return sleeptime;
}
