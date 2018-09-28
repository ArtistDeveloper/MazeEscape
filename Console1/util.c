#include "util.h"

void init()
{
	system("mode con  cols=90 lines=20 | title game");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);  // Get : 무언가를 가져올 때
	CONSOLE_CURSOR_INFO ConsoleCursor;
	GetConsoleCursorInfo(consoleHandle, &ConsoleCursor); //빼도 기능됨
	ConsoleCursor.bVisible = FALSE; //bvisible : 화면 표시여부 FALSE : 0, TRUE : 1
	ConsoleCursor.dwSize = 1; //dwsize : 문자 셀의 비율(1~100) 
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor); //set : 설정(값 전달)
				 //콘솔 스크린 버퍼 핸들, CONSOLE_CURSOR_INFO구조체 넘겨주기
	// _in_ 받는 값 ex) 매개변수로 받는 값 _out_보내는 값
}

void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void setColor(int foreground, int background)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int color = foreground + background * 16; //?
	SetConsoleTextAttribute(consoleHandle, color);
}
