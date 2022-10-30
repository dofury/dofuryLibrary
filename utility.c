#include "utility.h"

void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//�ܼ� �ڵ鰡������
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void getUserInput()
{
	int currentInput = 0;
	while (currentInput != KEY_ENTER)
	{
		currentInput = _getch();
	}
}