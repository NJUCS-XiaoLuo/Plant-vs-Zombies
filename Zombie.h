#pragma once
#include "windows_tools.h"
class Zombie {
	int health;//当前生命值
	int max_health;//最大生命值
	int attack;//攻击力
	int speed;//移动速度（暂时设定为4s一动）
	int up_left_x;
	int up_left_y;
public:
	Zombie(int ihealth) {
		health = ihealth;
		max_health = 200;
		up_left_x = -1;
		up_left_y = -1;
		attack = 100;//每100ms的攻击力
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