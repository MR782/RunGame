#include "Block.h"
#include"CoreScene.h"

void Block::move()
{
	//���Ԍo�߂ňړ�������
	this->rect.x += ((int)this->velocity.x);
}

Block::Block(Rect rect_):Object(rect_)
{
	this->active = true;//�����t���O�𗧂Ă�
	this->anime->set("block");//�u���b�N�摜���Z�b�g
	this->name = "block";//�I�u�W�F�N�g�̖��O���Z�b�g
}

void Block::update()
{
	this->move();//�ړ�����
	//�v���C���[�Ƃ̓����蔻��
	if (this->rect.Hit(model::player->get_rect())) {
			model::player->receive(this->name);
	}
	//��ʊO�ɍs�����玩�g������ł��邱�Ƃɂ���
	const bool over_leftborder = this->rect.x + this->rect.w < 0;
	if (over_leftborder) this->active = false;
}

bool Block::get_active()
{
	//���g�̑��݃t���O��Ԃ�
	return this->active;
}

void Block::set_movement(Vector2 vec2)
{
	//�ړ��ʂ��Z�b�g
	this->velocity = vec2;
}
