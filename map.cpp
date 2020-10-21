#include "map.h"
#include "game.h"

Cell::Cell() {
	hereplant = nullptr;
	herezombie = nullptr;
	up_left_x = up_left_y = 1;
	isSelected = false;
	isPlanted = false;
	plantType = -1;
	haveZombie = false;
	zombie_status = false;
}

void Cell::set_position(int x, int y) {
	up_left_x = x * (CELL_WIDTH + 1) + 1;
	up_left_y = SHORE_HEIGHT + y * (CELL_HEIGHT + 1) + 1;
}
bool Cell::addZombie(int tmp_health) {
	herezombie = new Zombie(tmp_health);
	haveZombie = true;
	herezombie->getXY(up_left_x, up_left_y);
	draw_zombie();
	return true;
}
bool Cell::delZombie() {
	delete herezombie;
	herezombie = nullptr;
	haveZombie = false;
	clear_zombie();
	return true;
}
void Cell::plant_a_plant(PLANT_NAME plant,Game& nowgame) {
	//setXY(0,5);
	//cout << nowgame.store.getCost(plant);
	if (!isPlanted && nowgame.store.getSun() > nowgame.store.getCost(plant)) {
		if (!nowgame.store.plant[plant].canPlant())
			return;
		int dx, dy;
		dx = up_left_x + 1;
		dy = up_left_y + 2;
		switch (plant) {
		case SUNFLOWER:
			hereplant = new Sunflower();
			break;
		case PEASHOOTER:
			hereplant = new Peashooter();
			break;
		}
		hereplant->plant(plant, dx, dy);
		hereplant->getXY(up_left_x, up_left_y);
		nowgame.store.add_sun(-nowgame.store.getCost(plant));
		isPlanted = true;
	}
	return;
}
bool Cell::del_a_plant() {
	if (hereplant->gethealth() <= 0) {
		int dx = up_left_x;
		int dy = up_left_y + 2;
		setXY(dx, dy);
		cout << "          ";
		delete hereplant;
		//初始化格子中的参数
		hereplant = nullptr;
		isPlanted = false;
		plantType = -1;
		init_zombie_status();//恢复僵尸初始状态（可以移动）
	}
	return true;
}
void Cell::draw_focus() {
	if (isSelected) {
		setColor(MAP_SELECTED_COLOR);
		for (int i = 0;i < CELL_HEIGHT;++i) {
			setXY(up_left_x, up_left_y + i);
			if (i == 0 || i == CELL_HEIGHT - 1)
				for (int j = 0;j < CELL_WIDTH;++j)cout << "+";
			else {
				setXY(up_left_x, up_left_y + i);
				cout << "+";
				setXY(up_left_x + CELL_WIDTH - 1, up_left_y + i);
				cout << "+";
			}
		}
		setColor(NORMAL_COLOR);
	}
	else {
		for (int i = 0;i < CELL_HEIGHT;++i) {
			setXY(up_left_x, up_left_y + i);
			if (i == 0 || i == CELL_HEIGHT - 1)
				for (int j = 0;j < CELL_WIDTH;++j)cout << " ";
			else {
				setXY(up_left_x, up_left_y + i);
				cout << " ";
				setXY(up_left_x + CELL_WIDTH - 1, up_left_y + i);
				cout << " ";
			}

		}
	}
}
void Cell::draw_zombie() {
	if (haveZombie) {
		setXY(up_left_x + 1, up_left_y + 1);
		setColor(NORMAL_ZOMBIE_COLOR);
		cout << "小僵尸" << endl;
		setColor(NORMAL_COLOR);
	}
}
void Cell::clear_zombie() {
	if (!haveZombie)
		setXY(up_left_x, up_left_y + 1);
	cout << "           ";
}
void Cell::checkeating() {
	if (hereplant != NULL && herezombie != NULL)
		zombie_status = true;
}
void Cell::eating() {
	if (zombie_status == true) {//正在吃植物
		hereplant->isattacked(herezombie->getattack());
	}
}
void Cell::zombie_init() {
	delete herezombie;
	herezombie = nullptr;
	haveZombie = false;
	zombie_status = false;
	setXY(up_left_x, up_left_y + 1);
	cout << "          ";
}
Cell::~Cell (){}


Map::Map() {}
void Map::init() {
	system("cls");
	//绘制地图
	setXY(0, SHORE_HEIGHT);
	for (int y = 0;y < MAP_NUM_Y;++y) {
		string str(WINDOWS_X,'#');
		cout << str << endl;
		for (int i = 0;i < CELL_HEIGHT;++i) {
			for (int j = 0;j < MAP_NUM_X;++j) {
				string str1(CELL_WIDTH,' ');
				cout << "#" << str1;
			}
			string str2(17,' ');
			cout << "#" << str2 << endl;
		}
	}
	string str(WINDOWS_X, '#');
	cout << str << endl;

	//初始化格子参数
	for (int y = 0;y < MAP_NUM_Y;++y) {
		for (int x = 0;x <= MAP_NUM_X;++x) {
			grass_block[y][x].set_position(x, y);
		}
	}
}
void Map::refresh() {
	for (int i = 0;i < MAP_NUM_X;++i) {
		for (int j = 0;j < MAP_NUM_Y;++j) {
			if (grass_block[j][i].getSelect())grass_block[j][i].draw_focus();
		}
	}
}
Map::~Map() {}