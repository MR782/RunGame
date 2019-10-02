#include "Item.h"
#include"CoreScene.h"
#include"Audio.h"

void Item::move()
{
	//画面右端から左端に移動する
	this->rect.x += ((int)this->velocity.x);
}

Item::Item(Rect rect_):Object(rect_)
{
	this->active = true;//生存フラグをtrueにする
	this->anime->set("item");//itemの画像をセット
	this->name = "item";//オブジェクトの名前を設定
}

void Item::update()
{
	this->move();
	//プレイヤーとの当たり判定
	if (this->rect.Hit(model::player->get_rect())) {
			model::player->receive(this->name);
	}
	//画面外に行ったら自身を死んでいることにする
	const bool over_leftborder = this->rect.x + this->rect.w < 0;
	if (over_leftborder) this->active = false;
}

bool Item::get_active()
{
	return this->active;//生存中か判定に使用
}

void Item::set_movement(Vector2 vec2)
{
	//移動量をセット
	this->velocity = vec2;
}

void Item::receive(std::string name)
{
	if (name == "player") {
		//アイテム取得でスコア（100）加算
		Engine::set_score(Engine::get_score() + 500);
		this->active = false;//自身を消す
		Audio::play("get_item");//アイテム取得音を鳴らす
	}
}
