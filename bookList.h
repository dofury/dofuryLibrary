#pragma once
#include "data.h"
void blInit();
void blDraw();
void blShow(Book* book);
void blShows();
void blStart();
Node* blKeyDraw();
Book inputBook();
int blsKeyDraw(Node* present);
void blsDraw();
int blKeyControl();
typedef enum _eListMenu {
	eListMenu_Edit = 3,
	eListMenu_Remove = 5,
	eListMenu_Undo = 7
}eListMenu;