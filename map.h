#pragma once
#include<iostream>
#include "windows_tools.h"
#include "store.h"
#include "Plant.h"
#include "Zombie.h"
using namespace std;
class Cell{
	//格子左上角的坐标位置
	int up_left_x, up_left_y;
	//是否被选中
	bool isSelected;
	//是否已经种植植物
	bool isPlanted;
	//种植的植物类型
	int plantType;
	//是否有僵尸
	bool haveZombie;
	//用于判断僵尸是否停止（true为停止）
	bool zombie_status;
	
public:
	Plant* hereplant;
	Zombie* herezombie;
	Cell();
	//设置坐标
	void set_position(int x, int y);
	//添加一个僵尸(添加成功返回true)
	bool addZombie(int tmp_health);
	//删除一个僵尸(删除成功返回true)
	bool delZombie();
	//种植一个植物（种植成功返回true)
	void plant_a_plant(PLANT_NAME plant,Game& nowgame);
	//铲除一个植物（铲除成功返回true）
	bool del_a_plant();
	//绘制被选中后界面图案
	void draw_focus();
	void select() {isSelected = true;}
	void unselect() {isSelected = false;}
	bool getSelect() {return isSelected;}
	void draw_zombie();
	void clear_zombie();
	bool Check_zombie() {return haveZombie;}
	void checkeating();
	void zombie_init();
	//获取僵尸状态（停止为true）
	bool get_zombie_status() {return zombie_status;}
	void init_zombie_status() { zombie_status = false; }
	void eating();
	
	//植物打僵尸时候调用
	int Getzombie_health() {return herezombie->gethealth();}
	~Cell();
};
class Map{
public:
	Cell grass_block[MAP_NUM_Y][MAP_NUM_X + 1];
	Map();
	void init();
	//地图刷新
	void refresh();
	~Map();
	//friend class Cell;
	friend class Game;
};