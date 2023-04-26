#pragma once

enum class ButtonType
{
    Game0,
    Game1,
    Game2,
    Game3,
    Pause,
    Result,
    GameOver,
};

/// <summary>
/// ボタン１つ分
/// </summary>
class Button {
private:
    float x; //横の場所
    float y; //縦の場所
    float w; //幅
    float h; //高さ
    bool onCursol = false;//場所
    //static Button instance_;
public:
    //static Button* instance() { return &instance_; }

    void init(ButtonType btnType, float x,float y,float w,float h); //ボタン生成
     
    bool position();//ボタン位置
     
    void render();//ボタン１つを描画

    ButtonType buttontype;
};

/// <summary>
/// 複数のボタンを管理
/// </summary>
class ButtonManager
{

public:
    static ButtonManager& Instance() {
        static ButtonManager instance;
        return instance;
    }

    void RemoveAll() {
        delete[] buttons;
        buttons = nullptr;
    }

public:
    Button* buttons;
};