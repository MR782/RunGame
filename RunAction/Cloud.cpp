#include "Cloud.h"
#include"ScreenSystem.h"

Cloud::Cloud(Rect rect_) :Object(rect_)
{
	//�������ɕK�v�ȍ��ڂ�ݒ�
	this->anime->set("cloud");//�摜�Z�b�g
	this->name = "cloud";//���O��ݒ�
	this->active = true;//���݂��Ă��邱�Ƃɂ���
	this->velocity.x = -3;//�ړ��ʂ͌Œ�̂��߂����Œ�`
}

void Cloud::update()
{
	move();
	//��ʍ��[�ɏ������瑶�݂�����
	if (this->rect.x + this->rect.w < 0) this->active = false;
}

void Cloud::move()
{
	//��ʉE���獶�Ɉړ�
	this->rect.x += (int)this->velocity.x;
}

bool Cloud::get_active()
{
	return this->active;
}
