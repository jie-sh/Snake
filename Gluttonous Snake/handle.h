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
#define FOOD 1//'★'
#define BARRIER 2//'※'
#define SNAKE 3//'■'

#define 星形 1
#define 三角 2
#define 菱形 3
#define 方形 4
#define 圆形 5


class CHandle {
public:
	// 在指定的坐标使用指定的颜色打印指定的字符
	void WriteChar(short x, short y, int color, const char* s);
	// 隐藏光标
	void HindCursor(bool Hide = true);
private:
	short x;
	short y;
	int color;
	const char* s;
};

#endif

