#pragma once
#include<iostream>
#include"Purpose.h"

struct Text {
	const char* str;//描画する文字
	int text_width;//テキストの長さ
	Point pos;//表示座標
	int font;//フォントハンドル
	int color;//色
};

Text set_font(const char* str, Point pos, int font, int color);

int create_font(int size,int thick,bool is_anti_alias);

void draw_font(Text handle);