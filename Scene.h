#ifndef SCENE_H
#define SCENE_H
using namespace GameLib;
using namespace input;
class Scene
{
protected:
    int state;
    int timer;
    int count;
 
    Scene* nextScene;   // 次のシーン
private:
public:

    Scene* execute();   // 実行処理

    virtual void init()
    { // 初期化処理
        state = 0;
        timer = 0;
        nextScene = nullptr;
    };
    virtual void deinit() 
    {
      

    };   // 終了処理
    virtual void update() {};   // 更新処理
    virtual void render() {};   // 描画処理

    void changeScene(Scene* scene) { nextScene = scene; }   // シーン変更処理
    Scene* getScene() const { return nextScene; }           // nextSceneのゲッター
};

class SceneManager
{
public:
    void execute(Scene*);  // 実行処理
};

#endif
