#include "all.h"
Game2 Game2::instance_;

void Game2::init()
{
	Scene::init();
	
	ButtonType btnTypeArr[] =
	{
		ButtonType::Pause,
		ButtonType::Result,
		ButtonType::GameOver,
	};

	// ゲームセレクト用のボタンの位置とか
	float arr[][4] =
	{
		{100.0f,300.0f,200.0f,100.0f},
		{400.0f,300.0f,200.0f,100.0f},
		{100.0f,600.0f,200.0f,100.0f},
	};

	// ボタンの最大数分ボタンを作成
	ButtonManager::Instance().buttons = new Button[3];

	// ボタンのサイズを設定していく
	for (int i = 0; i < _countof(arr); ++i)
	{
		ButtonManager::Instance().buttons[i].init(btnTypeArr[i], arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
	}
}

void Game2::deinit()
{
	// ボタンを解放
	ButtonManager::Instance().RemoveAll();
}

void Game2::update()
{
	switch (state)
	{
	case 0:


		timer = 0;                                  // タイマーを初期化
		GameLib::setBlendMode(Blender::BS_ALPHA);   // 通常のアルファ処理
		state++;
		/*fallthrough*/
	case 1:
		ButtonManager::Instance().buttons[0].position();
		if (TRG(0) & PAD_START) {
			state++;
		}

		timer++;
	case 2:
		// ポーズの更新
		for (int i = 0; i < 3; ++i)
		{
			ButtonManager::Instance().buttons[i].position();
		}
		if (TRG(0) & PAD_START) {

			if (ButtonManager::Instance().buttons[0].position()) {
				state--;
			}
			if (ButtonManager::Instance().buttons[1].position()) {
				changeScene(Result::instance());
			}
			if (ButtonManager::Instance().buttons[2].position()) {
				changeScene(GameOver::instance());
			}
		}
		break;
	}
	timer++;
}

void Game2::render()
{
	clear(0.2f, 1.0f, 0.6f);
	if (state == 2) {
		clear(0.8f, 0.1f, 0.5f);
		for (int i = 0; i < 3; ++i)
		{
			ButtonManager::Instance().buttons[i].render();
		}
	}
}
