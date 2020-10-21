#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>
#include<cstdlib>
#include<string>
#include<time.h>
#include<conio.h>
#include<iostream>

using namespace std;

//////////////////////////////////////////////////////////////////ui����ߴ���Ϣ


//��ͼ��ÿ����ӵĿ�ȣ��ַ�����
const int CELL_WIDTH = 11;
//��ͼ��ÿ����ӵĸ߶ȣ��ַ�����
const int CELL_HEIGHT = 5;
//��ͼÿ�а����ĸ�����
const int MAP_NUM_X = 8;
//��ͼÿ�а����ĸ�����
const int MAP_NUM_Y = 5;



//�̵�UI������ʾ���Ͻ磨��ͼ�·���һ�е�λ�ã�- y��ֵ
const int UP_HEIGHT = 0;
//const int UP_HEIGHT = (CELL_HEIGHT + 1) * MAP_NUM_Y + 3;

//�̵�UIռ�ݵĸ߶ȣ��ַ�����
const int SHORE_HEIGHT = 8;
//���ƴ���Ĵ�С(������Ĳ���Ϊ׼������)
const int WINDOWS_X = (CELL_WIDTH + 1) * MAP_NUM_X + (CELL_WIDTH + 1) * 3 / 2;
const int WINDOWS_Y = (CELL_HEIGHT + 1) * MAP_NUM_Y + SHORE_HEIGHT + 3;

//�̵�UI����ָ�����|����λ��
const int SPLIT_CHAR_X = WINDOWS_X - 20;
const int SPLIT_CHAR_Y = UP_HEIGHT;


//��Ϸ״̬��ʾ����λ�� - y��ֵ
const int STATUE_POSITION = (CELL_HEIGHT + 1) * MAP_NUM_Y + SHORE_HEIGHT + 3;



//////////////////////////////////////////////////ֲ���뽩ʬ�Ĳ���

//ֲ��������
const int PLANT_TYPE = 2;
//��ʬ������
const int ZOMBIE_TYPE = 1;



/////////////////////////////////////////////////��ɫ����
//Ĭ����ɫ���ڵװ��֣�
const int NORMAL_COLOR = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
//ֲ�￨Ƭ��ѡ�к����ɫ
const int SELECTED_COLOR = BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
//��ͼ���ӱ�ѡ�к����ɫ
const int MAP_SELECTED_COLOR = FOREGROUND_RED | FOREGROUND_GREEN;

//�㶹���ֵ���ɫ
const int PEASHOOTER_COLOR = BACKGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
//���տ�����ɫ
const int SUNFLOWER_COLOR = BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;


//��ͨ��ʬ����ɫ
const int NORMAL_ZOMBIE_COLOR = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED;
//�ӵ���ɫ
const int BULLET_COLOR = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
///////////////////////////////////////////////////����ȫ�ֲ���


//��Ϸ������ʾ�ֵ���ɫ
const int END_COLOR = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE;
//����ˢ��ʱ��
const int SLEEP_TIME = 100;
//��������CD
const int SUN_CD = 60;
//ֲ�￨Ƭ�Ŀ��
const int PLANTCARD_WIDTH = 28;
//ֲ������
enum PLANT_NAME{SUNFLOWER,PEASHOOTER};

//////////////////////////////////////////////////ȫ��ui����

//���ع��
void HideCursor();
//���ô����С
void SetWindowSize(int cols, int lines);
//ת�ƾ������Ӧλ��
void setXY(int x, int y);

///////////////////////////////////////////////////��ɫת��

//����ɫ��ӡ����
void color_num_print(int num, int color_index);
//����ɫ��ӡ�ַ���
void color_string_print(string str, int color_index);
//������ɫ
void setColor(int color_index);