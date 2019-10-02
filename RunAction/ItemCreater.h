#pragma once
#include<memory>
#include"Item.h"

//ƒAƒCƒeƒ€‚Ì¶¬

class ItemCreater {
	int spawn_cnt;//¶¬‚·‚éŠÔ
public:
	void update();
	std::unique_ptr<Item> create();//¶¬ˆ—
};