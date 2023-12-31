#include "Camera.h"

//指定方向へ向く
void Camera::SetLookAt(
	const DirectX::XMFLOAT3& eye, 
	const DirectX::XMFLOAT3& focus,
	const DirectX::XMFLOAT3& up)
{
	//視点、注意点、上方向からビュー行列を作成
	DirectX::XMVECTOR Eye	= DirectX::XMLoadFloat3(&eye);
	DirectX::XMVECTOR Focus = DirectX::XMLoadFloat3(&focus);
	DirectX::XMVECTOR Up	= DirectX::XMLoadFloat3(&up);
	DirectX::XMMATRIX View	= DirectX::XMMatrixLookAtLH(Eye, Focus, Up);

	DirectX::XMStoreFloat4x4(&view_, View);

	//ビューを逆行列化し、ワールド行列に戻す
	DirectX::XMMATRIX World = DirectX::XMMatrixInverse(nullptr, View); //マトリックスは行列、インバースは逆
	DirectX::XMFLOAT4X4 world;

	DirectX::XMStoreFloat4x4(&world, World);

	//カメラの方向を取り出す
	this->right_.x = world._11;
	this->right_.y = world._12;
	this->right_.z = world._13;

	this->up_.x = world._21;
	this->up_.y = world._22;
	this->up_.z = world._23;

	this->front_.x = world._31;
	this->front_.y = world._32;
	this->front_.z = world._33;

	//視点、注意点を保存
	this->eye_ = eye;
	this->focus_ = focus;
}

//パースペクティブ設定
void Camera::SetPerspectiveFov(float fovY, float aspect, float nearZ, float farZ)
{
	//画角、画面比率、クリップ距離からプロジェクション行列を作成
	DirectX::XMMATRIX Projection = 
		DirectX::XMMatrixPerspectiveFovLH(fovY, aspect, nearZ, farZ);
	DirectX::XMStoreFloat4x4(&projection_, Projection);

	//クリップ距離設定
	this->nearZ_ = nearZ;
	this->farZ_ = farZ;
}