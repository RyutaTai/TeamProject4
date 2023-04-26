#pragma once
class obj2d
{
public:
    //�����o�ϐ�
    GameLib::Sprite* spr;
    VECTOR2 pos;
    VECTOR2 scale;
    VECTOR2 texPos;
    VECTOR2 texSize;
    VECTOR2 pivot;
    VECTOR2 speed;
    VECTOR4 color;
    VECTOR4 set_pos; //{��,��A�E�A��}

    bool exist; //���݂��Ă��邩
    bool isHit; //�q�b�g���Ă��邩

    VECTOR4 tbl_color[4] = { {1,0,0,1},{0,0,1,1},{0,1,0,1},{1,1,0,1} };

    //�����o�֐�
    virtual void init() {};
    virtual void deinit() {};
    virtual void update() {};
    virtual void render() {};
private:
};

