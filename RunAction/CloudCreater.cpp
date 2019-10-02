#include "CloudCreater.h"
#include"define.h"
#include"CoreScene.h"
#include"ScreenSystem.h"
#include<time.h>

void CloudCreater::update()
{
	this->spawn_cnt++;
	//���̃^�C�~���O�ŉ_�𐶐�����
	if (this->spawn_cnt >= SpawnCloudTiming) {
		clouds->push_back(create());
		this->spawn_cnt = 0;
	}
}

std::unique_ptr<Cloud> CloudCreater::create()
{
	Rect cloud_rect;
	//���s���Ԃɂ�藐����ݒ�
	//srand((unsigned int)time(NULL));
	int random = rand() % ScreenSize::height;
	//�����̌��ʂɂ��o���ʒu�iY���W��ς���j
	cloud_rect = { ScreenSize::width, random, CloudWidth, CloudHeight };

	std::unique_ptr<Cloud> cloud;
	cloud = std::make_unique<Cloud>(cloud_rect);//��`������`�œo�^

	return cloud;
}
