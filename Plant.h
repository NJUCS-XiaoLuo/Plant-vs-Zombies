#pragma once
//#include "game.h"
#include "windows_tools.h"
//#include "game.h"

class Game;

class Plant {

protected:
	//�������ֵ
	int max_health;
	//��ǰ����ֵ
	int health;
	//��ǰ���ڸ������꣨�㶹���ָ�Ϊ�ӵ������꣩
	int up_left_x, up_left_y;
	int cost;
	int row;

public:
	Plant(){}
	//�Ƿ񱻳�
	bool isate() {
		return false;
	}
	//���ڱ���
	bool iseating() {
		return false;
	}
	virtual void go(Game& nowgame) {}
	void plant(PLANT_NAME plant_kind, int dx, int dy);
	void isattacked(int attack) {
		health -= attack;
	}
	void getXY(int dx,int dy) {
		up_left_x = dx;
		up_left_y = dy;
	}
	int gethealth() {
		return health;
	}
	friend class Cell;
};
class Sunflower :public Plant {
	//ÿ��������������
	//const char* name;
	const int sun_produce;
	//��������ļ��
	const int produce_time;
	int counter;
public:
	Sunflower():sun_produce(25),produce_time(800){
		counter = 0;
		up_left_x = up_left_y = -1;
		max_health = 300;
		health = 300;
		cost = 50;
	}
	void go(Game& nowgame);
};
class Peashooter :public Plant {
	//ÿ��������������
	//const char* name;
	const int attack;
	//��������ļ��
	const int attack_time;
	int counter;

public:
	Peashooter() : attack(20), attack_time(300) {
		counter = 0;
		up_left_x = up_left_y = -1;
		max_health = 300;
		health = 300;
		cost = 100;
	}
	void go(Game& nowgame);
};