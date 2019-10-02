#pragma once
#include"GameUI.h"

class ResultWindow {
	Point position;//ウィンドウを表示する位置
	GameUI* result;//リザルト表示のUI
	int window_graph;//ウィンドウの画像
	int restart_graph;//リスタートガイドの画像
	int titleback_graph;//タイトルバックの画像
public:
	ResultWindow();
	~ResultWindow();
	void update();
	void draw();
};