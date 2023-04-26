#include"all.h"

Title Title::instance_;



void Title::init()
{
	Scene::init();

}

void Title::deinit()
{
	safe_delete(spr_title);
}

void Title::update()
{
	switch (state)
	{
	case 0:
		spr_title = sprite_load(L"./Data/Images/title.png");
		state++;
		setBlendMode(Blender::BS_ALPHA);

		/*fallthrough*/
	case 1:
		if (TRG(0)& PAD_START || TRG(0) & PAD_TRG3)
		{
			changeScene(GameSelect::instance());
		}

		break;
	}

	timer++;
}

void Title::render()
{
	clear(1, 1, 1);
	sprite_render(spr_title, 0, 0,1.0f,1.0f,0,0,1280,720);
	if (timer / 5 % 4) 
	{
	text_out(1, "Push Enter Key", 400, 600);
	}
}
