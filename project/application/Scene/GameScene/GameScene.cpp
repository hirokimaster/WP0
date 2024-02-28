#include "GameScene.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Initialize()
{
	a = TextureManager::Load("resources/uvChecker.png");
	b = TextureManager::Load("resources/monsterBall.png");
}

void GameScene::Update()
{
}

void GameScene::Draw()
{
}

void GameScene::PostProcessDraw()
{
}
