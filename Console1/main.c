#include "main.h"
#include "game.h"

int main()
{
	init();

	while (1)
	{
		Title();
		int menuCode = Menu(); //선택한 메뉴값 반환 (y - 12 값)

		if (menuCode == 0)
		{	
			system("cls");	
			int n = mapList();

			if (n == 0)
			{
				drawmap();
			}

			else if (n == 1)
			{
				// 어려움
			}
		}

		else if (menuCode == 1)
		{
			infoDraw();
		}

		else if (menuCode == 2)
		{
			return 0;
		}
		system("cls");
		setColor(white, black);
	}

	return 0;
}
