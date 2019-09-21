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
	void Menu();//菜单
	void Opetion(CMap& Map);//菜单选项
public:
	CHandle m_objHandle;
	int m_nChoice;
};

#endif