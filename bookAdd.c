#include "utility.h"
#include "data.h"
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
	printf("추가되었습니다! 뒤로가기: ENTER");
	getUserInput();
}

void bAddDraw()
{
	system("cls");
	printf("----책 추가 페이지----");
}
void titleAdd()
{
	gotoxy(0, 1);
	printf("책이름(한글 18자, 영어 36자 이내): ");
	gets_s(book.title,36);
}
void authorAdd()
{
	printf("작가(한글 18자, 영어 36자 이내): ");
	gets_s(book.author,36);
}
void genreAdd()
{
	printf("장르(한글 18자, 영어 36자 이내): ");
	gets_s(book.genre,36);
}