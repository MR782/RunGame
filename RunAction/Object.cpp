#include "Object.h"
#include"CoreScene.h"
#include"./dxlib/DxLib.h"

bool Object::object_check_hit(Rect rect_, std::string parts)
{
	//自身と当たり判定するなら
	if (parts == "me") {
		Rect me(this->rect.x, this->rect.y, this->rect.w, this->rect.h);
		if (rect_.Hit(me)) {
			return true;
		}
	}
	//足元と何かの矩形で当たり判定を行うなら
	else if (parts == "foot") {
		Rect foot(this->rect.x, this->rect.y + this->rect.h, this->rect.w, 1);
		if (rect_.Hit(foot)) {
			return true;
		}
	}
	//以下必要に応じて追加
	return false;
}

Object::Object(Rect _rect)
{
	this->rect = _rect;
	this->angle = Angle::Right;
	this->hitflag = false;

	this->velocity = Vector2(0, 0);

	this->anime = std::make_unique<Animation>();
}

void Object::initialize()
{
}

void Object::finalize()
{
}

void Object::draw()
{
	this->anime->draw_anime(this->rect);
}

void Object::receive(std::string name)
{
	throw "receiveが実装されていません";//例外処理を飛ばす
}

Rect Object::get_rect()
{
	return this->rect;
}