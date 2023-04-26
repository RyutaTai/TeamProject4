#include "all.h"

Back::Back() :state(0) ,spr_back(nullptr)
{
	
}

Back::~Back()
{
}

void Back::init()
{
	spr_back = sprite_load(L"./Data/Images/Back2.png");
	for (int i = 0; i < 2; i++)
	{
		back[i] = {};
	}
	back[0].pos = { 0, 0 };
	back[1].pos = { 1280, 0 };
	back[0].scale = back[1].scale = { 1,1 };
	back[0].texPos = back[1].texPos = { 0,0 };
	back[0].texSize = back[1].texSize = { 1280,720 };
	back[0].pivot = back[1].pivot = { 0,0 };
}

void Back::deinit()
{
	safe_delete(spr_back);

}

void Back::update()
{
	switch (state)
	{
	case 0:

		state++;
		/*fallthrough*/
	case 1:

		for (int i = 0; i < BACK_MAX; i++)
		{
			back[i].pos.x -= 2;
			if (back[i].pos.x + back[i].texSize.x < 0)
			{
				back[i].pos.x = 1280 - 2;
			}
		}
		break;
	}
}

void Back::render()
{
	sprite_render(spr_back, back[0].pos.x, back[0].pos.y, back[0].scale.x, back[0].scale.y, back[0].texPos.x, back[0].texPos.y, back[0].texSize.x, back[0].texSize.y);
	sprite_render(spr_back, back[1].pos.x, back[1].pos.y, back[1].scale.x, back[1].scale.y, back[1].texPos.x, back[1].texPos.y, back[1].texSize.x, back[1].texSize.y);

}
