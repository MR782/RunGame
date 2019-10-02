#pragma once
#include"Purpose.h"

//落下や矩形判定

class Rigit {
public:
	bool check_foot(const Rect& rect_);//足元判定
	void check_move(Vector2& vec_, Rect& rect_, bool& hit_flag);//マップにめり込まないようにする
	void fall(Vector2& ,float);//落下処理
};