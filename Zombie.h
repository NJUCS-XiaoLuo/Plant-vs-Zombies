#pragma once
#include "windows_tools.h"
class Zombie {
	int health;//��ǰ����ֵ
	int max_health;//�������ֵ
	int attack;//������
	int speed;//�ƶ��ٶȣ���ʱ�趨Ϊ4sһ����
	int up_left_x;
	int up_left_y;
public:
	Zombie(int ihealth) {
		health = ihealth;
		max_health = 200;
		up_left_x = -1;
		up_left_y = -1;
		attack = 100;//ÿ100ms�Ĺ�����
	}
	int gethealth() {
		return health;
	}
	void getXY(int dx, int dy) {
		up_left_x = dx;
		up_left_y = dy;
	}
	int getX() {
		return up_left_x - 1;
	}
	int get_row(){
		return (up_left_y - 1 - SHORE_HEIGHT) / (CELL_HEIGHT + 1);
	}
	int getattack() {
		return attack;
	}
	void isattacked(int attack) {
		health -= attack;
	}
};