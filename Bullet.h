#pragma once
class Bullet
{

public:
	int x;
	int y;
	int r;
	int speed;
	int isShot;
	Bullet();
	void Draw(int bulletImage);
	void Update();

};

