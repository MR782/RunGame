#include "CreateMap.h"
#include"./dxlib/DxLib.h"
#include<fstream>
#include <sstream>

//マップ生成ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー

std::vector<std::shared_ptr<MapObject>> CreateMap::mapobj;

void CreateMap::init()
{
	std::ifstream mappath("./json/Mapdata.json");//jsonファイル指定し読み込む
	if (mappath.fail()) throw std::runtime_error("mapfile.json is not found");//見つからなかったら例外処理
	//Jsonを使用するための準備----------------
	json11::Json mapdata;
	std::istreambuf_iterator<char> it(mappath);
	std::istreambuf_iterator<char> last;
	std::string json_str(it, last);
	std::string err;
	mapdata = json11::Json::parse(json_str, err);
	//-----------------------------------------
	for (auto& item : mapdata["Map"].array_items()) {//Mapの中のアイテムの数繰り返す
		std::shared_ptr<MapObject> obj = std::make_shared<MapObject>();
		//基礎データ登録---------------------------------------------
		obj->chip_size = item["chipsize"].int_value();//チップ１つの大きさを読み込む
		obj->map_maxX = item["mapMaxX"].int_value();//マップのX軸の大きさ
		obj->map_maxY = item["mapMaxY"].int_value();//マップのY軸の大きさ
		obj->chipNumwidth = item["chipNumwidth"].int_value();//チップを画像にしたとき当たり判定を行うチップを設定(6なら6以上の全てと判定)
		obj->chippath = item["chippath"].string_value();//マップチップのファイルパス
		obj->datapath = item["datapath"].string_value();//マップデータのファイルパス
		obj->name = item["name"].string_value();//ステージ番号などデータの識別番号
		//マップデータ入力-------------------------------------------
		std::ifstream m_data(obj->datapath.c_str());
		for (int y = 0; y < obj->map_maxY / obj->chip_size; ++y) {
			std::string lineText;
			getline(m_data, lineText);
			std::istringstream ss_lt(lineText);
			for (int x = 0; x < obj->map_maxX / obj->chip_size; ++x) {
				std::string  tc;
				getline(ss_lt, tc, ',');// , で区切ってデータを入れる
				std::stringstream ss;
				ss << tc;
				ss >> obj->data[y][x]; //データを入れる エラーが起こる
			}
		}
		m_data.close();//ファイルを閉じる
		//--------------------------------------------------------------
		//チップ画像登録
		obj->chipgraph = LoadGraph(obj->chippath.c_str());//チップ画像格納

		mapobj.push_back(std::move(obj));//登録して１つ進める
	}

	mappath.close();
}

void CreateMap::finalize()
{
	//データの数文画像を削除する
	for (auto itr = mapobj.begin(); itr != mapobj.end(); ++itr) {
		DeleteGraph((*itr)->chipgraph);
	}
	mapobj.clear();//vector削除
}

CreateMap::~CreateMap()
{
	mapobj.clear();
}

std::shared_ptr<MapObject> CreateMap::get(std::string name)
{
	std::shared_ptr<MapObject> ret = nullptr;//空っぽの状態
	for (auto itr = mapobj.begin(); itr != mapobj.end(); ++itr) {
		if ((*itr)->name == name) {//その番号があるなら
			ret = (*itr);//そのオブジェクトを返す
		}
	}
	return ret;
}

//ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー
