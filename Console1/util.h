#pragma once
#include "main.h"

#ifndef __COLOR_LIST_
#define __COLOR_LIST_

enum
{
	black, //0
	blue, //1
	green, //2
	cyan, //3
	red, //4
	purple, //5
	brown, //6
	lightgray, //7
	darkgray, //8
 	lightblue, //9
	lightgreen, //10
	lightcyan, //11
	lightred, //12
	lightpurple, //13
	yellow, //14
	white //15
};

#endif

void init();
void gotoxy(int, int);
void setColor(int, int);