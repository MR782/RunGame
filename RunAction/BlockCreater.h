#pragma once
#include<memory>
#include"Block.h"

//�u���b�N�̐���

class BlockCreater {
	int spawn_cnt;//�������鎞��
	std::unique_ptr<Block> create();//�u���b�N�𐶐�����
public:
	~BlockCreater();
	void update();//�X�V���Ĉ��̃^�C�~���O�Ńu���b�N�𐶐�����
};