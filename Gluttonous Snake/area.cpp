//#include<cstdio>
//#include"area.h"
//#include"windows.h"
//int CEditorMap::Landform( CMap& Map) {
//	// ��ȡ����̨���뻺�����ľ��
//	HANDLE InputHandle = GetStdHandle(STD_INPUT_HANDLE);
//
//	// ��������¼��Ľ���: ENABLE_MOUSE_INPUT
//	SetConsoleMode(InputHandle, ENABLE_MOUSE_INPUT);
//
//	DWORD Number = 0;
//	// ���ڱ����ȡ�����¼�
//	INPUT_RECORD InputRecord = { 0 };
//
//	// ��дһ��ѭ�������ϵĻ�ȡ��ǰ�����¼�
//	//	- 1: ��Ҫ��ȡ��һ������̨�������¼�
//	//	- 2: һ���ṹ�壬�����˻�ȡ���������¼�
//	//	- 3: ��������ʾ�ṩ�Ľṹ���м���(1)
//	//	- 4: ��ǰ��ȡ���˼����¼�
//	while (ReadConsoleInput(InputHandle, &InputRecord, 1, &Number))
//	{
//		// ���ܵ��¼���ֹ���������,������Ҫ�����ж�
//		if (InputRecord.EventType == MOUSE_EVENT)
//		{
//			// ��ȡ����������
//			COORD MouseCoord = InputRecord.Event.MouseEvent.dwMousePosition;
//
//			// Ϊ���е�����¼������������Ĵ���
//			CHAR Buffer[0x100] = { 0 };
//
//			// ͨ�����������Ļ���Ӧ��ֱ�ӷ�ӳ�����ͼ��ص������У�
//			// ��������Ϸ�а��ݵĵ�ͼ�����Ƶ�ͼ�ο������ϰ���������
//
//			// ����¼��зǳ��࣬���ǿ��Ե�����Ӧĳһ���¼�
//			if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
//			{
//				// ������������ˣ���ִ������
//				//Map.m_Map[MouseCoord.X / 2][MouseCoord.Y] = BARRIER;
//				//Handle.WriteChar(MouseCoord.Y, MouseCoord.X / 2, 0xE, "��");
//				
//				Map.m_Map[MouseCoord.X / 2][MouseCoord.Y] = BARRIER;
//				int n = MouseCoord.Y % 16;
//				
//				m_objHandle.WriteChar(MouseCoord.X / 2, MouseCoord.Y, 0x9 | n, "��");
//
//			}
//			else if (InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
//			{
//				Map.StartGame();//��ʼ��Ϸ
//				return 0;
//				
//			}
//
//		}
//	}
//}
//
////�����ϰ�����Ϣ
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
