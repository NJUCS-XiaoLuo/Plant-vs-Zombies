#pragma once
#include "windows_tools.h"
class Bullet {
	int speed;
	int counter;//ʱ�����
	int x, y;//��ǰ����λ��
	int map_y;//��ǰ���ڵ�ͼ���к�
public:
	Bullet() {
		speed = 5;
		counter = 0;
		x = y = 0;
	}
	//�����ӵ�
	void draw_bullet(int dx,int dy) {
		setXY(dx, dy);
		setColor(BULLET_COLOR);
		cout << "*";
		setColor(NORMAL_COLOR);
	}
	//����ӵ�
	void clear_bullet(int dx,int dy) {
		setXY(dx, dy);
		cout << " ";
	}
	//�ı��ӵ��Ĳ���
	void changeXY(int dx, int dy) {
		x = dx;
		y = dy;
	}
	//��ȡ�ӵ���xλ��
	int getX() {
		return x;
	}
	//��ȡ�ӵ���yλ��
	int getY() {
		return y;
	}
	//�����ӵ����ڵ���
	void set_row(int irow) {
		map_y = irow;
	}
	//��ȡ�ӵ����ڵ���
	int get_row() {
		return map_y;
	}
};