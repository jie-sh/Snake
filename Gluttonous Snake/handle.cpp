//#include <windows.h>
#include<iostream>
#include"handle.h"
//��� windows.h ͷ�ļ�ʹ�����еĺ���
#include <windows.h>
using namespace std;

void CHandle::WriteChar(short x, short y, int color, const char* s)
{
	// ���: ��windwos�о�����ڱ�ʶĳһ�ֶ�������������У����
	//	�����ڱ�ʶ��ǰ����̨�������������������ʾ�������ͬ
	HANDLE OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	// ͨ�������ĵ���ʵ���ƶ���굽ָ��λ��
	//  1: ��Ҫ�޸ĵ�����һ������������Ĺ��λ��
	//	2: ��Ҫ������ƶ�������̨����һ��λ��
	SetConsoleCursorPosition(OutputHandle, { y * 2, x });

	// Ϊ��������Ҫ��ӡ�������ṩ��ɫ������ʹ�� RGB �����һЩ��
	// ����ɫ����Ҫʹ�ýϰ�����ɫ��Ӧ��ѡ����ɫ(��ɫ����ɫ���׵�)
	SetConsoleTextAttribute(OutputHandle, color);

	// ��ӡָ����ͼ��
	cout << s;
}
void CHandle::HindCursor(bool Hide)
{
	// ���: ��windwos�о�����ڱ�ʶĳһ�ֶ�������������У����
	//	�����ڱ�ʶ��ǰ����̨�������������������ʾ�������ͬ
	HANDLE OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	// ����ṹ�壬���ڱ��������Ϣ����������ʾ�Ƿ���ʾ
	CONSOLE_CURSOR_INFO Cursor = { 1, Hide };
	// ���ú������ù�������
	SetConsoleCursorInfo(OutputHandle, &Cursor);
}