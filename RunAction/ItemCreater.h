#pragma once
#include<memory>
#include"Item.h"

//�A�C�e���̐���

class ItemCreater {
	int spawn_cnt;//�������鎞��
public:
	void update();
	std::unique_ptr<Item> create();//��������
};