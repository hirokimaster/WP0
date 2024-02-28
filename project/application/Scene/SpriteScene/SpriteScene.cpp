#include "SpriteScene.h"

void SpriteScene::Initialize()
{
	texHandleUV_ = TextureManager::Load("resources/uvChecker.png");
	texHandleMonsterBall_ = TextureManager::Load("resources/monsterBall.png");
	spriteUV_.reset(Sprite::Create(texHandleUV_));
	spriteMonsterBall_.reset(Sprite::Create(texHandleMonsterBall_, { 512.0f,0 }));
}

void SpriteScene::Update()
{
#ifdef _DEBUG

	ImGui::Begin("SceneChang");
	ImGui::Text("SPACE KEY");
	ImGui::End();

#endif // _DEBUG

	if (Input::GetInstance()->PressedKey(DIK_SPACE)) {
		GameManager::GetInstance()->ChangeScene("SPRITESCENE");
	}
}

void SpriteScene::Draw()
{
	spriteUV_->Draw();
	spriteMonsterBall_->Draw();
}
