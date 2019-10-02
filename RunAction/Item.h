#pragma once
#include"Object.h"

//アイテム

class Item : public Object {
private:
	bool active;//生きているかの判定(vectorから削除する際に使用)

	void move()override;//移動処理
public:
	Item(Rect);
	void update()override;

	bool get_active();
	void set_movement(Vector2 vec2);//移動量をセット
	void receive(std::string)override;
};