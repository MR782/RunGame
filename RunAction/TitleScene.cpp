#include "TitleScene.h"
#include"./dxlib/DxLib.h"
#include"KeyBoard.h"
#include"ScreenFunction.h"
#include"CoreScene.h"
#include"define.h"
#include"ScreenSystem.h"
#include"Audio.h"

std::unique_ptr<std::vector<std::unique_ptr<Cloud>>> clouds;

TitleScene::TitleScene()
{
	//�^�C�g�����S�̍쐬
	int logo_font_size = 32;
	int logo_thick = 32;
	int logo_handle = create_font(logo_font_size, logo_thick, true);//�t�H���g�n���h���ɃZ�b�g
	Point logo_pos = { (int)(ScreenSize::width / 10.f),TitleLogoPosY };//�\�����W�ݒ�
	this->title_logo = set_font("The Dash", logo_pos, logo_handle, GetColor(255, 255, 0));

	//�^�C�g���̃K�C�h�쐬
	int guide_font_size = 32;
	int guide_thick = 32;
	int guide_handle = create_font(guide_font_size, guide_thick, true);//�t�H���g�n���h���ɃZ�b�g
	Point guide_pos = { (int)(ScreenSize::width / 2.0) - guide_font_size * 4,(int)(ScreenSize::height / 2.0) };//�\�����W�ݒ�
	this->control_guide = set_font("Z�ŃQ�[���X�^�[�g", guide_pos, guide_handle, GetColor(255, 255, 0));
	//�������m��
	clouds = std::make_unique<std::vector<std::unique_ptr<Cloud>>>();
	cloud_creater = std::make_unique<CloudCreater>();
}

TitleScene::~TitleScene()
{
}

void TitleScene::initialize()
{
	//�w�i�摜�̓ǂݍ���
	this->back_graph = LoadGraph("./img/back/title.png");
	
	//�^�C�g����BGM�𗬂�
	Audio::play("title");
	clouds->clear();
}

void TitleScene::finalize()
{
	//�������m��
	DeleteGraph(this->back_graph);
	clouds->clear();

	Engine::set_fade_ioFlag(false);//�t�F�[�h�C����Ԃɂ���
}

void TitleScene::update()
{
	//Z�L�[���������Ȃ�
	if (KeyBoard::key_down(KEY_INPUT_Z)) {
		//�t�F�[�h�A�E�g�J�n
		Engine::set_fade_ioFlag(true);
		//���艹��炷
		Audio::play("decision");
		//�^�C�g����BGM��~
		Audio::stop("title");
	}
	//�_���ړ�������
	for (auto itr = clouds->begin(); itr != clouds->end(); itr++) {
		(*itr)->update();
	}
	cloud_creater->update();//���̃^�C�~���O�ŉ_�𐶐�

	if (ScreenFunction::check_brend_max()) {
		//�t�F�[�h�A�E�g����������
		//�Q�[���V�[���Ɉړ�
		core->scene_change(Scene::game);
	}
}

void TitleScene::draw()
{
	//�^�C�g���V�[���̔w�i��`��
	DrawExtendGraph(0, 0, ScreenSize::width, ScreenSize::height, this->back_graph, FALSE);
	//�_�̕`��
	for (auto itr = clouds->begin(); itr != clouds->end(); itr++) {
		(*itr)->draw();
	}
	//���S�ƃK�C�h�̕`��
	draw_font(this->title_logo);
	draw_font(this->control_guide);
}
