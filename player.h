
#pragma once
class Player : public obj2d
{
public:
    Player();
    ~Player();

    void init(obj2d* obj);
    void deinit(obj2d* obj);
    void update(obj2d* obj);
    void render(obj2d* obj);

    int getHp();

    //hpå∏è≠
    void decHp(int n);


private:
    void color_change(obj2d* obj);
    void moveY(obj2d* obj);
    void moveX(obj2d* obj);

    obj2d Ghost[5];


    bool onGround = false;
    int jumpTimer;
    int state = 0;
    int hp;
    int color_count;
};
