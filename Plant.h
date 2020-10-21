#pragma once
//#include "game.h"
#include "windows_tools.h"
//#include "game.h"

class Game;

class Plant {

protected:
	//最大生命值
	int max_health;
	//当前生命值
	int health;
	//当前所在格子坐标（豌豆射手改为子弹的坐标）
	int up_left_x, up_left_y;
	int cost;
	int row;

public:
	Plant(){}
	//是否被吃
	bool isate() {
		return false;
	}
	//正在被吃
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
	//每次生产的阳光数
	//const char* name;
	const int sun_produce;
	//生产阳光的间隔
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
	//每次生产的阳光数
	//const char* name;
	const int attack;
	//生产阳光的间隔
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