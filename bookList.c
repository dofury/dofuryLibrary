#include "bookList.h"
#include "utility.h"
#include "data.h"

void blStart()
{
	Node* select;
	select = blKeyDraw();
	if (select != NULL && bookList->count != 0)
	{
		int menuSelect;
		menuSelect = blsKeyDraw(select);
		switch (menuSelect)
		{
			case eListMenu_Edit:
				{
					Book tempBook = inputBook();
					editSet(select, tempBook);
					break;
				}
			case eListMenu_Remove:
				{
					removeSet(bookList, select);
					system("cls");
					printf("삭제되었습니다! 뒤로가기: ENTER");
					getUserInput();
					break;
				}
			case eListMenu_Undo:
				{
					break;
				}
		}
	}
}
void blInit()
{

}
Book inputBook()
{
	Book book;
	system("cls");
	gotoxy(0, 1);
	printf("책이름(한글 18자, 영어 36자 이내): ");
	gets_s(book.title, 36);
	system("cls");
	gotoxy(0, 1);
	printf("작가(한글 18자, 영어 36자 이내): ");
	gets_s(book.author, 36);
	system("cls");
	gotoxy(0, 1);
	printf("장르(한글 18자, 영어 36자 이내): ");
	gets_s(book.genre, 36);

	return book;
}
int blsKeyDraw(Node* present)
{
	system("cls");
	printf("====================================================\n");
	blShow(present->book);
	blsDraw();
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

void blsDraw()
{
	printf("   >>  1.편집\n");
	printf("====================================================\n");
	printf("       2.삭제\n");
	printf("====================================================\n");
	printf("       3.메뉴\n");
	printf("====================================================\n");
}
Node* blKeyDraw()
{
	Node* present = bookList->head->next;
	blDraw();
	blShows();
	x = 5;
	y = 1;
	if (bookList->count >= 1)
	{
		gotoxy(3, 1);
		printf(">>");
	}
	else
	{
		printf("\n                등록된 책이 없습니다!!!\n\n");
		printf("                    뒤로가기:SPACE");
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
					if (y < bookList->count*2-1) {
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
int blKeyControl()
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

void blShow(Book* book)
{
	if (book != NULL)
	{
		printf("       책 이름: %s 작가: %s 장르: %s\n",
			book->title,book->author,book->genre);
		printf("====================================================\n");
	}
}
void blShows()
{
	Node* node = bookList->head->next;
	for (int i = 0; i < bookList->count; i++)
	{
		blShow(node->book);
		node = node->next;
	}
}

void blDraw()
{
	system("cls");
	printf("======================= 책목록 =====================\n");
}