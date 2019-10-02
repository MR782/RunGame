#include "Engine.h"
//-------------------------------------
// 実体化
//-------------------------------------
bool Engine::gameoverFlag;//ゲームオーバーを判断するフラグ
bool Engine::fade_ioFlag;//フェードを管理するフラグ
int Engine::score;//スコア
int Engine::level;//ゲーム難易度

void Engine::initialize()
{
	//初期化
	gameoverFlag = false;
	fade_ioFlag = false;
	score = 0;
	level = 1;
}

void Engine::set_gameoverFlag(bool fg)
{
	if (gameoverFlag != fg) {//現在のフラグの状態と引数の値が違うなら
		gameoverFlag = fg;//更新
	}
}

void Engine::set_fade_ioFlag(bool flag)
{
	fade_ioFlag = flag;
}

void Engine::set_score(int point)
{
	score = point;
}

void Engine::set_level(int lv)
{
	//レベルは1~15の中で変動する
	if (lv < 15 && lv > 0) {
		level = lv;
	}
}

bool Engine::get_gameoverFlag()
{
	return gameoverFlag;
}

bool Engine::get_fade_ioFlag()
{
	return fade_ioFlag;
}

int Engine::get_score()
{
	return score;
}

int Engine::get_level()
{
	return level;
}
