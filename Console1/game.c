#include "game.h"
//#include "util.h" //game.h에 util.h를 넣어주었기에 이 소스에서 util.h를 포함시켜줄 필요 X .

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
				*x = w; //x로 쓰면 주소 *x로 쓰면 x주소에 있는 값 //시작 주소 값
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
	int key = 0; //열쇠 갯수 저장

	int playing = 1;
	
	if (mapCode == 0) {
		memcpy(tempMap, mapEasy, sizeof(tempMap)); //memory copy
	}
	else if (mapCode == 2) {
		memcpy(tempMap, mapHard, sizeof(tempMap));
	}

	drawMap(&x, &y); //drawMap을 해줬는데 바로 메뉴화면으로 돌아가는 이유는 
					 //main 함수에서 Title()함수를 무한루프로 돌려놨기 때문에 Title 함수에서 키입력을 받으러 그 상태로 돌아가는 것이다.

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
	printf("게임을 클리어 하셨습니다."); 
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
		printf("@"); //플레이어 출력

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
	printf("위 치 : %02d, %02d", *x, *y);

	setColor(yellow, black);
	gotoxy(40, 15);
	printf("열쇠 갯수 : %d", *key);
}


void Title() //탭과 스페이스바 구분 확실히.
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

	gotoxy(x - 2, y); //마우스 커서위치를 적은 좌표까지 옮김
	printf("> 게 임 시 작  "); //위 gotoxy함수로 지정한 좌표까지 커서위치가 옮겨졌으니, 거기에 출력
	gotoxy(x, y + 1);
	printf("게 임 정 보 ");
	gotoxy(x, y + 2);
	printf("   종  료\n");

	while (1)
	{
		int num = KeyControl(); // * 0이 계속 들어간다 지속적인 값으로 0이 계속들어가서 w키가 계속 작동했던 것. 해결점 찾았다
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

int KeyControl() //입력을 받으면 int형으로 함수에 값을 반환해줌
{
	int key;
	//char temp = _getch(); //getch는 비표준 입력함수 conio 헤더파일이 필요.

	//if (temp == 'w' || temp == 'W' ) return UP;
	//else if (temp == 'a' || temp == 'A') return LEFT;
	//else if (temp == 's' || temp == 'S' ) return DOWN;
	//else if (temp == 'd' || temp == 'D' ) return RIGHT;
	//else if (temp == ' ') return SUBMIT;
	//else if (temp == 13) return SUBMIT;


	if (kbhit()) { //키입력이 있는 경우  
		key = getch(); //키값을 받음
			if (key == 'w' || key == 'W' ) return UP;
			else if (key== 'a' || key == 'A') return LEFT;
			else if (key == 's' || key == 'S' ) return DOWN;
			else if (key == 'd' || key == 'D' ) return RIGHT;
			if (key == ' ') return SUBMIT;
			else if (key == 13) return SUBMIT;

		if (key == 224) { //방향키인경우 
			do { key = getch(); } while (key == 224);//방향키지시값을 버림 
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
	printf("				     [ 조 작 법 ]\n\n");
	printf("				이 동 : W, A, S D\n");
	printf("				선 택 : 스 페 이 스 바 \n\n\n\n\n\n\n");
	printf("			           개 발 자 : Pang\n\n");
	printf("			스 페 이 스 바 를  누 르 면  메 인 화 면 으 로	\n				    이 동 합 니 다 .");

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
	printf("[ 난 이 도 ]");
	gotoxy(x - 2, y);
	printf(">   연 습  ");
	gotoxy(x, y + 2);
	printf("어 려 움 ");
	gotoxy(x, y + 4);
	printf("  뒤 로\n");

	while (1) //루프
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

