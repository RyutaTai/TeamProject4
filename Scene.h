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
 
    Scene* nextScene;   // ���̃V�[��
private:
public:

    Scene* execute();   // ���s����

    virtual void init()
    { // ����������
        state = 0;
        timer = 0;
        nextScene = nullptr;
    };
    virtual void deinit() 
    {
      

    };   // �I������
    virtual void update() {};   // �X�V����
    virtual void render() {};   // �`�揈��

    void changeScene(Scene* scene) { nextScene = scene; }   // �V�[���ύX����
    Scene* getScene() const { return nextScene; }           // nextScene�̃Q�b�^�[
};

class SceneManager
{
public:
    void execute(Scene*);  // ���s����
};

#endif
