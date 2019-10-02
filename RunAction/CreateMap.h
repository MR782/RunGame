#pragma once
#include"Purpose.h"
#include "json11.hpp"

//マップの作成

class MapObject {
private:
public:
	//マップの最大サイズ(データとしての大きさ)
	int map_maxX;
	int map_maxY;
	//チップ一つのサイズ
	int chip_size;
	//マップのデータ配列
	int data[10][15];
	//チップ画像格納
	int chipgraph;
	int chipNumwidth;
	//チップ画像ファイルパス
	std::string chippath;
	//データファイルパス
	std::string datapath;
	//ステージ番号
	std::string name;
};

class CreateMap {
private:
	static std::vector<std::shared_ptr<MapObject>> mapobj;//jsonから読み込んだ際のデータを格納する配列
public:
	~CreateMap();
	static std::shared_ptr<MapObject> get(std::string stgnum);	//番号を持つオブジェクトポインタを返す
	static void init();//データ登録
	static void finalize();//メモリの開放
};
