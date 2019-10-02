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
	//タイトルロゴの作成
	int logo_font_size = 32;
	int logo_thick = 32;
	int logo_handle = create_font(logo_font_size, logo_thick, true);//フォントハンドルにセット
	Point logo_pos = { (int)(ScreenSize::width / 10.f),TitleLogoPosY };//表示座標設定
	this->title_logo = set_font("The Dash", logo_pos, logo_handle, GetColor(255, 255, 0));

	//タイトルのガイド作成
	int guide_font_size = 32;
	int guide_thick = 32;
	int guide_handle = create_font(guide_font_size, guide_thick, true);//フォントハンドルにセット
	Point guide_pos = { (int)(ScreenSize::width / 2.0) - guide_font_size * 4,(int)(ScreenSize::height / 2.0) };//表示座標設定
	this->control_guide = set_font("Zでゲームスタート", guide_pos, guide_handle, GetColor(255, 255, 0));
	//メモリ確保
	clouds = std::make_unique<std::vector<std::unique_ptr<Cloud>>>();
	cloud_creater = std::make_unique<CloudCreater>();
}

TitleScene::~TitleScene()
{
}

void TitleScene::initialize()
{
	//背景画像の読み込み
	this->back_graph = LoadGraph("./img/back/title.png");
	
	//タイトルのBGMを流す
	Audio::play("title");
	clouds->clear();
}

void TitleScene::finalize()
{
	//メモリ確保
	DeleteGraph(this->back_graph);
	clouds->clear();

	Engine::set_fade_ioFlag(false);//フェードイン状態にする
}

void TitleScene::update()
{
	//Zキーを押したなら
	if (KeyBoard::key_down(KEY_INPUT_Z)) {
		//フェードアウト開始
		Engine::set_fade_ioFlag(true);
		//決定音を鳴らす
		Audio::play("decision");
		//タイトルのBGM停止
		Audio::stop("title");
	}
	//雲を移動させる
	for (auto itr = clouds->begin(); itr != clouds->end(); itr++) {
		(*itr)->update();
	}
	cloud_creater->update();//一定のタイミングで雲を生成

	if (ScreenFunction::check_brend_max()) {
		//フェードアウトしきったら
		//ゲームシーンに移動
		core->scene_change(Scene::game);
	}
}

void TitleScene::draw()
{
	//タイトルシーンの背景を描画
	DrawExtendGraph(0, 0, ScreenSize::width, ScreenSize::height, this->back_graph, FALSE);
	//雲の描画
	for (auto itr = clouds->begin(); itr != clouds->end(); itr++) {
		(*itr)->draw();
	}
	//ロゴとガイドの描画
	draw_font(this->title_logo);
	draw_font(this->control_guide);
}
