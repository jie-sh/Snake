
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
	//���ÿ���̨��С
	system("mode con cols=150 lines=70");

	// ������������
	srand((unsigned int)time(NULL));

	//ģ�ⰴ��SHIFT���޸����뷨ΪӢ��״̬
	keybd_event(VK_SHIFT, 0, 0, 0);
	Sleep(100);
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);

	CMap objMap;
	CStart objStart;
	objStart.m_objHandle.HindCursor(false);//���ع��
	objStart.Opetion(objMap);//��ʼ��Ϸ
	system("pause");
	return 0;
}