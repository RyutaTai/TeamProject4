#pragma once

class Game1 : public Scene
{
public:
    static Game1 * instance() { return &instance_; }

    void init();
    void deinit();
    void update();
    void render();

private:
    static Game1 instance_;


};