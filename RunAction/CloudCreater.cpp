#include "CloudCreater.h"
#include"define.h"
#include"CoreScene.h"
#include"ScreenSystem.h"
#include<time.h>

void CloudCreater::update()
{
	this->spawn_cnt++;
	//一定のタイミングで雲を生成する
	if (this->spawn_cnt >= SpawnCloudTiming) {
		clouds->push_back(create());
		this->spawn_cnt = 0;
	}
}

std::unique_ptr<Cloud> CloudCreater::create()
{
	Rect cloud_rect;
	//実行時間により乱数を設定
	//srand((unsigned int)time(NULL));
	int random = rand() % ScreenSize::height;
	//乱数の結果により出現位置（Y座標を変える）
	cloud_rect = { ScreenSize::width, random, CloudWidth, CloudHeight };

	std::unique_ptr<Cloud> cloud;
	cloud = std::make_unique<Cloud>(cloud_rect);//定義した矩形で登録

	return cloud;
}
