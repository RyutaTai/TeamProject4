#include "all.h"

Player::Player() : hp(3), color_count(0)
{
}

Player::~Player()
{
}

void Player::init(obj2d* obj)
{
    obj->pos = { SCREEN_W /6,SCREEN_H / 2 };
    obj->texSize = { 50,50 };
    obj->set_pos = { obj->pos.x,obj->pos.y,obj->pos.x + obj->texSize.x,obj->pos.y + obj->texSize.y };
    obj->pivot = obj->texSize / 2;
    obj->color = { 1,1,1,1 };
}
void Player::deinit(obj2d* obj)
{

}
void Player::update(obj2d* obj)
{


    switch (state)
    {
    case 0:
        for (int i = 0; i < 5; i++)
        {
            Ghost[i] = {};
            Ghost[i].texSize = { 50,50 };
            Ghost[i].pivot = Ghost[i].texSize / 2;
            Ghost[i].color.w = 0.1f;
        }
        state++;
        /*fallthrough*/
    case 1:
        for (int i = 4; i > 0; i--)
        {
            Ghost[i].pos = Ghost[i - 1].pos;
        }
        Ghost[0].pos = obj->pos;

        moveY(obj);
        moveX(obj);


        obj->set_pos = obj->set_pos = { obj->pos.x - obj->texSize.x / 2,obj->pos.y - obj->texSize.y / 2,obj->pos.x + obj->texSize.x / 2,obj->pos.y + obj->texSize.y / 2 };
        
        color_change(obj);
        break;
    }
}
void Player::render(obj2d* obj)
{
    primitive::rect(Ghost[0].pos.x, Ghost[0].pos.y, Ghost[0].texSize.x, Ghost[0].texSize.y, Ghost[0].pivot.x, Ghost[0].pivot.y,0,obj->color.x, obj->color.y, obj->color.z,Ghost[0].color.w);
    primitive::rect(Ghost[1].pos.x, Ghost[1].pos.y, Ghost[1].texSize.x, Ghost[1].texSize.y, Ghost[1].pivot.x, Ghost[1].pivot.y,0, obj->color.x, obj->color.y, obj->color.z,Ghost[1].color.w);
    primitive::rect(Ghost[2].pos.x, Ghost[2].pos.y, Ghost[2].texSize.x, Ghost[2].texSize.y, Ghost[2].pivot.x, Ghost[2].pivot.y,0, obj->color.x, obj->color.y, obj->color.z,Ghost[2].color.w);
    primitive::rect(Ghost[3].pos.x, Ghost[3].pos.y, Ghost[3].texSize.x, Ghost[3].texSize.y, Ghost[3].pivot.x, Ghost[3].pivot.y,0, obj->color.x, obj->color.y, obj->color.z,Ghost[3].color.w);
    primitive::rect(Ghost[4].pos.x, Ghost[4].pos.y, Ghost[4].texSize.x, Ghost[4].texSize.y, Ghost[4].pivot.x, Ghost[4].pivot.y,0, obj->color.x, obj->color.y, obj->color.z,Ghost[4].color.w);
    primitive::rect(obj->pos.x,obj->pos.y,obj->texSize.x,obj->texSize.y,obj->pivot.x,obj->pivot.y, 0, obj->color.x, obj->color.y, obj->color.z,obj->color.w);
}
int Player::getHp()
{
    return hp;
}
void Player::decHp(int n)
{
    hp += n;
}


void Player::color_change(obj2d* obj)
{
 /*   if (GetKeyState('F')<0)
    {
        obj->color = tbl_color[0];
    }
    if (GetKeyState('J') < 0)
    {
        obj->color = tbl_color[1];
    }
    if (GetKeyState('D') < 0)
    {
        obj->color = tbl_color[2];
    }
    if (GetKeyState('K') < 0)
    {
        obj->color = tbl_color[3];
    }*/
    if (TRG(0) & PAD_TRG3)
    {
        color_count++;
    }
    obj->color = tbl_color[color_count % 4];
}

void Player::moveY(obj2d* obj)
{
    const int JUMP_TIMER = 15;
    const float KASOKU = 1.0f;
    const float SPEED_JUMP_Y = -8.0f;
    const float SPEED_MAX_Y = 16.0f;   

    onGround = false;

    obj->speed.y += KASOKU;
    obj->speed.y = (std::min)(obj->speed.y, SPEED_MAX_Y);
    obj->pos.y += obj->speed.y;

    //地面判定
    if (obj->pos.y + obj->texSize.y / 2 > 460)
    {
        obj->pos.y = 460 - obj->texSize.y / 2;
        onGround = true;
    }

    //ジャンプ入力
    if (TRG(0) & PAD_TRG1 && onGround == true)
    {
        jumpTimer = JUMP_TIMER;
    }

    //ジャンプ中
    if (jumpTimer > 0)
    {
        if (STATE(0) & PAD_TRG1)//押し続けているとき
        {
            obj->speed.y = SPEED_JUMP_Y;
            jumpTimer--;
        }
        else
        {
            jumpTimer = 0;
        }
    }
}

void Player::moveX(obj2d* obj)
{
    const int SPEED_X = 4;

    if (STATE(0) & PAD_LEFT)
    {
        obj->pos.x -= SPEED_X;
    }
    if (STATE(0) & PAD_RIGHT)
    {
        obj->pos.x += SPEED_X;
    }
}
