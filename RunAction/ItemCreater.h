#pragma once
#include<memory>
#include"Item.h"

//アイテムの生成

class ItemCreater {
	int spawn_cnt;//生成する時間
public:
	void update();
	std::unique_ptr<Item> create();//生成処理
};