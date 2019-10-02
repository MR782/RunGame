#pragma once
#include<memory>
#include"Purpose.h"
#include"Animation.h"
#include"Rigit.h"

//キャラクターの親クラス

class Object {
	//int animeCnt;//アニメーション切り替えカウンタ
protected:
	std::unique_ptr<Animation> anime;//アニメーション機能
	std::unique_ptr<Rigit> rigit;//重力など

	std::string name;//オブジェクト名
	Rect rect;//矩形、描画位置や当たり判定に使用する
	Vector2 velocity;//移動量
	Angle angle;//向きの情報
	bool hitflag;

	virtual void move() = 0;//移動処理
	bool object_check_hit(Rect,std::string parts = "me");
public:
	Object(Rect);//生成時の処理(矩形決定、初期アニメセット)
	virtual void initialize();
	virtual void finalize();
	virtual void update() = 0;//更新処理
	void draw();//描画処理

	virtual void receive(std::string);//受け取り処理(当たった時など当たった側が何をするか決める)
	//getter
	Rect get_rect();//自身の矩形を返す
};