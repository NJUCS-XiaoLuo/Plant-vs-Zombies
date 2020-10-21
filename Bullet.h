#pragma once
#include "windows_tools.h"
class Bullet {
	int speed;
	int counter;//时间计数
	int x, y;//当前所在位置
	int map_y;//当前所在地图的行号
public:
	Bullet() {
		speed = 5;
		counter = 0;
		x = y = 0;
	}
	//绘制子弹
	void draw_bullet(int dx,int dy) {
		setXY(dx, dy);
		setColor(BULLET_COLOR);
		cout << "*";
		setColor(NORMAL_COLOR);
	}
	//清除子弹
	void clear_bullet(int dx,int dy) {
		setXY(dx, dy);
		cout << " ";
	}
	//改变子弹的参数
	void changeXY(int dx, int dy) {
		x = dx;
		y = dy;
	}
	//获取子弹的x位置
	int getX() {
		return x;
	}
	//获取子弹的y位置
	int getY() {
		return y;
	}
	//设置子弹所在的行
	void set_row(int irow) {
		map_y = irow;
	}
	//获取子弹所在的行
	int get_row() {
		return map_y;
	}
};