#pragma once
#include "screen.h"
#include "data.h"
#include "utility.h"
#include <string.h>

typedef enum _eSearchMenu
{
	eTitleSearch = 1,
	eAuthorSearch = 3,
	eGenreSearch = 5,
	eSearchUndo = 7
}eSearchMenu;
List* searchList;
void bSearchDraw();