#pragma once
#include<memory>
#include"cloud.h"

//‰_‚Ì¶¬

class CloudCreater {
	int spawn_cnt;//¶¬‚·‚éŠÔ
public:
	void update();
	std::unique_ptr<Cloud> create();
};