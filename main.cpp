
#include "game.h"
#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

int main() {
	//char mu[250] = "music.wma";
	//system(mu);
	//Sleep(2000);
	//system("pause");
	Game mygame;
	mygame.init();
	mygame.loop();

	return 0;
}