#include "all.h"

void Wall::init(obj2d* obj)
{
    obj->pos = { SCREEN_W,SCREEN_H/2 };
    obj->texSize = { 10,200 };
    obj->set_pos = { pos.x ,pos.y,pos.x + texSize.x,pos.y + texSize.y };
    obj->pivot = obj->texSize / 2;
    obj->color = { 1,1,1,1 };
}

void Wall::deinit(obj2d* obj)
{
}

void Wall::update(obj2d* obj)
{
    switch (state)
    {
    case 0:
        move_speed = 4;
        state++;
        /*fallthrough*/
    case 1:
        obj->pos.x -= move_speed;


        obj->set_pos = obj->set_pos = { obj->pos.x - obj->texSize.x / 2,obj->pos.y - obj->texSize.y / 2,obj->pos.x + obj->texSize.x / 2,obj->pos.y + obj->texSize.y / 2 };


        break;
    };
}

void Wall::render(obj2d* obj)
{
    if (obj->exist == 1)
    {
        primitive::rect(obj->pos.x, obj->pos.y, obj->texSize.x, obj->texSize.y, obj->pivot.x, obj->pivot.y, 0, obj->color.x, obj->color.y, obj->color.z, obj->color.w);
    }
}

void Wall::spawn(obj2d*obj)
{
    obj->color = tbl_color[rand() % 4];
    obj->exist = true;
}

int Wall::getWall_count()
{
    return WALL_MAX;
}
