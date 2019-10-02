#pragma once
//画面サイズ(ドット)
#define ScreenSize_X 640
#define ScreenSize_Y 480
//プレイヤー関連
#define PlayerJumpPower -15
#define PlayerMovementX -5 //1フレーム当たりの移動量
//フェードインアウトのスピード
#define FeedSpeed 5 //1フレーム当たりのフェードイン・アウトのスピード
//地面の大きさ
#define GroundHeight 32 //32ドット
//ブロックの関連 ドット換算
#define BlockPos1 320- 64
#define BlockPos2 320 - 64 - 130
#define Block_Size 32
#define BlockDefaultSpeed -5 //1フレーム当たりの移動量
#define SpawnBlockTiming 60 //60フレーム
//アイテム ドット換算
#define ItemPos1 320 - 64
#define ItemPos2 320 - 64 - 130
#define ItemDefaultSpeed -5 //1フレーム当たりの移動量
#define ItemSize 32
#define SpawnItemTiming 60//60フレーム

//ゲームシーン
#define Start_SpawnItem 30 //アイテムの生成装置を稼働開始する時間（フレーム）
#define BackGroundDefaultSpeed 5 //1フレーム当たりの移動量

//UI　ラベルの座標
#define ScoreLabelPositionX 200
#define ScrreLabelHeaderPositionX 200
#define ScoreLabelPositionY 0
#define ScoreLabelHeaderPositionY 32
#define ScoreLabelPositionYAfter 320 / 2.0 - 130
#define ScoreLabelHeaderPositionAfter 320 / 2.0f - 130 + 32

//タイトルシーン
#define TitleLogoPosY 64
//雲の大きさ
#define CloudWidth 64 // ドット
#define CloudHeight 32 // ドット
#define SpawnCloudTiming 60//60フレーム