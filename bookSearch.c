#include "bookSearch.h"

Book* searchTitle(List* list,char title[36])
{
	Node* node = list->head->next; //head�� next���� �˻�
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
	printf("=================�˻�===============\n");
	printf("å�̸�(�ѱ� 18��, ���� 36�� �̳�): ");
	gets_s(title, 36);
	book = searchTitle(bookList, title);
	if (book != NULL)
	{
		printf("====================================\n");
		printf("å �̸�: %s �۰�: %s �帣: %s\n", book->title, book->author, book->genre);
		printf("====================================\n");
		printf("�˻� �Ϸ�.\n\n");
		printf("           Ȯ��:ENTER");
		getUserInput();
	}
	else
	{
		printf("å�� �����ϴ�.");
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
		printf("   >>  1.å�� �������� �˻�\n");
		printf("====================================\n");
		printf("       2.å�� �۰������� �˻�\n");
		printf("====================================\n");
		printf("       3.å�� �帣�� �˻�\n");
		printf("====================================\n");
		printf("       4.�ڷΰ���\n");
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