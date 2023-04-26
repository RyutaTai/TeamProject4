#pragma once

class GameOver : public Scene
{
private:

    static GameOver instance_;

public:
    static GameOver* instance() { return &instance_; }

    void init();
    void deinit();
    void update();
    void render();


};