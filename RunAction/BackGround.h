#pragma once
#include"Purpose.h"

//�w�i�摜

class BackGround {
	Point position;//�\�����W
	int graph;//�O���t�B�b�N�n���h��
	Rect draw_rect;//�`��ʒu�Ƒ傫��
public:
	BackGround(Point,const char[50]);//�R���X�g���N�^�ŏ������W�ƃO���t�B�b�N�n���h���̃p�X�����
	void update();//�X�V����
	void draw();//�`�揈��
};