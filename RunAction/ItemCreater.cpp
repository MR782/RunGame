#include "ItemCreater.h"
#include<time.h>
#include"CoreScene.h"
#include"define.h"
#include"ScreenSystem.h"

void ItemCreater::update()
{
	this->spawn_cnt++;
	//一定のタイミングでアイテムを生成
	if (this->spawn_cnt >= SpawnItemTiming) {
		model::items->push_back(this->create());
		this->spawn_cnt = 0;
	}
}

std::unique_ptr<Item> ItemCreater::create()
{
	Rect item_rect;
	//実行時間により乱数を設定
	srand((unsigned int)time(NULL));
	int random1to0 = rand() % 2;;
	//乱数の結果により出現位置（Y座標を変える）上段か下段か
	switch (random1to0) {
	case 0:
		item_rect = { ScreenSize::width, ItemPos2, ItemSize, ItemSize };
		break;
	case 1:
		item_rect = { ScreenSize::width, ItemPos1, ItemSize, ItemSize };
		break;
	}
	std::unique_ptr<Item> item;
	item = std::make_unique<Item>(item_rect);//ブロックを定義した矩形で登録
	item->set_movement(Vector2(ItemDefaultSpeed - Engine::get_level(), 0));//ブロックの移動量を設定

	return item;
}
