#include "Resource.h"
#include"./dxlib/DxLib.h" 
#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include "json11.hpp"

std::vector<std::shared_ptr<GraphicObject>> GraphicResource::graph;

//-----------------------------------------------
//Jsonからの読み込みなど
//------------------------------------------------

int GraphicResource::load(std::string _scope)
{
	//scopeの文字列の画像をjsonから検索し、読み込む
	//読み込んだ枚数を返す
	int ret = 0;
	for (auto itr = graph.begin(); itr != graph.end(); ++itr) {
		if ((*itr)->exist == false) {	//オブジェクトが未登録
			if ((*itr)->exits_scope(_scope)) {		//scopeが存在している
				register_graph(*(*itr));//登録
				ret++;//総合数増加
			}
		}
	}
	return ret;
}

void GraphicResource::delete_all()
{
	for (auto itr = graph.begin(); itr != graph.end(); ++itr) {
		if ((*itr)->exist == true) {	//オブジェクトが登録済み
			//シートの分だけ絵を削除する
			for (int i = 0; i < (*itr)->sheets; i++) {
				DeleteGraph(*((*itr)->handle + i));
			}
		}
		delete (*itr)->handle;
	}
}

void GraphicResource::init()
{
	std::ifstream file("./json/resource.json");
	//例外処理
	if (file.fail()) throw std::runtime_error("resource file not found");
	json11::Json json;//Jsonの変数を用意
	std::istreambuf_iterator<char> it(file);
	std::istreambuf_iterator<char> last;
	std::string json_string(it, last);//Json(string型)
	std::string err;
	//Json11で使用できるよう変換
	json = json11::Json::parse(json_string, err);
	//登録
	for (auto &item : json["graph"].array_items()) {
		std::shared_ptr<GraphicObject> obj = std::make_shared<GraphicObject>();
		obj->exist = false;
		obj->name = item["name"].string_value();
		obj->path = item["path"].string_value();
		obj->vertical = item["vertical"].int_value();
		obj->horizontal = item["horizontal"].int_value();
		obj->width = item["width"].int_value();
		obj->height = item["height"].int_value();
		obj->loop = item["loop"].bool_value();
		obj->interval = item["interval"].int_value();
		obj->sheets = item["sheets"].int_value();
		for (auto &scope : item["scope"].array_items()) {
			obj->scopes.push_back(scope.string_value());
		}
		obj->set_default_to_empty();
		graph.push_back(std::move(obj));
	}
	file.close();
}

std::shared_ptr<GraphicObject> GraphicResource::get(std::string name)
{
	std::shared_ptr<GraphicObject> ret = nullptr;//空っぽの状態
	for (auto itr = graph.begin(); itr != graph.end(); ++itr) {
		if ((*itr)->name == name) {//その名前があるなら
			ret = (*itr);//そのオブジェクトを返す
		}
	}
	return ret;
}

void GraphicResource::finalize()
{
	delete_all();
}

bool GraphicResource::exist_name(std::string name)
{
	//nameが存在しているか調べるメソッド
	bool ret = false;
	for (auto itr = graph.begin(); itr != graph.end(); ++itr) {
		if ((*itr)->name == name) {
			ret = true;
			break;
		}
	}
	return ret;
}

void GraphicResource::register_graph(GraphicObject& obj)
{
	if (obj.exist == false) {
		obj.handle = new int[obj.sheets];	//アニメーション画像のフレーム枚数分のハンドル領域を確保する
		obj.exist = true;
		LoadDivGraph(
			obj.path.c_str(),//ファイルパス
			obj.sheets,//画像を分割した際の全数
			obj.horizontal,//X方向の分割数
			obj.vertical,//Y方向の分割数
			obj.width,//画像の横の大きさ
			obj.height,//画像の縦の大きさ
			obj.handle//画像ハンドル
		);		//JSONに書かれた情報をLoadDivGraphから読み込む
	}
}

//-------------------------------------------------------
//グラフィックオブジェクト
//-------------------------------------------------------
void GraphicObject::set_default_to_empty()
{
	//デフォルト値の設定
	if (vertical == 0) vertical = 1;
	if (horizontal == 0) horizontal = 1;
	if (width == 0) width = 32;
	if (height == 0) height = 32;
	if (sheets == 0) sheets = vertical * horizontal;
}

bool GraphicObject::exits_scope(std::string _scope)
{
	bool check = false;
	for (auto&& scope : scopes) {//スコープの数繰り返す
		if (scope == _scope) {//スコープ発見
			check = true;//存在していることを証明
			break;
		}
	}
	return check;
}
