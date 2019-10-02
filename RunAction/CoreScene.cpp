#include "CoreScene.h"
#include"KeyBoard.h"
#include"Audio.h"
#include"CreateMap.h"
#include"Resource.h"
#include"ScreenFunction.h"
#include"ScreenHelperGraph.h"
#include"CreateMap.h"

CoreScene::CoreScene()
{
	//メモリ確保
	game = std::make_unique<GameScene>();
	title = std::make_unique<TitleScene>();
	//初期シーン設定
	scene = Scene::title;
}

CoreScene::~CoreScene()
{
	//用がなくなったら消す
	game.reset();
	title.reset();
}

void CoreScene::initialize()
{
	//画像と音楽の読み込みの準備
	GraphicResource::init();
	Audio::init();

	//使用画像をロード
	GraphicResource::load("player");
	GraphicResource::load("block");
	GraphicResource::load("item");
	GraphicResource::load("cloud");
	//使用音楽をロード
	Audio::load("se");
	Audio::load("bgm");

	//マップ生成の準備
	CreateMap::init();
	//初期シーンの初期化
	title->initialize();
}

void CoreScene::finalize()
{
	//キーボードや読み込んだデータ、作成したデータを削除
	KeyBoard::finalize();
	CreateMap::finalize();
	game->finalize();
	title->finalize();
	GraphicResource::finalize();
	Audio::finalize();
}

void CoreScene::update()
{
	KeyBoard::update();
	//現在のシーンに合わせて処理変える
	switch (scene)
	{
	case Scene::title:
		title->update();
		break;
	case Scene::game:
		game->update();
		break;
	}
	//フェードアウト・インの更新処理
	ScreenFunction::update();
}

//描画の総括
void CoreScene::draw()
{
	//シーンに合わせて描画するものを変える
	switch (scene)
	{
	case Scene::title:
		title->draw();
		break;
	case Scene::game:
		game->draw();
		break;
	}
	//フェードアウト・インの描画
	ScreenFunction::draw(ScreenHelperGraph::white_graph);
}

void CoreScene::scene_change(Scene scene_)
{
	//シーンを変える前に初期化処理を行う
	//現在のシーンの終了処理を行う
	switch (this->scene) {
	case Scene::title:
		title->finalize();
		break;
	case Scene::game:
		game->finalize();
		break;
	}
	//遷移するシーンの初期化を行う
	switch (scene_)
	{
	case Scene::title:
		title->initialize();
		break;
	case Scene::game:
		game->initialize();
		break;
	}
	scene = scene_;//シーンの更新
}
