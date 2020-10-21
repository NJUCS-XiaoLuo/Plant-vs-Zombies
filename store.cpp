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
	plant[0].set_plantcard(1, "向日葵  ", 250, 50);
	plant[1].set_plantcard(2, "豌豆射手", 250, 100);
}
//植物卡片打印
void Store::init() {
	sun_num = 100;//初始阳光数
	score = 0;
	paint_store_ui();

	//paint_plant_card_ui();
}
void PlantSet::print_card() {
	//确定输出位置
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
//商店ui界面打印
void Store::paint_store_ui() {
	//不变ui输出
	setXY(2, UP_HEIGHT);
	cout << "【商店】";
	setXY(SPLIT_CHAR_X, SPLIT_CHAR_Y);
	cout << "|";
	setXY(SPLIT_CHAR_X - 20, SPLIT_CHAR_Y);
	cout << "【阳光： " << sun_num << " $ ";
	setXY(SPLIT_CHAR_X + 2, SPLIT_CHAR_Y);
	cout << "得分： " << score << " 】";
	setXY(0, UP_HEIGHT + 1);
	string str(WINDOWS_X, '-');
	cout << str << endl;
	setXY(0, SHORE_HEIGHT - 1);
	cout << str << endl;


	//可变ui输出
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