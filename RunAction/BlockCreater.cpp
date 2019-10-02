#include "BlockCreater.h"
#include"ScreenSystem.h"
#include<time.h>
#include"define.h"
#include"CoreScene.h"

BlockCreater::~BlockCreater()
{
}

void BlockCreater::update()
{
	this->spawn_cnt++;
	if (this->spawn_cnt >= SpawnBlockTiming) {
		model::blocks->push_back(create());//GameSceneのBLock配列に登録
		this->spawn_cnt = 0;
	}
}
std::unique_ptr<Block> BlockCreater::create()
{
	Rect block_rect;
	//実行時間により乱数を設定
	srand((unsigned int)time(NULL));
	int random1to0 = rand() % 2;;
	//乱数の結果により出現位置（Y座標を変える）上段か下段か
	switch (random1to0) {
	case 0:
		block_rect = { ScreenSize::width, BlockPos2, Block_Size, Block_Size };
		break;
	case 1:
		block_rect = { ScreenSize::width, BlockPos1, Block_Size, Block_Size };
		break;
	}
	//unique_ptrのブロックを用意
	std::unique_ptr<Block> block;
	block = std::make_unique<Block>(block_rect);//ブロックを定義した矩形で登録
	block->set_movement(Vector2(BlockDefaultSpeed - Engine::get_level(), 0));//ブロックの移動量を設定
	
	return block;//設定したブロックを返す
}
