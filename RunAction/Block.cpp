#include "Block.h"
#include"CoreScene.h"

void Block::move()
{
	//時間経過で移動させる
	this->rect.x += ((int)this->velocity.x);
}

Block::Block(Rect rect_):Object(rect_)
{
	this->active = true;//生存フラグを立てる
	this->anime->set("block");//ブロック画像をセット
	this->name = "block";//オブジェクトの名前をセット
}

void Block::update()
{
	this->move();//移動処理
	//プレイヤーとの当たり判定
	if (this->rect.Hit(model::player->get_rect())) {
			model::player->receive(this->name);
	}
	//画面外に行ったら自身を死んでいることにする
	const bool over_leftborder = this->rect.x + this->rect.w < 0;
	if (over_leftborder) this->active = false;
}

bool Block::get_active()
{
	//自身の存在フラグを返す
	return this->active;
}

void Block::set_movement(Vector2 vec2)
{
	//移動量をセット
	this->velocity = vec2;
}
