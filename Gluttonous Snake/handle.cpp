//#include <windows.h>
#include<iostream>
#include"handle.h"
//添加 windows.h 头文件使用其中的函数
#include <windows.h>
using namespace std;

void CHandle::WriteChar(short x, short y, int color, const char* s)
{
	// 句柄: 在windwos中句柄用于标识某一种东西，这个例子中，句柄
	//	被用于标识当前控制台的输出缓冲区，用于显示具体的内同
	HANDLE OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	// 通过函数的调用实现移动光标到指定位置
	//  1: 想要修改的是哪一个输出缓冲区的光标位置
	//	2: 想要将光标移动到控制台的哪一个位置
	SetConsoleCursorPosition(OutputHandle, { y * 2, x });

	// 为接下来需要打印的文字提供颜色，可以使用 RGB 搭配出一些简单
	// 的颜色，不要使用较暗的颜色，应该选用亮色(黄色、绿色、白的)
	SetConsoleTextAttribute(OutputHandle, color);

	// 打印指定的图形
	cout << s;
}
void CHandle::HindCursor(bool Hide)
{
	// 句柄: 在windwos中句柄用于标识某一种东西，这个例子中，句柄
	//	被用于标识当前控制台的输出缓冲区，用于显示具体的内同
	HANDLE OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	// 定义结构体，用于保存光标的信息，参数二表示是否显示
	CONSOLE_CURSOR_INFO Cursor = { 1, Hide };
	// 调用函数设置光标的属性
	SetConsoleCursorInfo(OutputHandle, &Cursor);
}