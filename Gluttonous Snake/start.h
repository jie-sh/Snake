#pragma once

#ifndef STARTH
#define STARTH


#define STARGAME 1
#define EXIT 2
#define AREA 3
#define CONTINUE 4
#include"handle.h"

class CMap;

class CStart {
public:
	CStart();
	void Menu();//�˵�
	void Opetion(CMap& Map);//�˵�ѡ��
public:
	CHandle m_objHandle;
	int m_nChoice;
};

#endif