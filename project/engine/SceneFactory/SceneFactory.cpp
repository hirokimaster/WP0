#include "SceneFactory.h"

std::unique_ptr<IScene> SceneFactory::CreateScene(const std::string& sceneName)
{
	std::unique_ptr<IScene> newScene = nullptr;

	if (sceneName == "GAME") {
		newScene = std::make_unique<GameScene>();	
	}
	else if (sceneName == "MODELSCENE") {
		newScene = std::make_unique<ModelScene>();
	}
	else if (sceneName == "SPRITESCENE") {
		newScene = std::make_unique<SpriteScene>();
	}

	return	newScene;
}