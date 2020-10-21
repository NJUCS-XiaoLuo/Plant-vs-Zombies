#include "store.h"
using namespace std;

void PlantSet::set_plantcard(int inum, const string& iname, int icooling_time, int icost){
	num = inum;
	name = iname;
	cooling_time = icooling_time;
	cost = icost;
	isSelected = false;
}

Store::Store(){
	plant[0].set_plantcard(1, "���տ�  ", 250, 50);
	plant[1].set_plantcard(2, "�㶹����", 250, 100);
}
//ֲ�￨Ƭ��ӡ
void Store::init() {
	sun_num = 100;//��ʼ������
	score = 0;
	paint_store_ui();

	//paint_plant_card_ui();
}
void PlantSet::print_card() {
	//ȷ�����λ��
	int dx = -1;
	int dy = -1;
	switch (num) {
	case 1:
		dx = 0 * PLANTCARD_WIDTH;dy = UP_HEIGHT + 2;
		break;
	case 2:
		dx = 1 * PLANTCARD_WIDTH;dy = UP_HEIGHT + 2;
		break;
	default: break;
	}
	setXY(dx,dy);
	string str(PLANTCARD_WIDTH, ' ');
	cout << str;
	setXY(dx, dy);
	if (isSelected)
		setColor(SELECTED_COLOR);
	//cout << isSelected;
	cout << num << "." << name << " - " << cost << "$";
	setColor(NORMAL_COLOR);
}
//�̵�ui�����ӡ
void Store::paint_store_ui() {
	//����ui���
	setXY(2, UP_HEIGHT);
	cout << "���̵꡿";
	setXY(SPLIT_CHAR_X, SPLIT_CHAR_Y);
	cout << "|";
	setXY(SPLIT_CHAR_X - 20, SPLIT_CHAR_Y);
	cout << "�����⣺ " << sun_num << " $ ";
	setXY(SPLIT_CHAR_X + 2, SPLIT_CHAR_Y);
	cout << "�÷֣� " << score << " ��";
	setXY(0, UP_HEIGHT + 1);
	string str(WINDOWS_X, '-');
	cout << str << endl;
	setXY(0, SHORE_HEIGHT - 1);
	cout << str << endl;


	//�ɱ�ui���
	for (int i = 0;i < PLANT_TYPE;++i) {
		plant[i].print_card();
	}
}

void Store::add_sun(int isun_num) {
	sun_num += isun_num;
}
int Store::getCost(PLANT_NAME plant_name) {
	switch (plant_name) {
	case SUNFLOWER:
		return plant[0].getCost();
	case PEASHOOTER:
		return plant[1].getCost();
	default:break;
	}
}

Store::~Store() {
	
}