#include "all.h"

bool Judge::hit_check(obj2d* player, obj2d* wall)
{
    if (player->set_pos.z > wall->set_pos.x && player->set_pos.x <wall->set_pos.z)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Judge::color_check(obj2d* player, obj2d* wall)
{
    if (player->color.x != wall->color.x) return false;
    if (player->color.y != wall->color.y) return false;
    if (player->color.z != wall->color.z) return false;
    if (player->color.w != wall->color.w) return false;
    return true;
}


