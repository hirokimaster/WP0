#pragma once
#include "engine/Model/State/IModelState.h"
#include "engine/Model/State/ModelSphere.h"
#include "engine/Math/Vector2.h"
#include <fstream>
#include <sstream>
#include "engine/Utility/ImGuiManager/ImGuiManager.h"
#include "engine/Camera/Camera.h"
#include "externals/assimp/include/assimp/Importer.hpp"
#include "externals/assimp/include/assimp/scene.h"
#include "externals/assimp/include/assimp/postprocess.h"
#include <numbers>

struct Node {
	Matrix4x4 localMatrix;
	std::string name;
	std::vector<Node> children;
};

struct MaterialData {
	std::string textureFilePath;
};

struct ModelData {
	std::vector<VertexData> vertices;
	MaterialData material;
	Node rootNode;
};

class Model {
public:

	~Model();

	/// <summary>
	/// obj初期化
	/// </summary>
	/// <param name="filename"></param>
	void InitializeObj(const std::string& filename);

	/// <summary>
	/// gltf初期化
	/// </summary>
	/// <param name="filename"></param>
	void InitializeGLTF(const std::string& filename);

	/// <summary>
	/// Objの描画
	/// </summary>
	void Draw(WorldTransform worldTransform, Camera camera, Light light = None);

#pragma region Setter

	// テクスチャハンドル設定
	void SetTexHandle(uint32_t texHandle) { texHandle_ = texHandle; }
	// ライティングのsetter
	int32_t SetEnableLighting(int32_t enableLighting) { return materialData_->enableLighting = enableLighting; }
	// マテリアルの設定
	Material SetMaterialProperty(Material materialdata) { return *materialData_ = materialdata; }
	// directionalLightの設定
	DirectionalLight SetLightingProperty(DirectionalLight directionalLight) { return *directionalLightData_ = directionalLight; }
	// lightの設定
	PointLight SetPointLightProperty(PointLight pointLight) { return *pointLightData_ = pointLight; }
	SpotLight SetSpotLightProperty(SpotLight spotLight) { return *spotLightData_ = spotLight; }
	// cameradataの設定
	Vector3 SetCameraData(Vector3 camera) { return cameraData_->worldPosition = camera; }
#pragma endregion

	/// <summary>
	/// Objファイルを読む
	/// </summary>
	/// <param name="directoryPath"></param>
	/// <param name="filename"></param>
	/// <returns></returns>
	ModelData LoadObjFile(const std::string& directoryPath, const std::string& filename);

	/// <summary>
	/// GLTFファイルを読む
	/// </summary>
	/// <param name="directoryPath"></param>
	/// <param name="filename"></param>
	/// <returns></returns>
	ModelData LoadGLTFFile(const std::string& directoryPath, const std::string& filename);

	/// <summary>
	/// mtlファイルを読む
	/// </summary>
	/// <param name="directoryPath"></param>
	/// <param name="filename"></param>
	/// <returns></returns>
	MaterialData LoadMaterialTemplateFile(const std::string& directoryPath, const std::string& filename);

	/// <summary>
	/// ノードを読む
	/// </summary>
	/// <param name="node"></param>
	/// <returns></returns>
	Node ReadNode(aiNode* node);

private: // メンバ変数

	ModelData modelData_;
	Resource resource_ = {};
	D3D12_VERTEX_BUFFER_VIEW objVertexBufferView_{};
	Material* materialData_ = nullptr;
	DirectionalLight* directionalLightData_ = nullptr;
	uint32_t texHandle_ = 0;
	PointLight* pointLightData_ = nullptr;
	SpotLight* spotLightData_ = nullptr;
	CameraData* cameraData_ = nullptr;
	Property property_{};
};


