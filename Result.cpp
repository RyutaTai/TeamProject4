#include "all.h"

Result Result::instance_;

void Result::init()
{
	Scene::init();
	ButtonType btnTypeArr[] =
	{
		ButtonType::Game0,
		ButtonType::Game1,
	};

	// ゲームセレクト用のボタンの位置とか
	float arr[][4] =
	{
		{100.0f,300.0f,200.0f,100.0f},
		{400.0f,300.0f,200.0f,100.0f},
	};
	// ボタンの配列を作る
	ButtonManager::Instance().buttons = new Button[2];
	// TODO: ボタンの位置を設定（ボタンタイプを後で修正）
	ButtonManager::Instance().buttons[0].init(ButtonType::Game0, 100, 300, 200, 100);

	for (int i = 0; i < 2; ++i)
	{
		ButtonManager::Instance().buttons[i].init(btnTypeArr[i], arr[i][0], arr[i][1], arr[i][2], arr[i][3]);

		
	}
}

void Result::deinit()
{
	ButtonManager::Instance().RemoveAll();
}

void Result::update()
{
	switch (state)
	{
	case 0:
		
		
		timer = 0;                                  // タイマーを初期化
		GameLib::setBlendMode(Blender::BS_ALPHA);   // 通常のアルファ処理
		state++;
		/*fallthrough*/
	case 1:
		for (int i = 0; i < 2; ++i)
		{
			ButtonManager::Instance().buttons[i].position();
			if (TRG(0) & PAD_START) {
				if (ButtonManager::Instance().buttons[0].position())
					changeScene(GameSelect::instance());
				if (ButtonManager::Instance().buttons[1].position())
					changeScene(Game::instance());
			}
		}

		break;
	}
	timer++;
}

void Result::render()
{
	clear(0.5f, 0.4f, 0);
	// ボタンの描画
	for (int i = 0; i < 2; ++i)
	{
		ButtonManager::Instance().buttons[i].render();
	}
}
