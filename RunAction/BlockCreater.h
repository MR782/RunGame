#pragma once
#include<memory>
#include"Block.h"

//ブロックの生成

class BlockCreater {
	int spawn_cnt;//生成する時間
	std::unique_ptr<Block> create();//ブロックを生成する
public:
	~BlockCreater();
	void update();//更新して一定のタイミングでブロックを生成する
};