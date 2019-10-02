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
		model::blocks->push_back(create());//GameScene��BLock�z��ɓo�^
		this->spawn_cnt = 0;
	}
}
std::unique_ptr<Block> BlockCreater::create()
{
	Rect block_rect;
	//���s���Ԃɂ�藐����ݒ�
	srand((unsigned int)time(NULL));
	int random1to0 = rand() % 2;;
	//�����̌��ʂɂ��o���ʒu�iY���W��ς���j��i�����i��
	switch (random1to0) {
	case 0:
		block_rect = { ScreenSize::width, BlockPos2, Block_Size, Block_Size };
		break;
	case 1:
		block_rect = { ScreenSize::width, BlockPos1, Block_Size, Block_Size };
		break;
	}
	//unique_ptr�̃u���b�N��p��
	std::unique_ptr<Block> block;
	block = std::make_unique<Block>(block_rect);//�u���b�N���`������`�œo�^
	block->set_movement(Vector2(BlockDefaultSpeed - Engine::get_level(), 0));//�u���b�N�̈ړ��ʂ�ݒ�
	
	return block;//�ݒ肵���u���b�N��Ԃ�
}
