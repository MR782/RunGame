#include "Item.h"
#include"CoreScene.h"
#include"Audio.h"

void Item::move()
{
	//��ʉE�[���獶�[�Ɉړ�����
	this->rect.x += ((int)this->velocity.x);
}

Item::Item(Rect rect_):Object(rect_)
{
	this->active = true;//�����t���O��true�ɂ���
	this->anime->set("item");//item�̉摜���Z�b�g
	this->name = "item";//�I�u�W�F�N�g�̖��O��ݒ�
}

void Item::update()
{
	this->move();
	//�v���C���[�Ƃ̓����蔻��
	if (this->rect.Hit(model::player->get_rect())) {
			model::player->receive(this->name);
	}
	//��ʊO�ɍs�����玩�g������ł��邱�Ƃɂ���
	const bool over_leftborder = this->rect.x + this->rect.w < 0;
	if (over_leftborder) this->active = false;
}

bool Item::get_active()
{
	return this->active;//������������Ɏg�p
}

void Item::set_movement(Vector2 vec2)
{
	//�ړ��ʂ��Z�b�g
	this->velocity = vec2;
}

void Item::receive(std::string name)
{
	if (name == "player") {
		//�A�C�e���擾�ŃX�R�A�i100�j���Z
		Engine::set_score(Engine::get_score() + 500);
		this->active = false;//���g������
		Audio::play("get_item");//�A�C�e���擾����炷
	}
}
