#include "Novice.h"
#include "Player.h"
#include <math.h>
#include <ScreenChange.h>



int dis(int x1, int y1, int x2, int y2) {
	int dis;
	dis = (int)sqrtf(float((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));

	return dis;
}



Player::Player(int posX, int posY, int speed, int radius) {
	posX_ = posX;
	posY_ = posY;
	speed_ = speed;
	radius_ = radius;
	isAlive = 1;
	cooldown = 0;
	hp_ = 100;
	count = 0;
}

void Player::SetPosition(int x, int y) {

	posX_ = x;
	posY_ = y;
}

void Player::SetSpeed(int speed) {

	speed_ = speed;

}

void Player::SetRadius(int r) {

	radius_ = r;
}



void Player::Move(char* keys) {
	(keys[DIK_W]) ? posY_ -= speed_ : (keys[DIK_S]) ? posY_ += speed_ : 0;
	(keys[DIK_A]) ? posX_ -= speed_ : (keys[DIK_D]) ? posX_ += speed_ : 0;

	(cooldown > 0)? cooldown--: cooldown = 0;


	if(cooldown <= 0){
		for (int i = 0; i < 5; i++) {
	if (keys[DIK_SPACE]) {
		if (bullet[i].isShot == 0) {
			bullet[i].x = posX_;
			bullet[i].y = posY_;
			cooldown = 10;
			bullet[i].isShot = 1;
			break;
		}
			}
		}

	}


	for (int i = 0; i < 5; i++) {

		bullet[i].Update();
	}
}


void Player::checkCollision( Enemy* enemy) {

	(count > 0) ? count-- : count = 0;
	if(enemy->isAlive==1){
	if ((dis(posX_, posY_, enemy->GetPosX(), enemy->GetPosY()) < enemy->GetRadius() + radius_)&&count==0)
	{
		hp_ -= 30;
		(hp_ <= 0) ? isAlive = 0 : isAlive = 1;

		count = 40;
	}
	}
}


void Player::checkBullet(Enemy* enemy) {


	if (enemy->isAlive&& enemy->count==0) {
		for (int i = 0; i < 5; i++) {
			if (bullet[i].isShot) {
				if ((dis(bullet[i].x, bullet[i].y, enemy->GetPosX(), enemy->GetPosY()) < enemy->GetRadius() + bullet[i].r)) {
					enemy->hp_ -=30;
					enemy->count =40;
					bullet[i].isShot = 0;
				}
			}
		}
	}
};

void Player::Draw(int playerImage, int bulletImage) {
	
	for (int i = 0; i < 5; i++) {
		bullet[i].Draw(bulletImage);
	}
	(count==0)? Novice::DrawSprite(posX_ - 32, posY_ - 32, playerImage, 1, 1, 0, WHITE):
				Novice::DrawSprite(posX_ - 32, posY_ - 32, playerImage, 1, 1, 0, RED);;

}