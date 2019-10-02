#pragma once
#include"Object.h"

//プレイヤーキャラクター

class Player : public Object {
private:
	Vector2 movement;//移動量を入れる
	void move()override;//移動処理
	void set_jumppower(float);//ジャンプ力をセットする
public:
	Player(Rect);
	void initialize()override;
	void finalize()override;
	void update()override;
	void dead_update();//死亡後の更新処理

	void receive(std::string)override;

	Vector2 get_movement();
};