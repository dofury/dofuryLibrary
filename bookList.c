#include "bookList.h"
#include "utility.h"
#include "data.h"

void blStart()
{
	Node* select;
	select = blKeyDraw();
	if (select != NULL)
	{
		Book* book = select->book;
		system("cls");
		printf("%s", book->title);
	}
}
void blInit()
{

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
		printf("====================================\n");
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
	printf("=============== 책목록 =============\n");
}