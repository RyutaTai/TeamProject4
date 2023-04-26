#pragma once

class Wall:public obj2d
{
public:
    void init(obj2d* obj);
    void deinit(obj2d* obj);
    void update(obj2d* obj);
    void render(obj2d* obj);
    void spawn(obj2d* obj);

    int getWall_count();

    static const int WALL_MAX = 5;
private:
    int state;
    int move_speed;

};

