#pragma once

#include <d3d11.h>
#include <DirectXMath.h>
#include "Graphics/RenderContext.h"
#include "Graphics/Model.h"
#include "Graphics/Sprite.h"

class Shader
{
public:
	Shader() {}
	virtual ~Shader() {}

	// 描画開始
	virtual void Begin(ID3D11DeviceContext* dc, const RenderContext& rc) = 0;

	// 描画
	virtual void Draw(ID3D11DeviceContext* dc, const Model* model) = 0;

	// 描画終了
	virtual void End(ID3D11DeviceContext* context) = 0;
};

class ModelShader
{
public:
	ModelShader() {}
	virtual ~ModelShader() {}

	// 描画開始
	virtual void Begin(const RenderContext& rc) = 0;

	// 必要なバッファの設定
	virtual void SetBuffers(const RenderContext& rc, const std::vector<Model::Node>& nodes, const ModelResource::Mesh& mesh) = 0;

	// サブセット単位で描画
	virtual void DrawSubset(const RenderContext& rc, const ModelResource::Subset& subset) = 0;

	// 描画終了
	virtual void End(const RenderContext& rc) = 0;
};


class SpriteShader
{
public:
	SpriteShader() {}
	virtual ~SpriteShader() {}

	// 描画開始
	virtual void Begin(const RenderContext& rc) = 0;

	// 描画
	virtual void Draw(const RenderContext& rc, const Sprite* sprite) = 0;

	// 描画終了
	virtual void End(const RenderContext& rc) = 0;
};