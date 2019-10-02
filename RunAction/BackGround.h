#pragma once
#include"Purpose.h"

//背景画像

class BackGround {
	Point position;//表示座標
	int graph;//グラフィックハンドル
	Rect draw_rect;//描画位置と大きさ
public:
	BackGround(Point,const char[50]);//コンストラクタで初期座標とグラフィックハンドルのパスを入力
	void update();//更新処理
	void draw();//描画処理
};