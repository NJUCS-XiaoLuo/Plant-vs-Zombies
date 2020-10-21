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
	int row;//��
	int col;//��
};
using namespace std;
//������Ϸ״̬����Ϸ�У���ֲ�У������У���ͣ�У�
enum gamestatus{PLAYING,PLANTING,SHOVELING,PAUSING};
struct BULLET{
	Bullet* bullet;
	int counter;//ʱ�����
};
class Game {
	//��ǰ��Ϸ״̬
	int status;
	//��ֲֲ��ı��
	int plant_type;
	//�����Զ�����ʱ�����
	int count;
	//�Ƿ������
	bool shopping_end;
	//��ͼѡ�񿪹�λ��
	int select_x, select_y;
	//��Ϸ����
	bool end;

	int counter_zombie;//��ʬ��������
	int move_counter;//��ʬ�ƶ�����

	int count_kill_zombie;//ɱ����ʬ��

	vector<zombies> all_zombie;
	//friend class Cell;
public:
	Map map;
	Store store;
	vector<BULLET> bullet;

	Game();
	//��Ϸ��ʼ��
	void init();
	//��Ϸ��ѭ��
	void loop();
	//������ֲֲ��
	void shopping();
	//����ֲ��
	void shoveling();
	//��ͣ
	void pausing(int tmp_status);
	//����ˢ��
	void refresh();
	//��Ϸ��������
	void playing();
	//������ͼ����
	void openfocus(int& x, int& y);
	//�رյ�ͼ����
	void closefocus(int& x, int& y);
	~Game();
	//��������
	void sun_increase();
	//��Ϸ����
	void gameover();
	//������ʬ
	void makezombie();
	//��ʬ�ƶ�
	void movezombie();
	//�����ʬ
	void delzombie();
	void score_run() {
		int new_score = count_kill_zombie * 20;
		this->store.change_score(new_score);
	}
	//����ӵ���ʾ
	void addbullet(int x, int y);
	//�ƶ��ӵ�
	void movebullet();
	//����ӵ�
	void clearbullet();
	friend class Plant;
};