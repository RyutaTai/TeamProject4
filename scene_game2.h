#pragma once

class Game2 : public Scene
{
public:
    static Game2* instance() { return &instance_; }

    void init();
    void deinit();
    void update();
    void render();

private:
    static Game2 instance_;


};