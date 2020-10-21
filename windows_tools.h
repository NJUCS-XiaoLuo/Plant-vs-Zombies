#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>
#include<cstdlib>
#include<string>
#include<time.h>
#include<conio.h>
#include<iostream>

using namespace std;

//////////////////////////////////////////////////////////////////ui界面尺寸信息


//地图中每块格子的宽度（字符数）
const int CELL_WIDTH = 11;
//地图中每块格子的高度（字符数）
const int CELL_HEIGHT = 5;
//地图每行包含的格子数
const int MAP_NUM_X = 8;
//地图每列包含的格子数
const int MAP_NUM_Y = 5;



//商店UI界面显示的上界（地图下方隔一行的位置）- y的值
const int UP_HEIGHT = 0;
//const int UP_HEIGHT = (CELL_HEIGHT + 1) * MAP_NUM_Y + 3;

//商店UI占据的高度（字符数）
const int SHORE_HEIGHT = 8;
//绘制窗体的大小(多出来的部分为准备区域)
const int WINDOWS_X = (CELL_WIDTH + 1) * MAP_NUM_X + (CELL_WIDTH + 1) * 3 / 2;
const int WINDOWS_Y = (CELL_HEIGHT + 1) * MAP_NUM_Y + SHORE_HEIGHT + 3;

//商店UI界面分隔符“|”的位置
const int SPLIT_CHAR_X = WINDOWS_X - 20;
const int SPLIT_CHAR_Y = UP_HEIGHT;


//游戏状态显示栏的位置 - y的值
const int STATUE_POSITION = (CELL_HEIGHT + 1) * MAP_NUM_Y + SHORE_HEIGHT + 3;



//////////////////////////////////////////////////植物与僵尸的参数

//植物种类数
const int PLANT_TYPE = 2;
//僵尸种类数
const int ZOMBIE_TYPE = 1;



/////////////////////////////////////////////////颜色设置
//默认颜色（黑底白字）
const int NORMAL_COLOR = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
//植物卡片被选中后的颜色
const int SELECTED_COLOR = BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
//地图格子被选中后的颜色
const int MAP_SELECTED_COLOR = FOREGROUND_RED | FOREGROUND_GREEN;

//豌豆射手的颜色
const int PEASHOOTER_COLOR = BACKGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
//向日葵的颜色
const int SUNFLOWER_COLOR = BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;


//普通僵尸的颜色
const int NORMAL_ZOMBIE_COLOR = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED;
//子弹颜色
const int BULLET_COLOR = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
///////////////////////////////////////////////////其他全局参数


//游戏结束显示字的颜色
const int END_COLOR = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE;
//界面刷新时间
const int SLEEP_TIME = 100;
//阳光自增CD
const int SUN_CD = 60;
//植物卡片的宽度
const int PLANTCARD_WIDTH = 28;
//植物名称
enum PLANT_NAME{SUNFLOWER,PEASHOOTER};

//////////////////////////////////////////////////全局ui函数

//隐藏光标
void HideCursor();
//设置窗体大小
void SetWindowSize(int cols, int lines);
//转移句柄到对应位置
void setXY(int x, int y);

///////////////////////////////////////////////////颜色转换

//带颜色打印数字
void color_num_print(int num, int color_index);
//带颜色打印字符串
void color_string_print(string str, int color_index);
//设置颜色
void setColor(int color_index);