#include "game.h"
//#include "util.h" //game.h�� util.h�� �־��־��⿡ �� �ҽ����� util.h�� ���Խ����� �ʿ� X .

char tempMap[14][80];

char mapEasy[14][80] = {
{ "11111111111111111111111111111111111111111111111111111111111111111111111111111111" },
{ "10000000000000000000000000000000000000000000000000000000000000000000000000000001" },
{ "10000000000000000000000000000000000000000000000000000000000000000000000000000001" },
{ "10001000000000000000000000000000000000000000000000000000000000000000000000000001" },
{ "10001000000000000000000000000000000000000000000000000000000000000000000000000001" },
{ "10001000000000000000000000000000000000000000000000000000000000000000000000000001" },
{ "10001000001111110000000000000000000000000000000000000000000000000000000000000001" },
{ "10001000000000010000000000000000000000000000000000000000000000000000000000000001" },
{ "10001000000000010000000000000000000000000000000000000000000000000000000000000001" },
{ "100010000000k0010000000000000000000000000000000000000000000011111111111000000001" },
{ "10001000000000010000000000000000000000000000000000000000000010000000001000000001" },
{ "10s0100000000001111111111111111111111111111111111111111111111000q000001000000001" },
{ "100010000000000L0000000000000000000000000000000000000000000000000000001000000001" },
{ "11111111111111111111111111111111111111111111111111111111111111111111111111111111" }
};

char mapHard[14][80] = {
{ "11111111111111111111111111111111111111111111111111111111111111111111111111111111" },
{ "10s00100000000k00000000000000000100000000000001k01000L00000000000000000000000001" },
{ "10000L111111111111111111110111111111111110001010010001011111001000001L1111111111" },
{ "1100100001k000000000100k10000000000000000000101011000101000100101100100000001101" },
{ "10001001111111101111100010000000100000100000100000000101011000101000101111111101" },
{ "101010000000000000001011111111111111L1111111111111111101010010001000101000100101" },
{ "10101111111011111111100000000000000000000000100000001101010010001000101010100101" },
{ "1k001001001000000000100101111111111111011001000001001001010011111000101010100001" },
{ "10101001001111111100100100010000010000001111111011001001010000001000101010100001" },
{ "10101001001000000000L0000001001001010000L000000001001001011100000000101010100101" },
{ "101010010011111111101011111111100001001111111111110010010000L1111111100010000101" },
{ "1110100100100010000010001000001111111110000k00001000100111100100q000111111111101" },
{ "10001000000000000000100000000000000001000000000000000000000001000000L00000000001" },
{ "11111111111111111111111111111111111111111111111111111111111111111111111111111111" }
};


void drawMap(int*x, int* y)
{
	system("cls");
	int h, w = 0;

	for (h = 0; h < 14; h++)
	{
		for (w = 0; w < 80; w++)
		{
			
			char temp = tempMap[h][w];
			if (temp == '0') {
				setColor(black, black);
				printf(" ");
			}
			else if (temp == '1') {
				setColor(white, white);
				printf("#");
			}
		
			else if (temp == 's') {
				*x = w; //x�� ���� �ּ� *x�� ���� x�ּҿ� �ִ� �� //���� �ּ� ��
				*y = h;
				setColor(cyan, black);
				printf("@");
			}
			else if (temp == 'q') {
				setColor(lightgreen, black);
				printf("0");
			}

			else if (temp == 'k') {
				setColor(yellow, black);
				printf("*");
			}

			else if (temp == 'L') {
				setColor(brown, black);
				printf("+");
			}
		}
		printf("\n");
	}
	setColor(white, black);
}


void gLoop(int mapCode) 
{
	int x, y;
	int key = 0; //���� ���� ����

	int playing = 1;
	
	if (mapCode == 0) {
		memcpy(tempMap, mapEasy, sizeof(tempMap)); //memory copy
	}
	else if (mapCode == 2) {
		memcpy(tempMap, mapHard, sizeof(tempMap));
	}

	drawMap(&x, &y); //drawMap�� ����µ� �ٷ� �޴�ȭ������ ���ư��� ������ 
					 //main �Լ����� Title()�Լ��� ���ѷ����� �������� ������ Title �Լ����� Ű�Է��� ������ �� ���·� ���ư��� ���̴�.

	while (playing)
	{
		drawUI(&x, &y, &key);

		switch (KeyControl()){
		case UP:
			move(&x, &y, 0, -1, &key, &playing);
			break;

		case DOWN:
			move(&x, &y, 0, 1, &key, &playing);
			break;

		case RIGHT:
			move(&x, &y, 1, 0, &key, &playing);
			break;

		case LEFT:
			move(&x, &y, -1, 0, &key, &playing);
			break;

		case SUBMIT:
			playing = 0;
				
		}
	}
	
	system("cls");
	gotoxy(30, 10);
	printf("������ Ŭ���� �ϼ̽��ϴ�."); 
	Sleep(1500);
}
//
//
//void clear()
//{
//
//}


