#include "GameUI.h"
#include"./dxlib/DxLib.h"
#include"GameScene.h"
#include"ScreenSystem.h"
#include"define.h"

GameUI::GameUI()
{
	//�t�H���g���쐬
	int fontsize = 32;//�����̑傫��
	int thick = 32;//�����̑���
	int header_font = create_font(fontsize, thick, true);
	int scorefont = create_font(fontsize, thick, true);
	//���W��ݒ�
	this->scorelabel_position = { ScoreLabelPositionX,ScoreLabelPositionY };
	this->scorelabel_header_position = { ScrreLabelHeaderPositionX,ScoreLabelHeaderPositionY };
	//�e�L�X�g�̍쐬
	this->scorelabel = set_font("Score", this->scorelabel_position, scorefont, GetColor(255, 255, 255));
	this->scorelabel_header = set_font("", this->scorelabel_header_position, header_font, GetColor(255, 255, 255));
}

void GameUI::update()
{
	if (Engine::get_gameoverFlag() == true) {
		//�Q�[���I�[�o�[���Ɍ��₷���ʒu�Ɉړ�
		this->scorelabel.pos.y = (int)(ScoreLabelPositionYAfter);
		this->scorelabel_header.pos.y = (int)(ScoreLabelHeaderPositionAfter);
	}
	else {
		//�v���C���͉�ʏ㕔�ɕ\��
		this->scorelabel.pos.y = ScoreLabelPositionY;
		this->scorelabel_header.pos.y = ScoreLabelHeaderPositionY;
	}
}

void GameUI::draw()
{
	//�t�H���g��ݒ肵�������ŕ\������
	//SCORE��\��
	DrawStringToHandle(this->scorelabel.pos.x, this->scorelabel.pos.y,
		this->scorelabel.str, this->scorelabel.color,
		this->scorelabel.font);
	//�X�R�A��\��
	DrawFormatStringToHandle(this->scorelabel_header.pos.x, this->scorelabel_header.pos.y,
		this->scorelabel_header.color,
		this->scorelabel_header.font,
		"%d",Engine::get_score());
}
