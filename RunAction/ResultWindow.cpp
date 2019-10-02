#include "ResultWindow.h"
#include"./dxlib/DxLib.h"
#include"ScreenSystem.h"
#include"GameScene.h"

ResultWindow::ResultWindow()
{
	//�������m��
	this->result = new GameUI();
	//�摜��int�^�ϐ��Ɋi�[
	this->window_graph = LoadGraph("./img/screen/score_window.png");
	this->restart_graph = LoadGraph("./img/screen/restart_msg.png");
	this->titleback_graph = LoadGraph("./img/screen/titleback_msg.png");
}

ResultWindow::~ResultWindow()
{
	//�������J��
	delete this->result;
}

void ResultWindow::update()
{
	//�X�R�A�̕\���̍X�V
	this->result->update();
}

void ResultWindow::draw()
{
	//�����Q�[���I�[�o�[�Ȃ�
	if (Engine::get_gameoverFlag() == true) {
		//�E�B���h�E�\��
		const Point window_graph_pos = { (int)(ScreenSize::width / 2.0f - 170), (int)(ScreenSize::height / 2.0 - 140) };
		DrawGraph(window_graph_pos.x, window_graph_pos.y, this->window_graph, TRUE);
		//���X�^�[�g�\��
		const Point restart_graph_pos = { (int)(ScreenSize::width / 2.0f - (7 * 32) / 2), (int)(ScreenSize::height / 2.0 - 50) };
		DrawGraph(restart_graph_pos.x, restart_graph_pos.y, this->restart_graph, TRUE);
		//�^�C�g���ɖ߂�\��
		const Point titleback_graph_pos = { (int)(ScreenSize::width / 2.0f - (7 * 32) / 2), (int)(ScreenSize::height / 2.0 + 10) };
		DrawGraph(titleback_graph_pos.x, titleback_graph_pos.y, this->titleback_graph, TRUE);
	}
	//���U���g�\��
	this->result->draw();
}