void move(int* x, int* y, int _x, int _y, int* key, int* playing) 
{
	char mapObstacle = tempMap[*y + _y][*x + _x];
	setColor(white, black);
	if (mapObstacle == '0') {
		gotoxy(*x, *y);
		printf(" ");

		setColor(cyan, black);
		gotoxy(*x + _x, *y + _y);
		printf("@"); //�÷��̾� ���

		*x = *x + _x;
		*y = *y + _y;
	}

	else if (mapObstacle == 'k') {
		*key += 1;
		tempMap[*y + _y][*x + _x] = 0;
		gotoxy(*x + _x, *y + _y);
		printf(" ");
	}

	else if (mapObstacle == 'L'){
		if (*key > 0) {
			*key -= 1;
			tempMap[*y + _y][*x + _x] = '0';
			setColor(white, black);
			gotoxy(*x + _x, *y + _y);
			printf(" ");
		}
	}

	else if (mapObstacle == 'q') {
		*playing = 0;
	}

}


void drawUI(int* x, int* y, int* key)
{
	setColor(white, black);
	gotoxy(10, 15);
	printf("�� ġ : %02d, %02d", *x, *y);

	setColor(yellow, black);
	gotoxy(40, 15);
	printf("���� ���� : %d", *key);
}


void Title() //�ǰ� �����̽��� ���� Ȯ����.
{
	/*printf("\n\n\n\n");
	printf("				   #####       ### \n");
	printf("				   #          #    \n");
	printf("				   #####      #### \n");
	printf("				   #              # \n");
	printf("				   #####      #### \n");*/
	printf(TITLE);
}


int Menu()
{
	int i = 0;
	int x = 38;
	int y = 12;

	gotoxy(x - 2, y); //���콺 Ŀ����ġ�� ���� ��ǥ���� �ű�
	printf("> �� �� �� ��  "); //�� gotoxy�Լ��� ������ ��ǥ���� Ŀ����ġ�� �Ű�������, �ű⿡ ���
	gotoxy(x, y + 1);
	printf("�� �� �� �� ");
	gotoxy(x, y + 2);
	printf("   ��  ��\n");

	while (1)
	{
		int num = KeyControl(); // * 0�� ��� ���� �������� ������ 0�� ��ӵ��� wŰ�� ��� �۵��ߴ� ��. �ذ��� ã�Ҵ�
		switch (num)
		{
		case UP:
		{
			if (y > 12)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}

		case DOWN:
		{
			if (y < 14)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT: 
		{
			return y - 12;
		}
			break;
		}
	}
}

int KeyControl() //�Է��� ������ int������ �Լ��� ���� ��ȯ����
{
	int key;
	//char temp = _getch(); //getch�� ��ǥ�� �Է��Լ� conio ��������� �ʿ�.

	//if (temp == 'w' || temp == 'W' ) return UP;
	//else if (temp == 'a' || temp == 'A') return LEFT;
	//else if (temp == 's' || temp == 'S' ) return DOWN;
	//else if (temp == 'd' || temp == 'D' ) return RIGHT;
	//else if (temp == ' ') return SUBMIT;
	//else if (temp == 13) return SUBMIT;


	if (kbhit()) { //Ű�Է��� �ִ� ���  
		key = getch(); //Ű���� ����
			if (key == 'w' || key == 'W' ) return UP;
			else if (key== 'a' || key == 'A') return LEFT;
			else if (key == 's' || key == 'S' ) return DOWN;
			else if (key == 'd' || key == 'D' ) return RIGHT;
			if (key == ' ') return SUBMIT;
			else if (key == 13) return SUBMIT;

		if (key == 224) { //����Ű�ΰ�� 
			do { key = getch(); } while (key == 224);//����Ű���ð��� ���� 
			if (key == 72) return UP;
			else if (key == 75) return LEFT;
			else if (key == 80) return DOWN;
			else if (key == 77) return RIGHT;
			}               
		}
	};

void infoDraw()
{
	system("cls");
	printf("\n\n");
	printf("				     [ �� �� �� ]\n\n");
	printf("				�� �� : W, A, S D\n");
	printf("				�� �� : �� �� �� �� �� \n\n\n\n\n\n\n");
	printf("			           �� �� �� : Pang\n\n");
	printf("			�� �� �� �� �� ��  �� �� ��  �� �� ȭ �� �� ��	\n				    �� �� �� �� �� .");

	while (1)
	{
		if (KeyControl() == SUBMIT)
		{
			system("CLS");
			break;
		}
	}
}

int mapList()
{
	int i = 0;
	int x = 39;
	int y = 7;

	gotoxy(x-1, y - 6);
	printf("[ �� �� �� ]");
	gotoxy(x - 2, y);
	printf(">   �� ��  ");
	gotoxy(x, y + 2);
	printf("�� �� �� ");
	gotoxy(x, y + 4);
	printf("  �� ��\n");

	while (1) //����
	{
		int num = KeyControl();
		switch (num)
		{
		case UP: 
		{
			if (y > 7)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, y-2);
				printf(">");
				y -= 2;
			}
			break;
		}

		case DOWN: 
		{
			if (y < 11)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, y+2);
				printf(">");
				y += 2;
			}
			break;
		}

		case SUBMIT: 
		{
			return y - 7;
		}
			 break;
		}
	}
}

