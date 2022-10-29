#pragma once
typedef enum _eMenu {
	eMenu_List = 2,
	eMenu_Search = 4,
	eMenu_Add = 6,
	eMenu_Return = 8,
	eMenu_Reset = 10,
	eMenu_Save = 12
}eMenu;
void titleDraw();
void titleInit();
int keyDraw();
int keyControl();
