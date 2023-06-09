#include "all.h"

GameSelect GameSelect::instance_;
using namespace primitive;

void GameSelect::init()
{
	Scene::init();

	// ゲームセレクト用のボタンのタイプ
	ButtonType btnTypeArr[] =
	{
		ButtonType::Game0,
		ButtonType::Game1,
		ButtonType::Game2,
		ButtonType::Game3,

		// ポーズ用のボタンタイプ
	};

	// ゲームセレクト用のボタンの位置とか
	float arr[][4] =
	{
		{100.0f,300.0f,200.0f,100.0f},
		{400.0f,300.0f,200.0f,100.0f},
		{100.0f,600.0f,200.0f,100.0f},
		{400.0f,600.0f,200.0f,100.0f},

	};

	// ボタンの最大数分ボタンを作成
	ButtonManager::Instance().buttons = new Button[4];

	// ボタンのサイズを設定していく
	for (int i = 0; i < _countof(arr); ++i)
	{
		ButtonManager::Instance().buttons[i].init(btnTypeArr[i], arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
	}




}

void GameSelect::deinit()
{
	// ボタンを解放
	ButtonManager::Instance().RemoveAll();
}

void GameSelect::update()
{
	switch (state)
	{
	case 0:


		timer = 0;                                  // タイマーを初期化
		GameLib::setBlendMode(Blender::BS_ALPHA);   // 通常のアルファ処理
		state++;
		/*fallthrough*/
	case 1:

		// ボタンを押したかどうかチェック
		for (int i = 0; i < 4; ++i)
		{
			ButtonManager::Instance().buttons[i].position();
			if (TRG(0) & PAD_TRG3) {
				if (ButtonManager::Instance().buttons[0].position())
					changeScene(Game::instance());
				if (ButtonManager::Instance().buttons[1].position())
					changeScene(Game1::instance());
				if (ButtonManager::Instance().buttons[2].position())
					changeScene(Game2::instance());
				if (ButtonManager::Instance().buttons[3].position())
					changeScene(Game3::instance());
			}
		}

#if 0
		Button::instance()->position();
		if (TRG(0) & PAD_START) {
			if (Button::instance()->position())
				changeScene(Game::instance());
		}
#endif

		
		
		break;


	}
	timer++;
}

void GameSelect::render()
{
	clear(1, 1, 0);

	// ボタンの描画
	for (int i = 0; i < 4; ++i)
	{
		ButtonManager::Instance().buttons[i].render();
	}

	
}

