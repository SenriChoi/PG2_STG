#include <Novice.h>
#include <math.h>
#include <Enemy.h>
#include<Player.h>
#include<ScreenChange.h>

const char kWindowTitle[] = "愛憎";




int distance(int x1, int y1, int x2, int y2) {
	int dis;
	dis = (int)sqrtf(float((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));

	return dis;
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Player* player = new Player(640, 600, 10, 32);
	Enemy* enemyA = new Enemy(300, 100, 6, 32);
	Enemy* enemyB = new Enemy(450, 200, 6, 32);
	ScreenChange* screenChange = new ScreenChange;


	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	int titleImage = Novice::LoadTexture("./images/title.png");
	int BGImage = Novice::LoadTexture("./images/BG.png");
	int gameOverImage = Novice::LoadTexture("./images/gameover.png");
	int playerImage = Novice::LoadTexture("./images/player.png");
	int bulletImage = Novice::LoadTexture("./images/player_bullet.png");
	int enemyImage = Novice::LoadTexture("./images/enemy.png");
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		if (screenChange->screenNum == 1) {
			player->Move(keys);
			player->checkCollision(enemyA);
			player->checkCollision(enemyB);
			enemyA->Update(keys);
			enemyB->Update(keys);

			player->checkBullet(enemyA);
			player->checkBullet(enemyB);
		}


		screenChange->Update(keys, preKeys, player, enemyA, enemyB);
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		/// 
		/// 
		screenChange->Draw(titleImage, BGImage, gameOverImage);
		if (screenChange->screenNum == 1) {
			player->Draw(playerImage, bulletImage);
			enemyA->Draw(enemyImage);
			enemyB->Draw(enemyImage);
		}
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}