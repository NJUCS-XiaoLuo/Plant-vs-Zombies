#pragma once
#include<iostream>
#include "windows_tools.h"
#include "map.h"
#include "store.h"
#include "Zombie.h"
#include "Bullet.h"
#include <vector>
//#include "Plant.h"
struct zombies {
	Zombie* zombie;
	int row;//行
	int col;//列
};
using namespace std;
//定义游戏状态（游戏中，种植中，铲除中，暂停中）
enum gamestatus{PLAYING,PLANTING,SHOVELING,PAUSING};
struct BULLET{
	Bullet* bullet;
	int counter;//时间计数
};
class Game {
	//当前游戏状态
	int status;
	//种植植物的标号
	int plant_type;
	//阳光自动生产时间计数
	int count;
	//是否购买结束
	bool shopping_end;
	//地图选择开关位置
	int select_x, select_y;
	//游戏结束
	bool end;

	int counter_zombie;//僵尸产生计数
	int move_counter;//僵尸移动计数

	int count_kill_zombie;//杀死僵尸数

	vector<zombies> all_zombie;
	//friend class Cell;
public:
	Map map;
	Store store;
	vector<BULLET> bullet;

	Game();
	//游戏初始化
	void init();
	//游戏主循环
	void loop();
	//购买并种植植物
	void shopping();
	//铲除植物
	void shoveling();
	//暂停
	void pausing(int tmp_status);
	//界面刷新
	void refresh();
	//游戏正常运行
	void playing();
	//开启地图焦点
	void openfocus(int& x, int& y);
	//关闭地图焦点
	void closefocus(int& x, int& y);
	~Game();
	//阳光自增
	void sun_increase();
	//游戏结束
	void gameover();
	//产生僵尸
	void makezombie();
	//僵尸移动
	void movezombie();
	//清除僵尸
	void delzombie();
	void score_run() {
		int new_score = count_kill_zombie * 20;
		this->store.change_score(new_score);
	}
	//添加子弹显示
	void addbullet(int x, int y);
	//移动子弹
	void movebullet();
	//清除子弹
	void clearbullet();
	friend class Plant;
};