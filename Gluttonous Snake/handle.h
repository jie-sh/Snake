#pragma once

#ifndef HANDLEH
#define HANDLEH

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define PAUSE 4
#define RESTART 5

#define MAP_X 50
#define MAP_Y 50

#define SPACE 0//'  '
#define FOOD 1//'��'
#define BARRIER 2//'��'
#define SNAKE 3//'��'

#define ���� 1
#define ���� 2
#define ���� 3
#define ���� 4
#define Բ�� 5


class CHandle {
public:
	// ��ָ��������ʹ��ָ������ɫ��ӡָ�����ַ�
	void WriteChar(short x, short y, int color, const char* s);
	// ���ع��
	void HindCursor(bool Hide = true);
private:
	short x;
	short y;
	int color;
	const char* s;
};

#endif

