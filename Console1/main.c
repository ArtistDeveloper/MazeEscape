#include "main.h"
#include "game.h"

int main()
{
	init();

	while (1)
	{
		Title();
		int menuCode = Menu(); //������ �޴��� ��ȯ (y - 12 ��)

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
				// �����
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
