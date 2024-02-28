#pragma once
#include "application/Scene/IScene/IScene.h"
#include "engine/Sprite/Sprite.h"
#include "engine/Input/Input.h"
#include "engine/PostProcess/PostProcess.h"
#include "application/GameManager/GameManager.h"
#include "engine/Utility/ImGuiManager/ImGuiManager.h"

class SpriteScene  : public IScene{
public:

	void Initialize()override;

	void Update()override;

	void Draw()override;

private:
	uint32_t texHandleUV_ = 0;
	uint32_t texHandleMonsterBall_ = 0;
	std::unique_ptr<Sprite> spriteUV_ = nullptr;
	std::unique_ptr<Sprite> spriteMonsterBall_ = nullptr;

};

