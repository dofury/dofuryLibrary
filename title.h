#pragma once
typedef enum _eMenu {
	eMenu_List = 2,
	eMenu_Search = 4,
	eMenu_Add = 6,
	eMenu_Take = 8,
	eMenu_Reset = 10,
	eMenu_Save = 12
}eMenu;
void ttDraw();
void ttInit();
int ttKeyDraw();
int ttKeyControl();
