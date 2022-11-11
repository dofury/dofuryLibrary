#include <setjmp.h>
#include "utility.h"
#include "screen.h"
#include "data.h"
void listCheck();
int main()
{
    int select;
	fileLoad();


    do
    {
		listCheck();//리스트제거시 재생성
        ttInit();
        ttDraw();
        select = ttKeyDraw();
		switch (select) {
		case eMenu_List:
		{
			blStart();

		}break;
		case eMenu_Search:
		{
			bsStart();
		}break;
		case eMenu_Add:
		{
			bAddStart();

		}break;
		case eMenu_Take:
		{
			btStart();
		}break;
		case eMenu_Reset:
		{
				clear(bookList);//리스트 초기화
				system("cls");
				printf("초기화 완료 뒤로가기:ENTER");
				getUserInput();
		}break;
		case eMenu_Save:
		{	
				fileSave();
				clear(bookList);
				deleteList(bookList);//리스트제거
				return 0;
		}
		}
    }
    while(1);
	
	//수정했습니다

}
void listCheck()
{
	if (bookList == NULL)
	{
		bookList = newList();
		initList(bookList);
	}
}

