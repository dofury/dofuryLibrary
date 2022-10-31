#pragma once
#include <stdio.h>
#include<Windows.h>

#define KEY_ENTER 13

typedef enum _eSelect
{
	eUp =1,
	eDown,
	eSubmit,
	eUndo
}eSelct;
void gotoxy(int x, int y);
void getUserInput();
int x, y;