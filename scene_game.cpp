#include"all.h"

Game Game::instance_;

Player player;
Wall wall;
Judge judge;
UI ui;
Back back;



void Game::init()
{
	Scene::init();

	back.init();
	ui.init();
}

void Game::deinit()
{
	back.deinit();
	player.deinit(&player_);
	for (int i = 0; i < wall.getWall_count(); i++)
	{
		wall.deinit(&wall_[i]);
	}
	ui.deinit();
}

void Game::update()
{
	switch (state)
	{
	case 0:


		player.init(&player_);
		for (int i = 0; i < wall.getWall_count(); i++)
		{
			wall.init(&wall_[i]);
		}

		state++;
		/*fallthrough*/
	case 1:
		debug::setString("count %d", count);
		//debug::setString("player pos.x%f", player_.pos.x);
		//debug::setString("player set_pos.x%f", player_.set_pos.x);
		//debug::setString("player set_pos.y%f", player_.set_pos.y);
		//debug::setString("wall set_pos.x%f", wall_[0].set_pos.x);
		//debug::setString("wall set_pos.w%f", wall_[0].set_pos.w);
		//debug::setString("");
		debug::setString("player hp %d",player.getHp());
		
		//debug::setString("back0 %f", back[0].pos.x);
		//debug::setString("back1 %f", back[1].pos.x);
		back.update();
		player.update(&player_);
		ui.update();


		if (timer % 100 == 0 && timer != 0) { wall.spawn(&wall_[count++]); }
		if (count >= wall.getWall_count()) { count = 0; }
		for (int i = 0; i < wall.getWall_count(); i++)
		{
			if (wall_[i].exist == true)
				wall.update(&wall_[i]);
			{
				if (judge.hit_check(&player_, &wall_[i]))
				{

					//debug::setString("wall[%d] Hit", i);
					if (!judge.color_check(&player_, &wall_[i]) && !wall_[i].isHit)
					{
						//debug::setString("damage Hit" );
						wall_[i].isHit = true;
						ui.setDamageFlag(true);
						player.decHp(-1);
					}
					else ui.CalcScore();
				}
				else
				{
					wall_[i].isHit = false;
				}
				if (wall_[i].set_pos.z < 0)
				{
					wall_[i].exist = false;
					wall_[i].pos = { SCREEN_W, SCREEN_H / 2 };
				}
			}
		}

		

		break;
	}
	timer++;
}
void Game::render()
{
	clear(0, 0, 0);
	back.render();
	player.render(&player_);
	//primitive::rect(0, 60, 1280, 600, 0, 0, 0, 0, 0, 0, 1);//ƒQ[ƒ€‚Ì•‚¢”wŒi
	for (int i = 0; i < wall.getWall_count(); i++)
	{
		wall.render(&wall_[i]);
	}
	ui.render(3,&player_);
	//primitive::circle(player_.set_pos.x, player_.set_pos.y, 3,1,1,0,1,1,1,1);
	//primitive::circle(player_.pos.x, player_.pos.y, 3,1,1,0,0,0,0,1);
}


