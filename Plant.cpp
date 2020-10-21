#include "Plant.h"
#include "game.h"
void Plant::plant(PLANT_NAME plant_kind, int dx, int dy) {

	switch (plant_kind) {
	case SUNFLOWER:
		setXY(dx, dy);
		setColor(SUNFLOWER_COLOR);
		cout << "ÏòÈÕ¿û  ";
		break;
	case PEASHOOTER:
		setXY(dx, dy);
		setColor(PEASHOOTER_COLOR);
		cout << "Íã¶¹ÉäÊÖ";
		break;
	default:break;
	}
	setColor(PEASHOOTER_COLOR);
}
void Sunflower::go(Game& nowgame) {
	counter += 10;
	if (counter >= produce_time) {
		nowgame.store.add_sun(25);
		//setXY(10, 5);
		//cout << "produce";
		counter = 0;
	}
}
void Peashooter::go(Game& nowgame) {
	counter += 10;
	if (counter >= attack_time) {
		nowgame.addbullet(up_left_x, up_left_y);
		counter = 0;
	}
}