#include "wall.h"
#ifndef SCENE_GAME_H
#define SCENE_GAME_H

class Game : public Scene
{
public:
    static Game* instance() { return &instance_; }

    void init();
    void deinit();
    void update();
    void render();

    
private:
    static Game instance_;
    Player player_;
    Wall wall_[Wall::WALL_MAX];

};
#endif