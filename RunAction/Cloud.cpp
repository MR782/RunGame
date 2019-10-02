#include "Cloud.h"
#include"ScreenSystem.h"

Cloud::Cloud(Rect rect_) :Object(rect_)
{
	//生成時に必要な項目を設定
	this->anime->set("cloud");//画像セット
	this->name = "cloud";//名前を設定
	this->active = true;//存在していることにする
	this->velocity.x = -3;//移動量は固定のためここで定義
}

void Cloud::update()
{
	move();
	//画面左端に消えたら存在を消す
	if (this->rect.x + this->rect.w < 0) this->active = false;
}

void Cloud::move()
{
	//画面右から左に移動
	this->rect.x += (int)this->velocity.x;
}

bool Cloud::get_active()
{
	return this->active;
}
