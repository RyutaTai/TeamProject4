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
/// �{�^���P��
/// </summary>
class Button {
private:
    float x; //���̏ꏊ
    float y; //�c�̏ꏊ
    float w; //��
    float h; //����
    bool onCursol = false;//�ꏊ
    //static Button instance_;
public:
    //static Button* instance() { return &instance_; }

    void init(ButtonType btnType, float x,float y,float w,float h); //�{�^������
     
    bool position();//�{�^���ʒu
     
    void render();//�{�^���P��`��

    ButtonType buttontype;
};

/// <summary>
/// �����̃{�^�����Ǘ�
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