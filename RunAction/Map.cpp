#include "Map.h"
#include"./dxlib/DxLib.h"
#include"CoreScene.h"
#include"ScreenSystem.h"

//マップ処理

Map::Map()
{
}

Map::~Map()
{
	object.reset();
}

void Map::set(std::string stgnum)
{
	//CreateMapから名前の一致するものをセットする
	//ZeroMemory(this->object->data, sizeof(this->object->data));//マッパ配列を空にしておく
	object = CreateMap::get(stgnum);//マップのデータをセットする
}

//void Map::draw()
//{
//	Rect map = {
//		0,
//		0,
//		object->map_maxX,
//		object->map_maxY
//	};
//	//ループ範囲決定(最初からマップの最下段まで)
//	int sx = 0;
//	int sy = 0;
//	int ex = object->map_maxX / object->chip_size;
//	int ey = object->map_maxY / object->chip_size;
//	//描画処理
//	for (int y = sy; y <= ey; ++y) {
//		for (int x = sx; x <= ex; ++x) {
//			//マップを描画
//			DrawRectGraph((x * object->chip_size),//描画座標　 - control::camera->get_range().x
//				(y * object->chip_size),//描画座標　 - control::camera->get_range().y
//				(object->data[y][x] % object->chipNumwidth) * object->chip_size, //描画始点X(画像内での)
//				(object->data[y][x] / object->chipNumwidth) * object->chip_size,//描画始点Y(画像内での)
//				object->chip_size, object->chip_size,//幅(W,H)
//				object->chipgraph,TRUE);//ファイルパス 透過を実施するか
//		}
//	}
//}

bool Map::map_hitcheck(Rect rect_)
{
	bool check = false;
	//ループを回す範囲を決定
	int sx = rect_.x / object->chip_size;
	int sy = rect_.y / object->chip_size;
	int ex = (rect_.x + rect_.w - 1) / object->chip_size;
	int ey = (rect_.y + rect_.h - 1) / object->chip_size;

	//指定した範囲内で当たり判定を繰り返す
	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; x <= ex; ++x) {
			if (object->data[y][x] >= object->chipNumwidth) {//マップ番号が設定数以上なら
				//当たっていることにする
				check = true;
			}
		}
	}
	return check;
}

void Map::finalize()
{
	//画像を排除する
	DeleteGraph(object->chipgraph);
}

