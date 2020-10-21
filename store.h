#pragma once
#include<iostream>
#include "windows_tools.h"
//ֲ�Ｏ��
class PlantSet {
	//��ȴʱ��
	int cooling_time;
	//����������
	int cost;
	//ֲ����
	int num;
	//ֲ������
	string name;
	//�Ƿ�ѡ��
	bool isSelected;

	int counter;//ʱ�����

	bool status;//(�Ƿ�����ȴ��)
	//friend class Game;
public:
	PlantSet() {
		isSelected = false;
		status = false;
		counter = 0;
	}
	//����ֲ�￨Ƭ�ĳ�ʼ����
	void set_plantcard(int inum, const string& iname, int icooling_time, int icost);
	//��ӡֲ�￨Ƭ
	void print_card();
	//ѡ��ֲ�￨Ƭ
	void selected() {
		isSelected = true;
	}
	//δѡ��ֲ�￨Ƭ
	void unselected() {
		isSelected = false;
	}
	//�ж��Ƿ�ѡ��ֲ�￨Ƭ
	bool JudgeSelected() {
		return isSelected;
	}
	//��ȡֲ��Ļ���
	int getCost() {
		return cost;
	}
	//�ж�ֲ���Ƿ�����ȴ״̬
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
	//�ж��Ƿ������ֲֲ��
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
	//��ǰ������
	int sun_num;
	//��ǰ�÷�
	int score;

public:
	PlantSet plant[PLANT_TYPE];

	Store();
	//�̵�����ʼ��
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
	
	//�̵�ui�����ӡ
	void paint_store_ui();
	//����������
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