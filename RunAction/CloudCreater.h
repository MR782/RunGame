#pragma once
#include<memory>
#include"cloud.h"

//�_�̐���

class CloudCreater {
	int spawn_cnt;//�������鎞��
public:
	void update();
	std::unique_ptr<Cloud> create();
};