#include "Enemy.h"
#include "player.h"
#include <Novice.h>

Enemy::Enemy(int posX, int posY, int speed, int radius) {
	posX_ = posX;
	posY_ = posY;
	speed_ = speed;
	radius_= radius;
	isAlive = 1;
	hp_ = 100;
	count = 0;
	color = 0xFFFFFFFF;
}


void Enemy::Update(char*keys) {

	if (count > 0) {

		count--;
		color = RED;
	}
	else {
		count = 0;
		color = 0xFFFFFFFF;
	}

	if (isAlive ==1){
		posX_ += speed_;
	}

	if (posX_ - radius_<= 0 || posX_ + radius_ >= 1280) {
		speed_ *= -1;


	}
	if (keys[DIK_R]){
		isAlive = 1;
		hp_ = 100;
	}
	
	if (hp_ <= 0) {
		isAlive = 0;
	}
}

void Enemy::Draw(int enemyImage) {
	if (hp_>=50) {
		Novice::DrawSpriteRect(posX_-32, posY_-32, 0, 0, 64, 64, enemyImage, 0.3333f, 1, 0.0f, color);
	}
	else if (hp_ >= 20 && hp_ < 50) {
		Novice::DrawSpriteRect(posX_ - 32, posY_ - 32,64, 0, 64, 64, enemyImage, 0.3333f, 1, 0.0f, color);
	}
	else {
		Novice::DrawSpriteRect(posX_ - 32, posY_ - 32, 128, 0, 64, 64, enemyImage, 0.3333f, 1, 0.0f, color);

	}
}


void Enemy::SetPosition(int x, int y) {

	posX_ = x;
	posY_ = y;
}

void Enemy::SetSpeedX(int speed) {

	speed_ = speed;

}

void Enemy::SetRadius(int r) {

	radius_ = r;
}

Enemy::~Enemy() {


}