#pragma once
#include"GameUI.h"

class ResultWindow {
	Point position;//�E�B���h�E��\������ʒu
	GameUI* result;//���U���g�\����UI
	int window_graph;//�E�B���h�E�̉摜
	int restart_graph;//���X�^�[�g�K�C�h�̉摜
	int titleback_graph;//�^�C�g���o�b�N�̉摜
public:
	ResultWindow();
	~ResultWindow();
	void update();
	void draw();
};