#include "Novice.h"
#include "ScreenChange.h"




void ScreenChange::Update(char*keys, char*preKeys, Player *player, Enemy* enemyA, Enemy* enemyB) {


	if(keys[DIK_RETURN]&&!preKeys[DIK_RETURN]){
		player->hp_ = 100;
		player->SetPosition(640, 600);
		player->isAlive = 1;
		player->count = 0;
		enemyA->hp_ = 100;
		enemyA->SetPosition(300, 100);
		enemyA->isAlive = 1;
		enemyA->SetSpeedX(6);
		enemyA->count = 0;
		enemyB->hp_ = 100;
		enemyB->SetPosition(450, 200);
		enemyB->isAlive = 1;
		enemyB->count = 0;
		enemyB->SetSpeedX(6);

		if (screenNum == 0) {
			screenNum = 1;
		}
		else if (screenNum == 1|| screenNum==2) {
			screenNum = 0;

		}

	}

	if (screenNum == 1&&player->hp_<=0 ) {
		screenNum = 2;
	}

}

void ScreenChange::Draw(int titleImage, int BGImage, int gameoverImage) {

	(screenNum == 0) ? Novice::DrawSpriteRect(0, 0, 0, 0, 1280, 720, titleImage, 1, 1, 0.0f, WHITE) :
	(screenNum == 1) ? Novice::DrawSpriteRect(0, 0, 0, 0, 1280, 720, BGImage, 1, 1, 0.0f, WHITE):
					   Novice::DrawSpriteRect(0, 0, 0, 0, 1280, 720, gameoverImage, 1, 1, 0.0f, WHITE);
}

