#include "utility.h"
#define UP 1
#define DOWN 2
#define SUBMIT 3

void titleInit()
{
    system("mode con cols=120 lines=30 | title BOOK");

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//�ܼ� �ڵ鰡������
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0; //false �Ǵ� 0: �����
    ConsoleCursor.dwSize = 1;//����
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
	printf(">>  1. ��ü ���� ��Ϻ���\n");
	gotoxy(x, y + 2);
	printf("  2. ���� �˻�\n");
	gotoxy(x, y + 4);
	printf("  3. ���� �߰�\n");
	gotoxy(x, y + 6);
	printf("  4. ���� �뿩@�ݳ�\n");
	gotoxy(x, y + 8);
	printf("  5. �ʱ�ȭ\n");
	gotoxy(x, y + 10);
	printf("  6. ���� & ����\n");
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