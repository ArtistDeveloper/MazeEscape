#include "util.h"

void init()
{
	system("mode con  cols=90 lines=20 | title game");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);  // Get : ���𰡸� ������ ��
	CONSOLE_CURSOR_INFO ConsoleCursor;
	GetConsoleCursorInfo(consoleHandle, &ConsoleCursor); //���� ��ɵ�
	ConsoleCursor.bVisible = FALSE; //bvisible : ȭ�� ǥ�ÿ��� FALSE : 0, TRUE : 1
	ConsoleCursor.dwSize = 1; //dwsize : ���� ���� ����(1~100) 
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor); //set : ����(�� ����)
				 //�ܼ� ��ũ�� ���� �ڵ�, CONSOLE_CURSOR_INFO����ü �Ѱ��ֱ�
	// _in_ �޴� �� ex) �Ű������� �޴� �� _out_������ ��
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
