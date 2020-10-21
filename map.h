#pragma once
#include<iostream>
#include "windows_tools.h"
#include "store.h"
#include "Plant.h"
#include "Zombie.h"
using namespace std;
class Cell{
	//�������Ͻǵ�����λ��
	int up_left_x, up_left_y;
	//�Ƿ�ѡ��
	bool isSelected;
	//�Ƿ��Ѿ���ֲֲ��
	bool isPlanted;
	//��ֲ��ֲ������
	int plantType;
	//�Ƿ��н�ʬ
	bool haveZombie;
	//�����жϽ�ʬ�Ƿ�ֹͣ��trueΪֹͣ��
	bool zombie_status;
	
public:
	Plant* hereplant;
	Zombie* herezombie;
	Cell();
	//��������
	void set_position(int x, int y);
	//���һ����ʬ(��ӳɹ�����true)
	bool addZombie(int tmp_health);
	//ɾ��һ����ʬ(ɾ���ɹ�����true)
	bool delZombie();
	//��ֲһ��ֲ���ֲ�ɹ�����true)
	void plant_a_plant(PLANT_NAME plant,Game& nowgame);
	//����һ��ֲ������ɹ�����true��
	bool del_a_plant();
	//���Ʊ�ѡ�к����ͼ��
	void draw_focus();
	void select() {isSelected = true;}
	void unselect() {isSelected = false;}
	bool getSelect() {return isSelected;}
	void draw_zombie();
	void clear_zombie();
	bool Check_zombie() {return haveZombie;}
	void checkeating();
	void zombie_init();
	//��ȡ��ʬ״̬��ֹͣΪtrue��
	bool get_zombie_status() {return zombie_status;}
	void init_zombie_status() { zombie_status = false; }
	void eating();
	
	//ֲ���ʬʱ�����
	int Getzombie_health() {return herezombie->gethealth();}
	~Cell();
};
class Map{
public:
	Cell grass_block[MAP_NUM_Y][MAP_NUM_X + 1];
	Map();
	void init();
	//��ͼˢ��
	void refresh();
	~Map();
	//friend class Cell;
	friend class Game;
};