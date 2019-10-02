#include "BackGround.h"
#include"./dxlib/DxLib.h"
#include"ScreenSystem.h"
#include"CoreScene.h"
#include"define.h"

BackGround::BackGround(Point point, const char path[50] )
{
	//�`��ʒu�Ɣ͈͂����߂�
	this->position = point;
	this->draw_rect = { 0,0,ScreenSize::width,ScreenSize::height };
	//�摜�i�[
	this->graph = LoadGraph(path);
}

void BackGround::update()
{
	this->position.x -= BackGroundDefaultSpeed;//�w�i���E�Ɉړ������Ă���
	//��ʍ��[�ɏ��������ʉE�[�Ɉړ�
	if (this->position.x + this->draw_rect.w <= 0) this->position.x = ScreenSize::width;
}

void BackGround::draw()
{
	//�ǂݍ��񂾉摜��`��(���W,�摜���i�[�����ϐ�,���߂��s���� )
	DrawGraph(this->position.x, this->position.y, this->graph, FALSE);
}
