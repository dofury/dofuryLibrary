#include "bookList.h"
#include "utility.h"
#include "data.h"

void bListStart()
{
	bListDraw();
	Node* node = bookList->head->next;
	for (int i = 0; i < bookList->count; i++)
	{
		bListShow(node->book);
		node = node->next;
	}
	getUserInput();
}
void bListInit()
{

}

void bListShow(Book* book)
{
	if (book != NULL)
	{
		printf("å �̸�: %s �۰�: %s �帣: %s\n",
			book->title,book->author,book->genre);
	}
}

void bListDraw()
{
	system("cls");
	printf("-----å ���-----\n");
}