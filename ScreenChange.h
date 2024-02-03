#pragma once
#include "Player.h"
#include "Enemy.h"

class ScreenChange
{



public:
	int screenNum=0;
	int loadImage = 0;
	void Update(char* keys, char* preKeys,Player* player,Enemy*enemyA,Enemy*enemyB); 
	void Draw(int titleImage, int BGImage,int gameoverImage);

};

