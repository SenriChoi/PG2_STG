#pragma once


class Enemy
{

public:

	Enemy(int posX, int posY, int speed, int radius);


	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	int GetSpeed() { return speed_; };
	int GetRadius() { return radius_; };

	void SetPosition(int x, int y);
	void SetSpeedX(int speedX);
	void SetRadius(int r);


public:
	void Update(char *key);
	void Draw(int enemyImage);
	 int isAlive;
	 int hp_;
	 int count;
	~Enemy();



private:
	int posX_;
	int posY_;
	int speed_;
	int radius_;
	unsigned int color;
};

