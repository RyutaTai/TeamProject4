#pragma once

class Game3 : public Scene
{
public:
    static Game3* instance() { return &instance_; }

    void init();
    void deinit();
    void update();
    void render();

private:
    static Game3 instance_;


};