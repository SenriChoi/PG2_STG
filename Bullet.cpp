#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet() {
	x =-100;
	y=-100;
	r=10;
	speed=10;
	isShot =0;
}


void Bullet::Update() {
	if (isShot == 1) {
		y -= speed;
	}

	if (y<0-r) {
		isShot = 0;
	}
}

void Bullet::Draw(int bulletImage) {
	if (isShot == 1) {
		Novice::DrawSprite(x - 16, y - 16, bulletImage, 1, 1, 0, WHITE);
	}
}
