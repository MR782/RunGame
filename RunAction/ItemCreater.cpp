#include "ItemCreater.h"
#include<time.h>
#include"CoreScene.h"
#include"define.h"
#include"ScreenSystem.h"

void ItemCreater::update()
{
	this->spawn_cnt++;
	//���̃^�C�~���O�ŃA�C�e���𐶐�
	if (this->spawn_cnt >= SpawnItemTiming) {
		model::items->push_back(this->create());
		this->spawn_cnt = 0;
	}
}

std::unique_ptr<Item> ItemCreater::create()
{
	Rect item_rect;
	//���s���Ԃɂ�藐����ݒ�
	srand((unsigned int)time(NULL));
	int random1to0 = rand() % 2;;
	//�����̌��ʂɂ��o���ʒu�iY���W��ς���j��i�����i��
	switch (random1to0) {
	case 0:
		item_rect = { ScreenSize::width, ItemPos2, ItemSize, ItemSize };
		break;
	case 1:
		item_rect = { ScreenSize::width, ItemPos1, ItemSize, ItemSize };
		break;
	}
	std::unique_ptr<Item> item;
	item = std::make_unique<Item>(item_rect);//�u���b�N���`������`�œo�^
	item->set_movement(Vector2(ItemDefaultSpeed - Engine::get_level(), 0));//�u���b�N�̈ړ��ʂ�ݒ�

	return item;
}
