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

	// �Q�[���Z���N�g�p�̃{�^���̈ʒu�Ƃ�
	float arr[][4] =
	{
		{100.0f,300.0f,200.0f,100.0f},
		{400.0f,300.0f,200.0f,100.0f},
	};
	// �{�^���̔z������
	ButtonManager::Instance().buttons = new Button[2];
	// TODO: �{�^���̈ʒu��ݒ�i�{�^���^�C�v����ŏC���j
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
		
		
		timer = 0;                                  // �^�C�}�[��������
		GameLib::setBlendMode(Blender::BS_ALPHA);   // �ʏ�̃A���t�@����
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
	// �{�^���̕`��
	for (int i = 0; i < 2; ++i)
	{
		ButtonManager::Instance().buttons[i].render();
	}
}
