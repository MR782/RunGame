#pragma once
#include"GameScene.h"
#include"TitleScene.h"
#include<memory>

//シーン管理
enum Scene {
	title,//タイトル
	game//ゲームシーン
};

class CoreScene {
private:
	Scene scene;
public:
	//メソッド
	CoreScene();
	~CoreScene();
	void initialize();//全シーンの初期化
	void finalize();//全シーンの最終処理を行う
	void update();//シーンごとのupdate()を呼ぶ
	void draw();//シーンごとのdraw()を呼ぶ(ポーズなどでゲームのdraw()のみ呼びたいときのため作成)
	void scene_change(Scene);
	//メンバ変数
	std::unique_ptr<GameScene> game;  //ゲームシーン
	std::unique_ptr<TitleScene> title;//タイトルシーン
};

extern CoreScene *core;