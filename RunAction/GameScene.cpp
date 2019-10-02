#include "GameScene.h"
#include"ScreenSystem.h"
#include"ScreenFunction.h"
#include"ScreenHelperGraph.h"
#include"CoreScene.h"
#include"Audio.h"
#include"define.h"
#include"KeyBoard.h"
#include"./dxlib/DxLib.h"
#include<fstream>
#include<sstream>
//モデル
std::unique_ptr<Player> model::player;
std::unique_ptr<std::vector<std::unique_ptr<Block>>> model::blocks;
std::unique_ptr<std::vector<std::unique_ptr<Item>>> model::items;
//システム
std::unique_ptr<Map> control::map;
std::unique_ptr<Engine> control::engine;

void GameScene::set_GameState(GameState gs)
{
	this->game_state = gs;
}

GameScene::GameScene()
{
	//背景（２枚）用意---------------------
	Point back_groundA(0, 0);
	back_grounds.push_back(BackGround(back_groundA, "./img/back/game.png"));//初期座標と画像パスを入力
	Point back_groundB(ScreenSize::width, 0);
	back_grounds.push_back(BackGround(back_groundB, "./img/back/game.png"));//初期座標と画像パスを入力
	//地面（２枚）用意----------------------
	Point groundA(0, ScreenSize::height - GroundHeight);
	back_grounds.push_back(BackGround(groundA, "./img/back/ground.png"));//初期座標と画像パスを入力
	Point groundB(ScreenSize::width, ScreenSize::height - GroundHeight);
	back_grounds.push_back(BackGround(groundB, "./img/back/ground.png"));//初期座標と画像パスを入力

	//モデル
	Rect p_rect(50, 0, 32, 32);
	model::player = std::make_unique<Player>(p_rect);
	//オブジェクトのメモリ確保
	model::blocks = std::make_unique<std::vector<std::unique_ptr<Block>>>();
	model::items = std::make_unique<std::vector<std::unique_ptr<Item>>>();
	//システム
	control::map = std::make_unique<Map>();                 // マップ
	control::engine = std::make_unique<Engine>();			//エンジン（ゲーム内全般で使用するもの）
	//生成装置
	block_creater = std::make_unique<BlockCreater>();
	item_creater = std::make_unique<ItemCreater>();
	//リザルト
	this->result = new ResultWindow();
}

GameScene::~GameScene()
{
	//メモリ開放
	model::blocks->clear();
	model::items->clear();
	back_grounds.clear();
	delete this->result;
}

void GameScene::initialize()
{
	//モデルの初期化
	model::player->initialize();

	control::engine->initialize();//ゲーム内で使用するのもすべて初期化
	//----------------------------------------------------------------------------
	Audio::play("game");//ゲームシーンの音楽
	control::map->set("stage1");
	//データの初期化
	this->game_state = GameState::PLAY;
	this->delete_block_cnt = 0;
	this->max_block = 10; 
}

void GameScene::finalize()
{
	model::blocks->clear();
	model::items->clear();
	Engine::set_fade_ioFlag(false);
}

void GameScene::update()
{
	const bool is_dead = Engine::get_gameoverFlag() == true;//プレイヤーが死亡したらtrueになるフラグで判定
	if (this->game_state == GameState::PLAY) {//ゲームプレイ中なら
		Engine::set_fade_ioFlag(false);//フェードインを行う
		//各オブジェクトのupdateを呼ぶ
		//背景のupdate-----------------------------------------------
		for (auto itr = back_grounds.begin(); itr != back_grounds.end(); itr++) {
			itr->update();
		}
		//プレイヤーのupdate-----------------------------------------
		model::player->update();
		//ブロックの生成装置------------------------------------------
		block_creater->update();
		//ブロックの更新処理
		for (auto itr = model::blocks->begin(); itr != model::blocks->end(); itr++) {
			(*itr)->update();
		}
		delete_block();//条件を満たしたブロックをvectorから削除する

		//アイテムの生成装置-------------------------------------------
		if(this->start_item_creater_cnt >= Start_SpawnItem) item_creater->update();
		//アイテムの更新処理
		for (auto itr = model::items->begin(); itr != model::items->end(); itr++) {
			(*itr)->update();
		}
		delete_item();//条件を満たしたアイテムをvectorから削除する

		//スコアが増加していく
		Engine::set_score(Engine::get_score() + 1);
		//アイテムの生成を開始する時間までのカウント
		this->start_item_creater_cnt = min(Start_SpawnItem, this->start_item_creater_cnt++);//30フレーム
		//ブロックが一定数消えたらレベルを1上げる
		if (this->delete_block_cnt > this->max_block) { 
			Engine::set_level(Engine::get_level() + 1);
			this->delete_block_cnt = 0;//カウンターを初期化
		}
	}
	else {//ゲームがリザルトに移行したら
		model::player->dead_update();//死亡後の更新処理
		if (KeyBoard::key_down(KEY_INPUT_Z)){//Zキーが押されたらリスタートさせる
			core->scene_change(Scene::game);
		}
		else if (KeyBoard::key_down(KEY_INPUT_X)) {//Xキーが押されたらタイトルに戻る
			//決定音を鳴らす
			Audio::play("decision");
			Engine::set_fade_ioFlag(true);//フェードアウト開始
		}
		if (ScreenFunction::check_brend_max()) {//フェードアウトが終わったら
			core->scene_change(Scene::title);//タイトルにシーンを変える
		}
	}
	result->update();
}

void GameScene::draw()
{
	//各オブジェクトのdrawを呼ぶ
	//背景の描画
	for (auto itr = back_grounds.begin(); itr != back_grounds.end(); itr++) {
		(*itr).draw();
	}
	//ブロックの描画
	for (auto itr = model::blocks->begin(); itr != model::blocks->end(); itr++) {
		(*itr)->draw();
	}
	//アイテムの描画
	for (auto itr = model::items->begin(); itr != model::items->end(); itr++) {
		(*itr)->draw();
	}
	//プレイヤーの描画
	model::player->draw();
	//スコアの描画
	this->result->draw();
}

void GameScene::delete_block()
{
	//activeがfalseならデータを消す
	for (auto itr = model::blocks->begin(); itr != model::blocks->end(); itr++) {
		if ((*itr)->get_active() == false) {
			model::blocks->erase((itr));
			this->delete_block_cnt++;
			break;
		}
	}
}

void GameScene::delete_item()
{
	//activeがfalseならデータを消す
	for (auto itr = model::items->begin(); itr != model::items->end(); itr++) {
		if ((*itr)->get_active() == false) {
			model::items->erase((itr));
			break;
		}
	}
}

void GameScene::map_set()
{
	control::map->set("stage1");//ステージをセット
}
