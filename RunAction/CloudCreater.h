#pragma once
#include<memory>
#include"cloud.h"

//雲の生成

class CloudCreater {
	int spawn_cnt;//生成する時間
public:
	void update();
	std::unique_ptr<Cloud> create();
};