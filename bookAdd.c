#include "utility.h"
#include "data.h"
#include "bookAdd.h"
void bookInit()
{
	
}
void bookStart()
{
	bookDraw();
	titleAdd();
	authorAdd();
	genreAdd();
	printf("�߰��Ǿ����ϴ�! �ڷΰ���: ENTER");

	getUserInput();
}
void bookDraw()
{
	system("cls");
	printf("----å �߰� ������----");
}
void titleAdd()
{
	gotoxy(0, 1);
	printf("å�̸�(�ѱ� 18��, ���� 36�� �̳�): ");
	scanf_s("%s", &book.title,36);
}
void authorAdd()
{
	printf("�۰�(�ѱ� 18��, ���� 36�� �̳�): ");
	scanf_s("%s", &book.author,36);
}
void genreAdd()
{
	printf("�帣(�ѱ� 18��, ���� 36�� �̳�): ");
	scanf_s("%s", &book.genre,36);
}
void getUserInput()
{
	int currentInput = 0;
	while (currentInput != KEY_ENTER)
	{
		currentInput = _getch();
	}
}