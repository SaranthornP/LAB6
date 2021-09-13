#define _CRT_SECURE_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
void gotoxy(int, int);
void draw_ship(int, int);
void erase_ship(int, int);
void setcursor(bool);
void setcolor(int, int);
void bullet(int x, int y);
void erase_bullet(int x, int y);
int main() {
	setcursor(0);
	char ch = ' ';
	char chc = ' ';
	int x = 38, y = 20;
	int bulletstatus = 0;
	int bulletstatus1 = 0;
	int bulletstatus2 = 0;
	int bulletstatus3 = 0;
	int bulletstatus4 = 0;
	int bx1, bx2, bx3, bx4, bx5, by1, by2, by3, by4, by5;
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == ' '&&bulletstatus==0) {
				bulletstatus = 1;
				bx1 = x + 2;
				by1 = y;
				bullet(bx1, --by1);
			}
			else if (ch == ' ' && bulletstatus1 == 0) {
				bulletstatus1 = 1;
				bx2 = x + 2;
				by2 = y;
				bullet(bx2, --by2);
			}
			else if (ch == ' ' && bulletstatus2 == 0) {
				bulletstatus2 = 1;
				bx3 = x + 2;
				by3 = y;
				bullet(bx3, --by3);
			}
			else if (ch == ' ' && bulletstatus3 == 0) {
				bulletstatus3 = 1;
				bx4 = x + 2;
				by4 = y;
				bullet(bx4, --by4);
			}
			else if (ch == ' ' && bulletstatus4 == 0) {
				bulletstatus4 = 1;
				bx5 = x + 2;
				by5 = y;
				bullet(bx5, --by5);
			}
			if (ch == ' ') {
				ch=chc;
			}
		}
		if (ch == 'a' && x > 0) {
			chc = 'a';
			erase_ship(x, y);
			draw_ship(--x, y);
		}
		if (ch == 'd' && x < 75)
		{
			chc = 'd';
			erase_ship(x, y);
			draw_ship(++x, y);
		}
		if (ch == 'w') {
			erase_ship(x, y);
			draw_ship(x, --y);
		}
		if (ch == 's') {
			chc = 's';
			erase_ship(x, y);
			draw_ship(x, y);
		}
		if (bulletstatus == 1) {
			erase_bullet(bx1, by1);
			if (by1 == 0) bulletstatus = 0;
			if (by1 >= 1) {
				bullet(bx1, --by1);
			}
		}
		if (bulletstatus1 == 1) {
			erase_bullet(bx2, by2);
			if (by2 == 0) bulletstatus1 = 0;
			if (by2 >= 1) {
				bullet(bx2, --by2);
			}
		}
		if (bulletstatus2 == 1) {
			erase_bullet(bx3, by3);
			if (by3 == 0) bulletstatus2 = 0;
			if (by3 >= 1) {
				bullet(bx3, --by3);
			}
		}
		if (bulletstatus3 == 1) {
			erase_bullet(bx4, by4);
			if (by4 == 0) bulletstatus3 = 0;
			if (by4 >= 1) {
				bullet(bx4, --by4);
			}
		}
		if (bulletstatus4 == 1) {
			erase_bullet(bx5, by5);
			if (by5 == 0) bulletstatus4 = 0;
			if (by5 >= 1) {
				bullet(bx5, --by5);
			}
		}
			fflush(stdin);
		Sleep(100);
	} while (ch != 'x');
	
	return 0;
}
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(2, 4);
	printf("<-0->");
}
void erase_ship(int x, int y) {
	gotoxy(x, y);
	setcolor(7, 0);
	printf("     ");
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void setcolor(int fg, int bg) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void bullet(int x, int y) {
	gotoxy(x, y);
	setcolor(7, 0);
	printf("|");
}
void erase_bullet(int x, int y) {
	gotoxy(x, y);
	setcolor(7, 0);
	printf(" ");
}
