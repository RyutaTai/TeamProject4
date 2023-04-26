#include "all.h"

Scene* Scene::execute()
{
    using namespace GameLib;

    // 初期化処理
    audio_init();
    init();

    // ゲームループ
    while (GameLib::gameLoop(false))    // falseをtrueにするとタイトルバーにフレームレート表示
    {
        // 入力処理
        input::update();

        // 更新処理
#ifdef USE_IMGUI
        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
#endif
        update();

        // 描画処理
        render();
#ifdef USE_IMGUI
        ImGui::Render();
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
#endif

        // デバッグ文字列の描画
        debug::display(1, 1, 1, 1, 1);
        //debug::setString("GP2_02 SAMPLE");

        // 画面フリップ
        GameLib::present(1, 0);

        // 終了チェック
        if (nextScene) break;
    }

    // 終了処理
    deinit();
    audio_deinit();

    return nextScene;	// 次のシーンを返す
}

void SceneManager::execute(Scene* scene)
{
    using namespace GameLib;

    bool isFullScreen = false;	// フルスクリーンにするならtrueに変える
                                //（Releaseモードのみ）

    // ゲームライブラリの初期化処理
    GameLib::init(L"Traveling Cube", SCREEN_W, SCREEN_H, isFullScreen);



#ifndef _DEBUG
    //ShowCursor(!isFullScreen);	// フルスクリーン時はカーソルを消す
#endif

    // メインループ
    while (scene)
    {
        scene = scene->execute();
    }

    // ゲームライブラリの終了処理
    GameLib::uninit();
}
