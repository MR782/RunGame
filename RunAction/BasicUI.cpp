#include "BasicUI.h"
#include"./dxlib/DxLib.h"

Text set_font(const char* str,Point pos, int font, int color = GetColor(255, 255, 255))
{
	Text text;
	text.str = str;
	text.pos = pos;
	text.font = font;
	text.color = color;

	return text;
}

int create_font(int size, int thick, bool is_anti_alias)
{
	int handle;
	//アンチエイリアスを使用するなら
	if (is_anti_alias) {
		handle = CreateFontToHandle("", size, thick, DX_FONTTYPE_ANTIALIASING);
	}
	else {
		handle = CreateFontToHandle("", size, thick, DX_FONTTYPE_NORMAL);
	}
	return handle;
}

void draw_font(Text handle)
{
	DrawStringToHandle(handle.pos.x, handle.pos.y, handle.str, handle.color, handle.font);
}
