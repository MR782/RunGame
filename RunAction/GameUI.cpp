#include "GameUI.h"
#include"./dxlib/DxLib.h"
#include"GameScene.h"
#include"ScreenSystem.h"
#include"define.h"

GameUI::GameUI()
{
	//フォントを作成
	int fontsize = 32;//文字の大きさ
	int thick = 32;//文字の太さ
	int header_font = create_font(fontsize, thick, true);
	int scorefont = create_font(fontsize, thick, true);
	//座標を設定
	this->scorelabel_position = { ScoreLabelPositionX,ScoreLabelPositionY };
	this->scorelabel_header_position = { ScrreLabelHeaderPositionX,ScoreLabelHeaderPositionY };
	//テキストの作成
	this->scorelabel = set_font("Score", this->scorelabel_position, scorefont, GetColor(255, 255, 255));
	this->scorelabel_header = set_font("", this->scorelabel_header_position, header_font, GetColor(255, 255, 255));
}

void GameUI::update()
{
	if (Engine::get_gameoverFlag() == true) {
		//ゲームオーバー時に見やすい位置に移動
		this->scorelabel.pos.y = (int)(ScoreLabelPositionYAfter);
		this->scorelabel_header.pos.y = (int)(ScoreLabelHeaderPositionAfter);
	}
	else {
		//プレイ中は画面上部に表示
		this->scorelabel.pos.y = ScoreLabelPositionY;
		this->scorelabel_header.pos.y = ScoreLabelHeaderPositionY;
	}
}

void GameUI::draw()
{
	//フォントを設定した文字で表示する
	//SCOREを表示
	DrawStringToHandle(this->scorelabel.pos.x, this->scorelabel.pos.y,
		this->scorelabel.str, this->scorelabel.color,
		this->scorelabel.font);
	//スコアを表示
	DrawFormatStringToHandle(this->scorelabel_header.pos.x, this->scorelabel_header.pos.y,
		this->scorelabel_header.color,
		this->scorelabel_header.font,
		"%d",Engine::get_score());
}
