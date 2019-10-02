#include"Rigit.h"
#include"CoreScene.h"
#include"ScreenSystem.h"

bool Rigit::check_foot(const Rect & rect_)
{
	Rect foot = { rect_.x ,rect_.y + rect_.h,rect_.w,1 };
	//当たり判定を行った結果を返す
	return control::map->map_hitcheck(foot);
}

//マップでのめり込まない移動処理
void Rigit::check_move(Vector2& vec_, Rect& rect_, bool& hit_flag) {
	hit_flag = false;
	//X軸
	while (vec_.x != 0)
	{
		int preX = rect_.x;
		if (vec_.x >= 1) { rect_.x += 1; vec_.x -= 1; }// 座標を1ずつ加算　移動量１ずつ減算
		else if (vec_.x <= -1) { rect_.x -= 1; vec_.x += 1; }// 座標を1ずつ減算　移動量１ずつ加算
		else { rect_.x += (int)vec_.x; vec_.x = 0; }//小数点以下なら移動量をそのまま加えて移動量を０にする
		if (control::map->map_hitcheck(rect_)) {//マップと当たっているなら
			rect_.x = preX;//元の座標に戻す
			hit_flag = true;//ヒット判定をtrueにする
			break;
		}
	}
	//Y軸
	while (vec_.y != 0)
	{
		int preY = rect_.y;
		if (vec_.y >= 1) { rect_.y += 1; vec_.y -= 1; }// 座標を1ずつ加算　移動量１ずつ減算
		else if (vec_.y <= -1) { rect_.y -= 1; vec_.y += 1; }// 座標を1ずつ減算　移動量１ずつ加算
		else { rect_.y += (int)vec_.y; vec_.y = 0; }//小数点以下なら移動量をそのまま加えて移動量を０にする
		if (control::map->map_hitcheck(rect_)) {//マップと当たっているなら
			rect_.y = preY;//元の座標に戻す
			hit_flag = true;//ヒット判定をtrueにする
			break;
		}
	}
}

void Rigit::fall(Vector2& vec2, float fallspeed_)
{
	vec2.y += (int)fallspeed_;
}
