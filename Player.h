#pragma once
#include "Bullet.h"
#include "Enemy.h"
class Player
{
public:

	Player(int posX, int posY, int speed, int radius);


	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	int GetSpeed() { return speed_; };
	int GetRadius() { return radius_; };

	void SetPosition(int x, int y);
	void SetSpeed(int speed);
	void SetRadius(int r);
	
	Bullet bullet[5];
	int cooldown;
	int hp_=100;
	int count;
	int isAlive;
public:
	void Draw(int playerImage,int bulletImage);
	void Move(char* keys);
	void checkCollision(Enemy* enemy);
	void checkBullet(Enemy* enemy);

private:
	int posX_;
	int posY_;
	int speed_;
	int radius_;


};