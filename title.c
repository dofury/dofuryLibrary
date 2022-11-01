#include "utility.h"
#include "title.h"

void ttInit()
{
    system("mode con cols=120 lines=30 | title BOOK");

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//�ܼ� �ڵ鰡������
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0; //false �Ǵ� 0: �����
    ConsoleCursor.dwSize = 1;//����
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}
void ttDraw()
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

int ttKeyDraw()
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
		int n = ttKeyControl();
		switch (n) {
		case eUp: {
			if (y > 2) {
				gotoxy(x - 2, y);
				printf("  ");
				gotoxy(x - 2,y-=2);
				printf(">>");
			}
			break;
		}
		case eDown: {
			if (y < 12) {
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
int ttKeyControl()
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
	}
	else if (temp == 32) {
		return eSubmit;
	}
}