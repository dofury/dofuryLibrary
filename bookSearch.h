#pragma once
#include "screen.h"
#include "data.h"
#include "utility.h"
#include <string.h>

Book* searchTitle(List* list, char title[36]);
void bSearchStart();
int bSearchsKeyDraw();
void bSearchDraw();

typedef enum _eSearchMenu
{
	eTitleSearch = 1,
	eAuthorSearch = 3,
	eGenreSearch = 5,
	eSearchUndo = 7
}eSearchMenu;