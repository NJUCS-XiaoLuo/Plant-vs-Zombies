#include "game.h"
Game::Game() {
	select_x = 0, select_y = 0;
	shopping_end = false;
	count = 0;
	plant_type = -1;

	end = false;
	counter_zombie = 0;
	move_counter = 0;
	count_kill_zombie = 0;
	//默认游戏初始状态 - 正常状态
	status = PLAYING;
	HideCursor();
	SetWindowSize(WINDOWS_X, WINDOWS_Y);
	srand(time(0));
}
void Game::init(){
	map.init();
	store.init();
}
void Game::loop() {
	char ch;
	int tmp_status = PLAYING;
	while (true) {
		if (status == PLAYING) {
			if (_kbhit()) {//如果有按键按下，则_kbhit()函数返回真
				ch = _getch();//使用_getch()函数获取按下的键值
				switch (ch) {
				case 'b':
					status = PLANTING;break;
				case 'x':
					status = SHOVELING;break;
				case 32:
					status = PAUSING;break;
				default:
					status = PLAYING;break;
				}
			}
			//changeStatus();
			switch (status) {
			case PLAYING:
				//cout << "playing";
				break;
			case PLANTING:
				shopping();
				break;
			case SHOVELING:
				shoveling();break;
			case PAUSING:
				tmp_status = status;
				pausing(tmp_status);break;
			default:break;
			}
		}
		if (status == PLANTING) {
			shopping();
		}
		if (status == SHOVELING) {
			shoveling();
		}
		sun_increase();//增加阳光
		refresh();//刷新界面

		//植物功能触发
		//cout << "going" << endl;
		for (int i = 0;i < MAP_NUM_X;++i) {
			for (int j = 0;j < MAP_NUM_Y;++j) {
				if(map.grass_block[j][i].hereplant != nullptr)
					map.grass_block[j][i].hereplant->go(*this);
			}
		}

		

		clearbullet();
		movebullet();

		//产生僵尸
		makezombie();
		movezombie();
		delzombie();


		store.run();
		score_run();
		if (end) {
			gameover();
			break;
		}
		
		Sleep(SLEEP_TIME);
	}
}
void Game::openfocus(int& x, int& y) {
	map.grass_block[y][x].select();
	map.grass_block[y][x].draw_focus();
}
void Game::closefocus(int& x, int& y) {
	map.grass_block[y][x].unselect();
	map.grass_block[y][x].draw_focus();
}
void Game::sun_increase() {
	if (count >= 200) {
		store.add_sun(25);
		count = 0;
	}
	count += 10;
}
void Game::makezombie() {
	int raw;//第几行产生僵尸
	raw = rand() % 5;
	counter_zombie += 10;
	if (counter_zombie > 400) {//随机僵尸的生成时间
		map.grass_block[raw][MAP_NUM_X].addZombie(200);
		counter_zombie = 0;
		zombies new_zombie;
		new_zombie.row = raw;
		new_zombie.col = MAP_NUM_X;
		new_zombie.zombie = map.grass_block[raw][MAP_NUM_X].herezombie;

		all_zombie.push_back(new_zombie);//僵尸添加
	}
}
void Game::movezombie() {
	if (move_counter > 400) {
		for (int i = 0;i <= MAP_NUM_X;++i) {
			for (int j = 0;j < MAP_NUM_Y;++j) {
				map.grass_block[j][i].checkeating();
				if (map.grass_block[j][i].Check_zombie() == true && map.grass_block[j][i].get_zombie_status() == false) {
					if (i > 0) {
						int tmp_health = map.grass_block[j][i].Getzombie_health();
						map.grass_block[j][i].delZombie();

						for (int k = 0;k < all_zombie.size();++k) {
							if (all_zombie[k].row == j && all_zombie[k].col == i) {
								all_zombie.erase(all_zombie.begin() + k);
							}
						}
						map.grass_block[j][i - 1].addZombie(tmp_health);

						zombies new_zombie;
						new_zombie.row = j;
						new_zombie.col = i - 1;
						new_zombie.zombie = map.grass_block[j][i-1].herezombie;
						all_zombie.push_back(new_zombie);

					}
					else if (i == 0) {
						if (map.grass_block[j][i].Getzombie_health() > 0)
							end = true;
					}
				}
				if (map.grass_block[j][i].get_zombie_status() == true) {//植物正在被吃
					map.grass_block[j][i].eating();
					map.grass_block[j][i].del_a_plant();
				}
			}
		}
		move_counter = 0;
	}
	else
		move_counter += 10;
}
void Game::delzombie() {
	for (int i = 0;i < MAP_NUM_X;++i) {
		for (int j = 0;j < MAP_NUM_Y;++j) {
			if (map.grass_block[j][i].herezombie != nullptr) {
				if (map.grass_block[j][i].herezombie->gethealth() <= 0) {

					for (int k = 0;k < all_zombie.size();++k) {
						if (all_zombie[k].row == j && all_zombie[k].col == i) {
							all_zombie.erase(all_zombie.begin() + k);
						}
					}

					map.grass_block[j][i].zombie_init();
					count_kill_zombie++;
				}
			}
		}
	}
}
void Game::addbullet(int x, int y) {
	Bullet* a = new Bullet;
	BULLET new_bullet;
	new_bullet.bullet = a;
	int row = (y - SHORE_HEIGHT - 1) / (CELL_HEIGHT + 1);
	for (int k = 0;k < all_zombie.size();++k) {
		if (all_zombie[k].row == row) {
			if (new_bullet.bullet->getX() == 0 && new_bullet.bullet->getY() == 0) {//首次初始化
				new_bullet.bullet->changeXY(x + 9, y + 1);//////////////////////////////////////////////////更改位置！！！！！
				new_bullet.bullet->draw_bullet(new_bullet.bullet->getX(), new_bullet.bullet->getY());
				new_bullet.counter = 0;
				new_bullet.bullet->set_row((y - SHORE_HEIGHT - 1) / (CELL_HEIGHT + 1));
			}
			this->bullet.push_back(new_bullet);
			break;
		}
	}
}
void Game::clearbullet() {
	if (bullet.size() > 0) {
		for (int i = 0;i < bullet.size();++i) {
			if (bullet[i].bullet->getX() == WINDOWS_X - 2) {
				bullet[i].bullet->clear_bullet(bullet[i].bullet->getX(), bullet[i].bullet->getY());
				bullet.erase(bullet.begin() + i);
				continue;
			}
			for (int j = 0;j <= MAP_NUM_X;++j) {
				for (int k = 0;k < MAP_NUM_Y;++k) {
					if (map.grass_block[k][j].herezombie != nullptr) {
						if (bullet[i].bullet->getX() >= map.grass_block[k][j].herezombie->getX() && bullet[i].bullet->getX() <= map.grass_block[k][j].herezombie->getX() + CELL_WIDTH) {//清除子弹后会导致子弹数组下标越界，因此使用goto语句跳出循环
							if (bullet[i].bullet->get_row() == map.grass_block[k][j].herezombie->get_row()) {
								bullet[i].bullet->clear_bullet(bullet[i].bullet->getX(), bullet[i].bullet->getY());
								bullet.erase(bullet.begin() + i);
								map.grass_block[k][j].herezombie->isattacked(40);
								goto end;
							}
						}
					}
				}
			}
		end:;
		}
	}
}
void Game::movebullet() {
	if (bullet.size() > 0) {
		//setXY(25, 5);
		//cout << "当前屏幕中的子弹数" << bullet.size();
		for (int i = 0;i < bullet.size();++i) {
			if (bullet[i].counter >= 10) {
				bullet[i].bullet->clear_bullet(bullet[i].bullet->getX(), bullet[i].bullet->getY());
				bullet[i].bullet->changeXY(bullet[i].bullet->getX() + 1, bullet[i].bullet->getY());
				bullet[i].bullet->draw_bullet(bullet[i].bullet->getX(), bullet[i].bullet->getY());
				bullet[i].counter = 0;
			}
			bullet[i].counter += 10;
		}
	}
}
void Game::gameover() {
		system("cls");
		setXY(0, WINDOWS_Y / 2 - 18);
		cout << "          -------                    /\\                    /\\              /\\                |-----------       " << endl;;
		cout << "        /                           /  \\                  /  \\            /  \\               |                  " << endl;
		cout << "       /                           /    \\                /    \\          /    \\              |                  " <<endl;
		cout << "       |         ----             /      \\              /      \\        /      \\             |-----------       " << endl;
		cout << "       |        |    |           /________\\            /        \\      /        \\            |                  " << endl;
		cout << "       \\            /           /          \\          /          \\    /          \\           |                  " <<endl;
		cout << "        \\          /           /            \\        /            \\  /            \\          |                  "  <<endl;
		cout << "          ---------           /              \\      /              \\/              \\         |-----------       " <<endl;
		cout << "                    -------           \\              /         |-----------            |-----------|              " << endl;;
		cout << "                  /         \\          \\            /          |                       |           |              " << endl;
		cout << "                 /           \\          \\          /           |                       |           |              " << endl;
		cout << "                 |           |           \\        /            |-----------            |-----------|              " << endl;
		cout << "                 |           |            \\      /             |                       |      \\                  " << endl;
		cout << "                 \\          /              \\    /              |                       |       \\                 " << endl;
		cout << "                  \\        /                \\  /               |                       |        \\                " << endl;
		cout << "                    -------                  \\/                |-----------            |         \\               " << endl;
		setColor(END_COLOR);
		setXY(WINDOWS_X / 2 - 10, WINDOWS_Y / 2 - 1);
		cout << "僵尸吃掉了你的脑子！！！" << endl;
		setXY(WINDOWS_X / 2 - 4, WINDOWS_Y / 2);
		cout << "游戏结束" << endl;
		setXY(WINDOWS_X / 2 - 8, WINDOWS_Y / 2 + 1);
		cout << "你的最终得分是:" << this->store.getscore() << endl;
		setColor(NORMAL_COLOR);
		//setXY(0, WINDOWS_Y);
		//cout << "no ";
		system("pause");
}
void Game::refresh() {
	map.refresh();
	store.refresh();
}
void Game::shoveling() {

}
void Game::pausing(int tmp_status) {
	char ch;
	while (true) {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 32) {
				status = tmp_status;
				break;
			}
			else
				continue;
		}
	}

}
void Game::shopping() {
	char ch;
	//while (true) {
		if (_kbhit()) {
			closefocus(select_x, select_y);
			ch = _getch();
			switch (ch) {
			case '1':
				plant_type = SUNFLOWER;
				for (int i = 0;i < PLANT_TYPE;++i) {
					if (i == plant_type)
						store.plant[i].selected();
					else
						store.plant[i].unselected();
				}
				openfocus(select_x,select_y);
				break;
			case '2':
				plant_type = PEASHOOTER;
				for (int i = 0;i < PLANT_TYPE;++i) {
					if (i == plant_type)
						store.plant[i].selected();
					else
						store.plant[i].unselected();
				}
				openfocus(select_x, select_y);
				break;
			case 27:
				for (int i = 0;i < PLANT_TYPE;++i) {
					store.plant[i].unselected();
				}
				shopping_end = true;
				break;
			case 72:// up
				if (select_y > 0)select_y--;
				break;
			case 75:// left 
				if (select_x > 0)select_x--;
				break;
			case 77:// right
				if (select_x < MAP_NUM_X - 1)select_x++;
				break;
			case 80:// down
				if (select_y < MAP_NUM_Y - 1)select_y++;
				break;
			default:
				break;
			}
			refresh();
			openfocus(select_x, select_y);
			if (ch == 13) {
				map.grass_block[select_y][select_x].plant_a_plant((PLANT_NAME)plant_type,*this);
				closefocus(select_x, select_y);
				//break;
			}
			if (shopping_end) {
				status = PLAYING;
				closefocus(select_x, select_y);
			}

			//break;
		}
		
	//}
}
void Game::playing() {}
Game::~Game() {}