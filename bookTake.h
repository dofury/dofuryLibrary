#pragma once
#include "data.h"
#include "utility.h"
#include "bookList.h"
typedef enum _eTakeMenu {
	eTake_Borrow = 3,
	eTake_Return = 5,
	eTake_Undo = 7
}eTakeMenu;
void btStart();
void btDraw();
void btShow(Book* book);
void btBorrow(Node* present);
void btReturn(Node* present);
Node* btKeyDraw();
void btShows();
void btsDraw();