#include "BackGround.h"
#include"./dxlib/DxLib.h"
#include"ScreenSystem.h"
#include"CoreScene.h"
#include"define.h"

BackGround::BackGround(Point point, const char path[50] )
{
	//•`‰æˆÊ’u‚Æ”ÍˆÍ‚ðŒˆ‚ß‚é
	this->position = point;
	this->draw_rect = { 0,0,ScreenSize::width,ScreenSize::height };
	//‰æ‘œŠi”[
	this->graph = LoadGraph(path);
}

void BackGround::update()
{
	this->position.x -= BackGroundDefaultSpeed;//”wŒi‚ð‰E‚ÉˆÚ“®‚³‚¹‚Ä‚¢‚­
	//‰æ–Ê¶’[‚ÉÁ‚¦‚½‚ç‰æ–Ê‰E’[‚ÉˆÚ“®
	if (this->position.x + this->draw_rect.w <= 0) this->position.x = ScreenSize::width;
}

void BackGround::draw()
{
	//“Ç‚Ýž‚ñ‚¾‰æ‘œ‚ð•`‰æ(À•W,‰æ‘œ‚ðŠi”[‚µ‚½•Ï”,“§‰ß‚ðs‚¤‚© )
	DrawGraph(this->position.x, this->position.y, this->graph, FALSE);
}
