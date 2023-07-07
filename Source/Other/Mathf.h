#pragma once

//不動小数算術
class Mathf
{
public:
	//線形補完
	static float Lerp(float a, float b, float t);

	//指定範囲内のランダム値を計算する
	static float RandomRange(float nim, float max);
};