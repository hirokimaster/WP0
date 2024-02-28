#include "Framework.h"

void Framework::Initialize()
{
	// COMの初期化
	CoInitializeEx(0, COINIT_MULTITHREADED);

	win_ = WinApp::GetInstance();
	dxCommon_ = DirectXCommon::GetInstance();
	audio_ = Audio::GetInstance();

	// ウィンドウの作成
	win_->CreateGameWindow(L"WP0_Demo");
	// DirectX初期化
	dxCommon_->Initialize(win_);
	Input::Initialize();
	audio_->Initialize();
	GraphicsPipeline::Initialize();

	// ImGuiの初期化
	imguiManager_ = ImGuiManager::GetInstance();
	imguiManager_->Initialize(win_, dxCommon_);

	Sprite::StaticInitialize();

	gameManager_ = GameManager::GetInstance();

}

void Framework::Finalize()
{
	//gameManager_->Finalize();
	imguiManager_->Finalize();
	// ゲームウィンドウ破棄
	win_->TerminateGameWindow();
}

void Framework::Update()
{
	Sprite::StaticUpdate();
	gameManager_->Update();
}

void Framework::PostProcessDraw()
{
	gameManager_->PostProcessDraw();
}

void Framework::Run()
{
	Initialize();

	// メインループ
	while (true) {

		// メッセージ処理
		if (win_->ProcessMessage()) {
			break;
		}

		// input
		Input::Update();
		//imgui受付開始
		imguiManager_->Begin();

		Update();

		PostProcessDraw();

		// 描画前処理
		dxCommon_->PreDraw();

		Draw();

		imguiManager_->End();

		imguiManager_->Draw();
		// 描画後処理
		dxCommon_->PostDraw();

	}

	Finalize();
}