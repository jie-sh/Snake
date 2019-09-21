#include<cstdio>
#include <conio.h>
#include<windows.h>
#include"snake.h"

#pragma comment(lib, "winmm.lib")

CSnake::CSnake():Score(0)
{
	pHead = nullptr;
}

//��ʼ����
void CSnake::InitSnake(char nMap[MAP_X][MAP_Y]) {
	DestroySnake();
	Dir = RIGHT;//��ʼ����������
	AddSnake(4, 4, nMap);
	AddSnake(4, 5, nMap);
	AddSnake(4, 6, nMap);
}

// ������
void CSnake::DestroySnake() {
	Point *pCur = pHead;
	while (pHead != nullptr) {
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	}
}

// �����ͷ
void CSnake::AddSnake(int x, int y, char nMap[MAP_X][MAP_Y]) {//��ͷ�ڵ��Ϊ���ӽڵ�
									 
	Point *newPoint = new Point;
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = nullptr;
	//��ԭͷ�ڵ㲻Ϊ�գ����Ϊ���ӽڵ�
	if (pHead != nullptr) {	
		nMap[x][y] = SNAKE;
		int n = x % 11;
		if (n == 0) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0xC, "��");
		}
		else if (n == 1) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0xA, "��");
		}
		else if (n == 2) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0xB, "��");
		}
		else if (n == 3) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0xD, "��");
		}
		else if (n == 4) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0xE, "��");
		}
		else if (n == 5) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0x9, "��");
		}
		else if (n == 6) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0x8, "��");
		}
		else if (n == 7) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0xB, "��");
		}
		else if (n == 8) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0x9, "��");
		}
		else if (n == 8) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0xA, "��");
		}
		else if (n == 9) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0xD, "��");
		}
		else if (n == 10) {
			m_objHandle.WriteChar(pHead->x, pHead->y, 0x8, "��");
		}
			
	}
	newPoint->next = pHead;
	pHead = newPoint;
	m_objHandle.WriteChar(pHead->x, pHead->y, 0xF, "��");
	
}

//ɾ����β
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


// ��ȡ�û������룬�޸ķ���Ϳ���
int CSnake::GetDir() {
	
	// ��Ϸ�����ܱ�����������ʹ�ù��ĺ�����������������
	if (_kbhit())
	{		
		// ����һ��������������һ�������κΰ��������� true
		// _getch ���޻������룬����ʹ�ô����Եĺ���
		switch (_getch())
		{
		case 'w': Dir = UP; break;
		case 's': Dir = DOWN; break;
		case 'a': Dir = LEFT; break;
		case 'd': Dir = RIGHT; break;
		case 'q':              //��ͣ			
			while (true) {
				if (_getch() == ' ')				
					break;													
			}break;				
		case 'e': 
			return 0;
		//	SaveSnake(); 
		//	//m_objFile.SaveSnake(Food, Map);
		//	m_objHandle.WriteChar(MAP_X / 2, MAP_Y / 3, 0xA, "��Ϸ�浵");
		//	system("pause");			
		//	system("cls");
		//	break;

		//default: break;
		}
	}
}
//���ƶ�
int CSnake::SnakeMove(char nMap[MAP_X][MAP_Y], CFood& Food) {
	int x = pHead->x;//x,yΪ��ͷ������
	int y = pHead->y;
	
	// �����ߵķ����ƶ��ߵ�λ��
	switch (Dir)
	{
	case UP: x--; break;
	case DOWN: x++; break;
	case LEFT: y--; break;
	case RIGHT: y++; break;

	}
	//�ж���ͷ������ʲô
	if (nMap[x][y] == SPACE) {	
		AddSnake(x, y, nMap);
		DeleteSnake(nMap);
	}
	else if (nMap[x][y] == FOOD) {//�߳Բ�ͬ��ʳ��Ӳ�ͬ�ķ���
		if (Food.flag == ����) {
			Score += 10;
		}
		else if (Food.flag == ����) {			
			Score += 15;
		}
		else if (Food.flag == ����) {			
			Score += 20;
		}
		else if (Food.flag == ����) {			
			Score += -10;
		}
		else if (Food.flag == Բ��) {			
			Score += 0;
		}

		AddSnake(x, y, nMap);
		Food.SetFoodExist(0);
	}
	else if (nMap[x][y] == BARRIER || nMap[x][y] == SNAKE) {		
		PlaySoundA("Sound\\��ը.wav", NULL, SND_ASYNC | SND_NODEFAULT);//ײ����
		m_objHandle.WriteChar(MAP_X / 2, MAP_Y / 3, 0xA, "GAME OVER!");
		system("pause");
		system("cls");
		return 0; 
	}
	return true;
}

//��ȡ�߳�
int CSnake::CountSnake() {
	int size = 0;
	Point *tPoint = pHead;
	while (tPoint != nullptr) {
		size++;
		tPoint = tPoint->next;
	}
	return size;
}

// ��ȡˢ��ʱ��
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
