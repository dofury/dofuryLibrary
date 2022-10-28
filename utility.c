#include "utility.h"

void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//콘솔 핸들가져오기
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}