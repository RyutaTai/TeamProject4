#pragma once
class obj2d
{
public:
    //メンバ変数
    GameLib::Sprite* spr;
    VECTOR2 pos;
    VECTOR2 scale;
    VECTOR2 texPos;
    VECTOR2 texSize;
    VECTOR2 pivot;
    VECTOR2 speed;
    VECTOR4 color;
    VECTOR4 set_pos; //{左,上、右、下}

    bool exist; //存在しているか
    bool isHit; //ヒットしているか

    VECTOR4 tbl_color[4] = { {1,0,0,1},{0,0,1,1},{0,1,0,1},{1,1,0,1} };

    //メンバ関数
    virtual void init() {};
    virtual void deinit() {};
    virtual void update() {};
    virtual void render() {};
private:
};

