#include "SpriteScene.h"

void SpriteScene::Initialize()
{
	texHandleUV_ = TextureManager::Load("resources/uvChecker.png");
	texHandleCircle_ = TextureManager::Load("resources/circle.png");
	spriteUV_.reset(Sprite::Create(texHandleUV_));
	spriteCircle_.reset(Sprite::Create(texHandleCircle_, { 550.0f,0 }));
}

void SpriteScene::Update()
{
#ifdef _DEBUG

	ImGui::Begin("SceneChang");
	ImGui::Text("SPACE KEY");
	ImGui::End();

#endif // _DEBUG

	if (Input::GetInstance()->PressedKey(DIK_SPACE)) {
		GameManager::GetInstance()->ChangeScene("MODELSCENE");
	}
}

void SpriteScene::Draw()
{
	spriteUV_->Draw();
	spriteCircle_->Draw();
}
