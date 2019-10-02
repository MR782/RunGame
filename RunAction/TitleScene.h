#pragma once
#include"Purpose.h"
#include"BasicUI.h"
#include"Cloud.h"
#include"CloudCreater.h"

class TitleScene {
	int back_graph;//�w�i�摜
	int cloud_graoh;//�w�i�̉_�̉摜
	Text title_logo;//�^�C�g�����S
	Text control_guide;//�����p�e�L�X�g

	std::unique_ptr<CloudCreater> cloud_creater;//�_�̐������u
public:
	TitleScene();
	~TitleScene();
	void initialize();
	void finalize();
	void update();
	void draw();
};

extern std::unique_ptr<std::vector<std::unique_ptr<Cloud>>> clouds;