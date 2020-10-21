#include"windows_tools.h"
#include<cstdio>


void HideCursor()
{
	HANDLE position = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO curinfo;
	curinfo.bVisible = 0;
	curinfo.dwSize = 1;
	SetConsoleCursorInfo(position, &curinfo);
}

void SetWindowSize(int cols, int lines)
{
	//const char* title = "植物大战僵尸（控制台版）- Plants vs. Zombies  | By NJU-Fan";
	//SetConsoleTitle(title);
	char title[100];
	sprintf(title, "title  \"植物大战僵尸（控制台版）- Plants vs. Zombies  | By NJU-Fan\" ");
	system(title);//设置窗口标题
	char cmd[30];
	sprintf(cmd, "mode con: cols=%d lines=%d", cols, lines);//向目标字符串中打印
	system(cmd); //设置窗口宽度和高度
}

void setXY(int x, int y) {
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void color_num_print(int num, int color_index) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_index);
	cout << num;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL_COLOR);
}

void color_string_print(string str, int color_index) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_index);
	cout << str;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), NORMAL_COLOR);
}

void setColor(int color_index) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_index);
}
