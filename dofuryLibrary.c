#include <setjmp.h>
#include "utility.h"
#include "screen.h"
#include "data.h"
void mainInit();
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
void mainInit()
{
	/*Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;

	Node* node1 = (Node*)malloc(sizeof(Node));
	node1->next = head->next;
	node1->book.author = "짱구";
	node1->book.genre = "공포";
	node1->book.title = "학교괴담";
	head->next = node1;

	Node* node2 = (Node*)malloc(sizeof(Node));
	node2->next = node1->next;
	node2->book.author = "짱아";
	node2->book.genre = "로맨스";
	node2->book.title = "호호";
	node1->next = node2;

	Node* curr = head->next;
	while (curr != NULL)
	{
		printf("%s\n", curr->book.author);
		curr = curr->next;
	}

	free(head);
	free(node1);
	free(node2);*/

}
void listCheck()
{
	if (bookList == NULL)
	{
		bookList = newList();
		initList(bookList);
	}
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴llll

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
