#pragma once
#include"Object.h"

//�u���b�N

class Block : public Object {
private:
	bool active;//�����Ă��邩�̔���(vector����폜����ۂɎg�p)

	void move()override;//�ړ�����
public:
	Block(Rect);
	void update()override;

	bool get_active();
	void set_movement(Vector2 vec2);//�ړ��ʂ��Z�b�g
};