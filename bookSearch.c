#include "bookSearch.h"

Book* searchTitle(List* list,char title[36])
{
	Node* node = list->head->next; //head의 next부터 검색
	Book* book = node->book;
	while (node != list->tail)
	{
		if (strcmp(book->title, title) == 0)
		{
			return book;
		}
		node = node->next;
	}
	return NULL;
}

void searchTitleMessage()
{
	Book* book;
	char title[36];
	system("cls");
	printf("=================검색===============\n");
	printf("책이름(한글 18자, 영어 36자 이내): ");
	gets_s(title, 36);
	book = searchTitle(bookList, title);
	if (book != NULL)
	{
		printf("====================================\n");
		printf("책 이름: %s 작가: %s 장르: %s\n", book->title, book->author, book->genre);
		printf("====================================\n");
		printf("검색 완료.\n\n");
		printf("           확인:ENTER");
		getUserInput();
	}
	else
	{
		printf("책이 없습니다.");
		getUserInput();
	}
}
void bSearchStart()
{
	bSearchDraw();
	int menuSelect;
	menuSelect = bSearchsKeyDraw();
	switch (menuSelect)
	{
		case eTitleSearch:
		{
			searchTitleMessage();
			break;
		}
		case eAuthorSearch:
		{
			break;
		}
		case eGenreSearch:
		{
			break;
		}
		case eSearchUndo:
		{
			break;
		}
	}
}

void bSearchDraw()
{
	    system("cls");
		printf("====================================\n");
		printf("   >>  1.책의 제목으로 검색\n");
		printf("====================================\n");
		printf("       2.책의 작가명으로 검색\n");
		printf("====================================\n");
		printf("       3.책의 장르로 검색\n");
		printf("====================================\n");
		printf("       4.뒤로가기\n");
		printf("====================================\n");
}

int bSearchsKeyDraw()
{
	x = 5;
	y = 1;
	while (1) {
		int n = blKeyControl();
		switch (n) {
		case eUp: {
			if (y > 2)
			{
				gotoxy(x - 2, y);
				printf("  ");
				gotoxy(x - 2, y -= 2);
				printf(">>");
			}
			break;
		}
		case eDown: {
			if (y < 7) {
				gotoxy(x - 2, y);
				printf("  ");
				gotoxy(x - 2, y += 2);
				printf(">>");
			}
			break;
		case eSubmit: {
			return y;
		}


		}
		}
	}
}