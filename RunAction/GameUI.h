#pragma once
#include"BasicUI.h"

class GameUI {
	Text scorelabel;//�Q�[���̃X�R�A��\��
	Text scorelabel_header;//�Q�[����SCORE��\��
	Point scorelabel_position;//�X�R�A���x���̍��W
	Point scorelabel_header_position;//�X�R�A���x���w�b�_�[�̍��W
public:
	GameUI();
	void update();
	void draw();
};