#pragma once
#include<iostream>
#include "windows_tools.h"
//植物集合
class PlantSet {
	//冷却时间
	int cooling_time;
	//花费阳光数
	int cost;
	//植物编号
	int num;
	//植物名称
	string name;
	//是否被选中
	bool isSelected;

	int counter;//时间计数

	bool status;//(是否处于冷却中)
	//friend class Game;
public:
	PlantSet() {
		isSelected = false;
		status = false;
		counter = 0;
	}
	//设置植物卡片的初始参数
	void set_plantcard(int inum, const string& iname, int icooling_time, int icost);
	//打印植物卡片
	void print_card();
	//选中植物卡片
	void selected() {
		isSelected = true;
	}
	//未选中植物卡片
	void unselected() {
		isSelected = false;
	}
	//判断是否选中植物卡片
	bool JudgeSelected() {
		return isSelected;
	}
	//获取植物的花费
	int getCost() {
		return cost;
	}
	//判断植物是否处于冷却状态
	bool Cooling() {
		if (status == true) {
			counter += 10;
			if (counter >= cooling_time) {
				status = false;
				counter = 0;
			}
			return false;
		}
		else
			return false;
	}
	//判断是否可以种植植物
	bool canPlant() {
		if (status == false) {
			status = true;
			return true;
		}
		else
			return false;
	}
	~PlantSet(){}
};


class Store{
	//当前阳光数
	int sun_num;
	//当前得分
	int score;

public:
	PlantSet plant[PLANT_TYPE];

	Store();
	//商店界面初始化
	void init();
	
	int getSun() {
		return sun_num;
	}
	void refresh() {
		paint_store_ui();
	}
	int getCost(PLANT_NAME plant_name);
	void run() {
		for (int i = 0;i < PLANT_TYPE;++i) {
			plant[i].Cooling();
		}
	}
	
	//商店ui界面打印
	void paint_store_ui();
	//增加阳光数
	void add_sun(int isun_num);
	~Store();
	int getscore() {
		return score;
	}
	void change_score(int num) {
		score =  num;
	}
	friend class Game;
};