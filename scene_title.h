#ifndef SCENE_TITLE_H
#define SCENE_TITLE_H

using namespace GameLib;

class Title : public Scene
{
public:

private:
    Sprite* spr_title;
    static Title instance_;



public:
    static Title* instance() { return &instance_; }

    void init();
    void deinit();
    void update();
    void render();

};

#endif