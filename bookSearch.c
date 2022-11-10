#include "bookSearch.h"

void searchTitle(char title[36])
{
	Node* node = bookList->head->next; //head�� next���� �˻�
	Book* book = node->book;
	while (node != bookList->tail)
	{
		if (strcmp(book->title, title) == 0)
		{
			addBook(searchList, newBook(book->title, book->author, book->genre));
		}
		node = node->next;
		book = node->book;
	}
}

void searchAuthor(char author[36])
{
	Node* node = bookList->head->next; //head�� next���� �˻�
	Book* book = node->book;
	while (node != bookList->tail)
	{
		if (strcmp(book->author, author) == 0)
		{
			addBook(searchList, newBook(book->title, book->author, book->genre));
		}
		node = node->next;
		book = node->book;
	}
}

void searchGenre(char genre[36])
{
	Node* node = bookList->head->next; //head�� next���� �˻�
	Book* book = node->book;
	while (node != bookList->tail)
	{
		if (strcmp(book->genre, genre) == 0)
		{
			addBook(searchList, newBook(book->title, book->author, book->genre));
		}
		node = node->next;
		book = node->book;
	}
}


void bsInit()
{
	searchList = newList();
	initList(searchList);
}

void searchTitleMessage()
{
	char title[36];
	Node* node;
	Book* book;
	system("cls");
	printf("=================�˻�===============\n");
	printf("å ����(�ѱ� 18��, ���� 36�� �̳�): ");
	gets_s(title, 36);
	searchTitle(title);
	if (searchList->count != 0)
	{
		node = searchList->head->next; //head�� next���� �˻�
		for (int i = 0; i < searchList->count; i++)
		{
			book = node->book;
			node = node->next;
			printf("====================================\n");
			printf("å ����: %s �۰�: %s �帣: %s\n", book->title, book->author, book->genre);
			printf("====================================\n");;
		}
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

void searchAuthorMessage()
{
	char author[36];
	Node* node;
	Book* book;
	system("cls");
	printf("=================�˻�===============\n");
	printf("�۰�(�ѱ� 18��, ���� 36�� �̳�): ");
	gets_s(author, 36);
	searchAuthor(author);
	if (searchList->count != 0)
	{
		node = searchList->head->next; //head�� next���� �˻�
		for (int i = 0; i < searchList->count; i++)
		{
			book = node->book;
			node = node->next;
			printf("====================================\n");
			printf("å ����: %s �۰�: %s �帣: %s\n", book->title, book->author, book->genre);
			printf("====================================\n");;
		}
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


void searchGenreMessage()
{
	char genre[36];
	Node* node;
	Book* book;
	system("cls");
	printf("=================�˻�===============\n");
	printf("�帣(�ѱ� 18��, ���� 36�� �̳�): ");
	gets_s(genre, 36);
	searchGenre(genre);
	if (searchList->count != 0)
	{
		node = searchList->head->next; //head�� next���� �˻�
		for (int i = 0; i < searchList->count; i++)
		{
			book = node->book;
			node = node->next;
			printf("====================================\n");
			printf("å ����: %s �۰�: %s �帣: %s\n", book->title, book->author, book->genre);
			printf("====================================\n");;
		}
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

void bsStart()
{
	bsInit();
	bsDraw();
	int menuSelect;
	menuSelect = bsKeyDraw();
	switch (menuSelect)
	{
		case eTitleSearch:
		{
			searchTitleMessage();
			break;
		}
		case eAuthorSearch:
		{
			searchAuthorMessage();
			break;
		}
		case eGenreSearch:
		{
			searchGenreMessage();
			break;
		}
		case eSearchUndo:
		{
			break;
		}
	}
	clear(searchList);
	deleteList(searchList);
}

void bsDraw()
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

int bsKeyDraw()
{
	x = 5;
	y = 1;
	while (1) {
		int n = bsKeyControl();
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

int bsKeyControl()
{
	int temp;
	temp = _getch();
	if (temp == 224)
	{
		temp = _getch();
		if (temp == 72) {
			return eUp;
		}
		else if (temp == 80) {
			return eDown;
		}
		else if (temp == 75)//Left
		{
			return eUndo;
		}
	}
	else if (temp == 32) {
		return eSubmit;
	}

}