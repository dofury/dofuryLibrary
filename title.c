#include "utility.h"
#define UP 1
#define DOWN 2
#define SUBMIT 3

void titleInit()
{
    system("mode con cols=120 lines=30 | title BOOK");

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//콘솔 핸들가져오기
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0; //false 또는 0: 숨기기
    ConsoleCursor.dwSize = 1;//수정
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}
void titleDraw()
{
    printf("               BOOK\n");
    printf("====================================\n");
    printf("\n");
    printf("====================================\n");
    printf("\n");
    printf("====================================\n");
    printf("\n");
    printf("====================================\n");
    printf("\n");
    printf("====================================\n");
    printf("\n");
    printf("====================================\n");
    printf("\n");
    printf("====================================\n");
}

int keyDraw()
{
	x = 5;
	y = 2;
	gotoxy(x - 2, y);
	printf(">>  1. 전체 도서 목록보기\n");
	gotoxy(x, y + 2);
	printf("  2. 도서 검색\n");
	gotoxy(x, y + 4);
	printf("  3. 도서 추가\n");
	gotoxy(x, y + 6);
	printf("  4. 도서 대여@반납\n");
	gotoxy(x, y + 8);
	printf("  5. 초기화\n");
	gotoxy(x, y + 10);
	printf("  6. 종료 & 저장\n");
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 2) {
				gotoxy(x - 2, y);
				printf("  ");
				gotoxy(x - 2,y-=2);
				printf(">>");
			}
			break;
		}
		case DOWN: {
			if (y < 12) {
				gotoxy(x - 2, y);
				printf("  ");
				gotoxy(x - 2, y += 2);
				printf(">>");
			}
			break;
		case SUBMIT: {
			gotoxy(20,10);
			printf("%d", y);
			return y;
		}


		}
		}
	}
}
int keyControl()
{
	int temp;
	temp = _getch();
	if (temp == 224)
	{
		temp = _getch();
		if (temp == 72) {
			return UP;
		}
		else if (temp == 80) {
			return DOWN;
		}
	}
	else if (temp == 32) {
		return SUBMIT;
	}
}