#include "bookAdd.h"
void bAddInit()
{
	
}
void bAddStart()
{
	bAddDraw();
	titleAdd();
	authorAdd();
	genreAdd();
	addBook(bookList, newBook(book.title, book.author, book.genre));
	printf("====================================================\n");
	printf("          �߰��Ǿ����ϴ�! �ڷΰ���: ENTER");
	getUserInput();
}

void bAddDraw()
{
	system("cls");
	printf("======================= å�߰� =====================\n");
}
void titleAdd()
{
	gotoxy(0, 1);
	printf("å ����(�ѱ� 18��, ���� 36�� �̳�): ");
	gets_s(book.title,36);
}
void authorAdd()
{
	printf("�۰�(�ѱ� 18��, ���� 36�� �̳�): ");
	gets_s(book.author,36);
}
void genreAdd()
{
	printf("�帣(�ѱ� 18��, ���� 36�� �̳�): ");
	gets_s(book.genre,36);
}