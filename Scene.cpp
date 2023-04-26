#include "all.h"

Scene* Scene::execute()
{
    using namespace GameLib;

    // ����������
    audio_init();
    init();

    // �Q�[�����[�v
    while (GameLib::gameLoop(false))    // false��true�ɂ���ƃ^�C�g���o�[�Ƀt���[�����[�g�\��
    {
        // ���͏���
        input::update();

        // �X�V����
#ifdef USE_IMGUI
        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
#endif
        update();

        // �`�揈��
        render();
#ifdef USE_IMGUI
        ImGui::Render();
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
#endif

        // �f�o�b�O������̕`��
        debug::display(1, 1, 1, 1, 1);
        //debug::setString("GP2_02 SAMPLE");

        // ��ʃt���b�v
        GameLib::present(1, 0);

        // �I���`�F�b�N
        if (nextScene) break;
    }

    // �I������
    deinit();
    audio_deinit();

    return nextScene;	// ���̃V�[����Ԃ�
}

void SceneManager::execute(Scene* scene)
{
    using namespace GameLib;

    bool isFullScreen = false;	// �t���X�N���[���ɂ���Ȃ�true�ɕς���
                                //�iRelease���[�h�̂݁j

    // �Q�[�����C�u�����̏���������
    GameLib::init(L"Traveling Cube", SCREEN_W, SCREEN_H, isFullScreen);



#ifndef _DEBUG
    //ShowCursor(!isFullScreen);	// �t���X�N���[�����̓J�[�\��������
#endif

    // ���C�����[�v
    while (scene)
    {
        scene = scene->execute();
    }

    // �Q�[�����C�u�����̏I������
    GameLib::uninit();
}
