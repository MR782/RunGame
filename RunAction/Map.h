#pragma once
#include"Purpose.h"
#include "json11.hpp"
#include"CreateMap.h"

//マップ

class Map {
private:
	std::shared_ptr<MapObject> object;//ゲーム内で使用するマップデータ
public:
	Map();
	~Map();//objectの中を削除
	void set(std::string stgnum);//データをセット
	//void draw();//画像描画(本作品ではマップチップを描画しない)
	bool map_hitcheck(Rect);//マップとの当たり判定
	void finalize();//チップ画像を削除
};