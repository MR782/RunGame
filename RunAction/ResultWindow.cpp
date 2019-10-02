#include "ResultWindow.h"
#include"./dxlib/DxLib.h"
#include"ScreenSystem.h"
#include"GameScene.h"

ResultWindow::ResultWindow()
{
	//メモリ確保
	this->result = new GameUI();
	//画像をint型変数に格納
	this->window_graph = LoadGraph("./img/screen/score_window.png");
	this->restart_graph = LoadGraph("./img/screen/restart_msg.png");
	this->titleback_graph = LoadGraph("./img/screen/titleback_msg.png");
}

ResultWindow::~ResultWindow()
{
	//メモリ開放
	delete this->result;
}

void ResultWindow::update()
{
	//スコアの表示の更新
	this->result->update();
}

void ResultWindow::draw()
{
	//もしゲームオーバーなら
	if (Engine::get_gameoverFlag() == true) {
		//ウィンドウ表示
		const Point window_graph_pos = { (int)(ScreenSize::width / 2.0f - 170), (int)(ScreenSize::height / 2.0 - 140) };
		DrawGraph(window_graph_pos.x, window_graph_pos.y, this->window_graph, TRUE);
		//リスタート表示
		const Point restart_graph_pos = { (int)(ScreenSize::width / 2.0f - (7 * 32) / 2), (int)(ScreenSize::height / 2.0 - 50) };
		DrawGraph(restart_graph_pos.x, restart_graph_pos.y, this->restart_graph, TRUE);
		//タイトルに戻る表示
		const Point titleback_graph_pos = { (int)(ScreenSize::width / 2.0f - (7 * 32) / 2), (int)(ScreenSize::height / 2.0 + 10) };
		DrawGraph(titleback_graph_pos.x, titleback_graph_pos.y, this->titleback_graph, TRUE);
	}
	//リザルト表示
	this->result->draw();
}
