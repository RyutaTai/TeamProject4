#pragma once
class Stage
{
public:
    static const int WINDOW_W = 1280;                   // ウインドウの幅
    static const int WINDOW_H = 720;                    // ウインドウの高さ
    static const int CLIENT_W = 1280;                   // クライアント領域の幅
    static const int CLIENT_H = 720;                    // クライアント領域の高さ

               
    static const int CHIP_SIZE = 50;
    static const int LOOP_X = CLIENT_W / CHIP_SIZE + (CLIENT_W % CHIP_SIZE ? 2 : 1);
    static const int LOOP_Y = CLIENT_H / CHIP_SIZE + (CLIENT_H % CHIP_SIZE ? 2 : 1);

    static const int CHIP_NUM_X = 100;
    static const int CHIP_NUM_Y = 12;

    static constexpr float WIDTH = static_cast<float>(CHIP_NUM_X * CHIP_SIZE);  // マップの幅（ドット）
    static constexpr float HEIGHT = static_cast<float>(CHIP_NUM_Y * CHIP_SIZE); // マップの高さ（ドット）

    enum TR_ATTR
    {
        TR_NONE = -1,
        TR_GROUND = 0,

    };


private:
    VECTOR2 scroll;
    char terrain[CHIP_NUM_Y][CHIP_NUM_X];                   // 地形データ
public:
    void init();
    void update();
    void drawterrain();
private:
    void clear();
    void draw(char[][CHIP_NUM_X]); 
    bool loadMapData(const char[][CHIP_NUM_X], char[][CHIP_NUM_X]);
};

