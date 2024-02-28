#pragma once
#include "application/Scene/IScene/IScene.h"
#include "engine/Sprite/Sprite.h"
#include "engine/Input/Input.h"
#include "engine/PostProcess/PostProcess.h"
#include "engine/ModelManager/ModelManager.h"
#include "engine/ParticleSystem/ParticleSystem.h"
#include "application/GameManager/GameManager.h"

class ModelScene : public IScene{
public:

	void Initialize()override;

	void Update()override;

	void Draw()override;

private:
	Camera camera_{};
	WorldTransform worldTransformCube_{};
	WorldTransform worldTransformAxis_{};
	uint32_t texHandleUV_ = 0;
	uint32_t texHandleMonsterBall_ = 0;
	Model* modelCube_ = nullptr;
	Model* modelAxis_ = nullptr;

	// particle
	std::list<Particle> particles1_ = {};
	std::list<Particle> particles2_ = {};
	std::unique_ptr<ParticleSystem> particle1_ = {};
	std::unique_ptr<ParticleSystem> particle2_ = {};
	const float dt = 1.0f / 60.0f;
	Emitter emit{};
	AccelerationField accelerationField{};
	std::mt19937 randomEngine_;
	bool isDrawParticle1_ = false;
	bool isDrawParticle2_ = false;
};

