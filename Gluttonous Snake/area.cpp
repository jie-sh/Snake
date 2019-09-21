//#include<cstdio>
//#include"area.h"
//#include"windows.h"
//int CEditorMap::Landform( CMap& Map) {
//	// 获取控制台输入缓冲区的句柄
//	HANDLE InputHandle = GetStdHandle(STD_INPUT_HANDLE);
//
//	// 开启鼠标事件的接受: ENABLE_MOUSE_INPUT
//	SetConsoleMode(InputHandle, ENABLE_MOUSE_INPUT);
//
//	DWORD Number = 0;
//	// 用于保存读取到的事件
//	INPUT_RECORD InputRecord = { 0 };
//
//	// 编写一个循环，不断的获取当前鼠标的事件
//	//	- 1: 想要读取哪一个控制台的输入事件
//	//	- 2: 一个结构体，保存了获取到的输入事件
//	//	- 3: 数量，表示提供的结构体有几个(1)
//	//	- 4: 当前读取到了几个事件
//	while (ReadConsoleInput(InputHandle, &InputRecord, 1, &Number))
//	{
//		// 接受的事件不止有鼠标类型,所以需要进行判断
//		if (InputRecord.EventType == MOUSE_EVENT)
//		{
//			// 获取到鼠标的坐标
//			COORD MouseCoord = InputRecord.Event.MouseEvent.dwMousePosition;
//
//			// 为所有的鼠标事件进行输出坐标的处理
//			CHAR Buffer[0x100] = { 0 };
//
//			// 通常来讲，鼠标的绘制应该直接反映在与绘图相关的数组中，
//			// 数组在游戏中扮演的地图，绘制的图形可以是障碍物或者事物。
//
//			// 鼠标事件有非常多，我们可以单独响应某一个事件
//			if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
//			{
//				// 鼠标的左键按下了，就执行这里
//				//Map.m_Map[MouseCoord.X / 2][MouseCoord.Y] = BARRIER;
//				//Handle.WriteChar(MouseCoord.Y, MouseCoord.X / 2, 0xE, "※");
//				
//				Map.m_Map[MouseCoord.X / 2][MouseCoord.Y] = BARRIER;
//				int n = MouseCoord.Y % 16;
//				
//				m_objHandle.WriteChar(MouseCoord.X / 2, MouseCoord.Y, 0x9 | n, "※");
//
//			}
//			else if (InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
//			{
//				Map.StartGame();//开始游戏
//				return 0;
//				
//			}
//
//		}
//	}
//}
//
////保存障碍物信息
//void CEditorMap::SaveArea(CMap& Map) {
//
//	FILE *pFile = nullptr;
//	int nError = fopen_s(&pFile, "E:\\snake.txt", "wb+");
//	if (nError != 0)
//		return;
//
//	for (int i = 0; i < MAP_X; i++) {
//		for (int j = 0; j < MAP_Y; j++) {
//			fwrite(&Map.m_Map[i][j], sizeof(Map.m_Map), 1, pFile);
//		}
//	}
//}
