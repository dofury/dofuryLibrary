#include "bookTake.h"

void btStart()
{
	Node* select;
	int menuSelect;
	select = btKeyDraw();//booklist 기능 그대로 활용
	if (select != NULL && bookList->count != 0)
	{
		menuSelect = btsKeyDraw(select);
		switch (menuSelect)
		{
		case eTake_Borrow:
		{
			btBorrow(select);
			break;
		}
		case eTake_Return:
		{
			btReturn(select);
			break;
		}
		case eTake_Undo:
		{
			break;
		}
		}
	}
}

Node* btKeyDraw()
{
	Node* present = bookList->head->next;
	btDraw();
	btShows();
	x = 5;
	y = 1;
	if (bookList->count >= 1)
	{
		gotoxy(3, 1);
		printf(">>");
	}
	else
	{
		printf("\n               등록된 책이 없습니다!!!\n\n");
		printf("                   뒤로가기:SPACE");
	}
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
				present = present->prev;
			}
			break;
		}
		case eDown: {
			if (y < bookList->count * 2 - 1) {
				gotoxy(x - 2, y);
				printf("  ");
				gotoxy(x - 2, y += 2);
				printf(">>");
				present = present->next;
			}
			break;
		case eSubmit: {
			return present;
		}
		case eUndo: {
			return NULL;
		}


		}
		}
	}
}

int btsKeyDraw(Node* present)
{
	system("cls");
	printf("====================================================\n");
	btShow(present->book);
	btsDraw();
	x = 5;
	y = 3;
	while (1) {
		int n = blKeyControl();
		switch (n) {
		case eUp: {
			if (y > 4)
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

void btBorrow(Node* present)
{
	Book* book = present->book;
	system("cls");
	printf("====================================================\n");
	btShow(book);
	if (book->take == 0)
	{
		book->take = 1;
		printf("            대출 완료. 뒤로가기: ENTER");
		getUserInput();
	}
	else
	{
		printf("       이미 대출된 책입니다. 뒤로가기: ENTER");
		getUserInput();
	}
}

void btReturn(Node* present)
{
	Book* book = present->book;
	system("cls");
	printf("====================================================\n");
	btShow(book);
	if (book->take == 1)
	{
		book->take = 0;
		printf("            반납 완료. 뒤로가기: ENTER");
		getUserInput();
	}
	else
	{
		printf("       이미 반납된 책입니다. 뒤로가기: ENTER");
		getUserInput();
	}
}

void btShow(Book* book)
{
	if (book != NULL)
	{
		printf("        책 이름: %s 작가: %s 장르: %s ",
			book->title, book->author, book->genre);
		if (book->take == 0)
		{
			printf("[대출가능]\n");
		}
		else
		{
			printf("[대출불가]\n");
		}
		printf("====================================================\n");
	}
}
void btShows()
{
	Node* node = bookList->head->next;
	for (int i = 0; i < bookList->count; i++)
	{
		btShow(node->book);
		node = node->next;
	}
}
void btDraw()
{
	system("cls");
	printf("======================= 책목록 =====================\n");
}
void btsDraw()
{
	printf("   >>  1.대출\n");
	printf("====================================================\n");
	printf("       2.반납\n");
	printf("====================================================\n");
	printf("       3.메뉴\n");
	printf("====================================================\n");
}
