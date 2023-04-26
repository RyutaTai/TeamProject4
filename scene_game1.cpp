#include "all.h"

Game1 Game1::instance_;

void Game1::init()
{
	Scene::init();

	Scene::init();
	ButtonType btnTypeArr[] =
	{
		ButtonType::Pause,
		ButtonType::Result,
		ButtonType::GameOver,
	};

	// �Q�[���Z���N�g�p�̃{�^���̈ʒu�Ƃ�
	float arr[][4] =
	{
		{100.0f,300.0f,200.0f,100.0f},
		{400.0f,300.0f,200.0f,100.0f},
	};

	// �{�^���̍ő吔���{�^�����쐬
	ButtonManager::Instance().buttons = new Button[3];

	// �{�^���̃T�C�Y��ݒ肵�Ă���
	for (int i = 0; i < 2; ++i)
	{
		ButtonManager::Instance().buttons[i].init(btnTypeArr[i], arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
	}
}

void Game1::deinit()
{
	// �{�^�������
	ButtonManager::Instance().RemoveAll();
}

void Game1::update()
{
	switch (state)
	{
	case 0:


		timer = 0;                                  // �^�C�}�[��������
		GameLib::setBlendMode(Blender::BS_ALPHA);   // �ʏ�̃A���t�@����
		state++;
		/*fallthrough*/
	case 1:
		ButtonManager::Instance().buttons[0].position();
		if (TRG(0) & PAD_START) {
			state++;
		}

		timer++;
	case 2:
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

void Game1::render()
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