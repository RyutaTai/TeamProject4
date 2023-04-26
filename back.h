#pragma once
class Back : public obj2d
{
public:
    Back();
    ~Back();
    void init();
    void deinit();
    void update();
    void render();
   
private:
    static const int BACK_MAX = 2;
    int state;
    GameLib::Sprite* spr_back;
    obj2d back[BACK_MAX];

};

