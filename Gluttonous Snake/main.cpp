
#include <windows.h>
#include <iostream>
#include <conio.h>
#include<ctime>
#include<cstdlib>
#include"handle.h"
#include"map.h"
#include"start.h"

int main()
{
	//设置控制台大小
	system("mode con cols=150 lines=70");

	// 添加随机数种子
	srand((unsigned int)time(NULL));

	//模拟按键SHIFT来修改输入法为英文状态
	keybd_event(VK_SHIFT, 0, 0, 0);
	Sleep(100);
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);

	CMap objMap;
	CStart objStart;
	objStart.m_objHandle.HindCursor(false);//隐藏光标
	objStart.Opetion(objMap);//开始游戏
	system("pause");
	return 0;
}