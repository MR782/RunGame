#pragma once
#include"Object.h"

//ブロック

class Block : public Object {
private:
	bool active;//生きているかの判定(vectorから削除する際に使用)

	void move()override;//移動処理
public:
	Block(Rect);
	void update()override;

	bool get_active();
	void set_movement(Vector2 vec2);//移動量をセット
};