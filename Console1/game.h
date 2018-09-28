#pragma once
#include "main.h"
#include "util.h"

#define TITLE ("\n\n\n\n"\
				"				   #####       ### \n"\
				"				   #          #    \n"\
				"				   #####      #### \n"\
				"				   #              # \n"\
				"				   #####      #### \n")

#ifndef KEY_CODE
#define KEY_CODE

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define SUBMIT 5

#endif


void Title();
int Menu();
int KeyControl();
void infoDraw();
int mapList();
void drawmap();
void gLoop(int);

