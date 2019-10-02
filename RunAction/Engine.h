#pragma once


//ゲームを通して必要なものの定義

class Engine {
private:
	static bool gameoverFlag;//ステージ内で死亡したか判断する
	//false : フェードイン　true : フェードアウト
	static bool fade_ioFlag;
	//スコア
	static int score;
	//ゲームのレベル
	static int level;
public:
	static void initialize();
	//フラグや値をセットする
	static void set_gameoverFlag(bool);//死亡フラグ
	//false : フェードイン　true : フェードアウト
	static void set_fade_ioFlag(bool);
	//スコアをセット
	static void set_score(int);
	//難易度をセット
	static void set_level(int);

	//値を受け取る
	static bool get_gameoverFlag();
	static bool get_fade_ioFlag();
	static int get_score();
	static int get_level();
};