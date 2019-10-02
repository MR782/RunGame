#pragma once
#include<memory>
//プレイヤー
#include"player.h"
//ブロック
#include"BlockCreater.h"
//アイテム
#include"ItemCreater.h"
//システム
#include"Map.h"
#include"Engine.h"
//背景
#include"BackGround.h"
//リザルト表示
#include"ResultWindow.h"


class GameScene {
public:
	enum class GameState {
		PLAY,//ゲーム中
		RESULT//リザルト表示
	};
	//メンバー
	void set_GameState(GameState);
	//メソッド
	GameScene();
	~GameScene();
	void initialize();
	void finalize();
	void update();
	void draw();
private:
	GameState game_state;//ゲームの状態
	//生成装置
	std::unique_ptr<BlockCreater> block_creater;
	std::unique_ptr<ItemCreater> item_creater;
	int start_item_creater_cnt;//アイテム生成を開始する時間（フレーム単位）ブロック生成から30フレームずらしてから起動
	//特定の条件を満たしたオブジェクトをvectorから削除する
	void delete_block();
	void delete_item();
	//リザルト表示
	ResultWindow* result;

	//1レベルごとの最大ブロック生成数の最大値
	int max_block;
	int delete_block_cnt;

	void map_set();//マップデータをセットする

	//背景を格納する配列
	std::vector<BackGround> back_grounds;
};

//他のクラスでも使用するためcs->game->と長く続くのを阻止
namespace model {
	//キャラクター
	extern std::unique_ptr<Player> player;
	//オブジェクト
	extern std::unique_ptr<std::vector<std::unique_ptr<Block>>> blocks;
	extern std::unique_ptr<std::vector<std::unique_ptr<Item>>> items;
}

namespace control {
	//マップ
	extern std::unique_ptr<Map> map;
	//ゲーム上のフラグ
	extern std::unique_ptr<Engine> engine;
}