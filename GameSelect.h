#pragma once
using namespace primitive;
class GameSelect : public Scene
{
 public:
    static GameSelect* instance() { return &instance_; }

    void init();
    void deinit();
    void update();
    void render();
   
#if 0
    struct button {
        float x = 0; //‰¡‚ÌêŠ
        float y = 0; //c‚ÌêŠ
        float w = 0; //•
        float h = 0; //‚‚³

        bool onCursol = false;
    };

    enum ButtonType
    {
        Game0,
        Game1,
        Game2,
        Game3,
        ButtonType_Max
    };

    button button[ButtonType_Max];
#endif

private:
    static GameSelect instance_;
};