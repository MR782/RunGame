#include "BackGround.h"
#include"./dxlib/DxLib.h"
#include"ScreenSystem.h"
#include"CoreScene.h"
#include"define.h"

BackGround::BackGround(Point point, const char path[50] )
{
	//描画位置と範囲を決める
	this->position = point;
	this->draw_rect = { 0,0,ScreenSize::width,ScreenSize::height };
	//画像格納
	this->graph = LoadGraph(path);
}

void BackGround::update()
{
	this->position.x -= BackGroundDefaultSpeed;//背景を右に移動させていく
	//画面左端に消えたら画面右端に移動
	if (this->position.x + this->draw_rect.w <= 0) this->position.x = ScreenSize::width;
}

void BackGround::draw()
{
	//読み込んだ画像を描画(座標,画像を格納した変数,透過を行うか )
	DrawGraph(this->position.x, this->position.y, this->graph, FALSE);
}
