#pragma once
#include"BasicUI.h"

class GameUI {
	Text scorelabel;//ゲームのスコアを表示
	Text scorelabel_header;//ゲームのSCOREを表示
	Point scorelabel_position;//スコアラベルの座標
	Point scorelabel_header_position;//スコアラベルヘッダーの座標
public:
	GameUI();
	void update();
	void draw();
};