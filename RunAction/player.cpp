#include "player.h"
#include"ScreenSystem.h"
#include"CoreScene.h"
#include"define.h"
#include"KeyBoard.h"
#include"Audio.h"
#include"./dxlib/DxLib.h"

Player::Player(Rect rect_) :Object(rect_)
{
	this->name = "player";//オブジェクトの名前を設定
	//移動量の初期化
	this->velocity = { 0,0 };
	this->movement = { 0,0 };
}

void Player::initialize()
{
	//データの初期化
	this->rect = Rect(50, 170, 45, 47);//x,y,width,height 当たり判定矩形、描画位置
	//移動量の初期化
	this->velocity = { 0,0 };
	this->movement = { 0,0 };

	this->anime->set("player_run");//走りアニメーションに設定
}

void Player::finalize()
{
}

void Player::update()
{
	//移動処理
	move();
	//当たり判定------------------------------------------------------------------------
	//アイテムとの当たり判定
	for (auto itr = model::items->begin(); itr != model::items->end(); itr++) {
		if (this->rect.Hit((*itr)->get_rect())) {//アイテムとプレイヤーが当たっているなら
			(*itr)->receive(this->name);
		}
	}
}

void Player::dead_update()
{
	//死亡したら後退しながらジャンプして画面外に消える
	this->rigit->fall(this->velocity, this->movement.y);//Y軸の移動
	this->rect.x += (int)this->velocity.x;//移動X
	this->rect.y += (int)this->movement.y;//移動Y
	this->movement.y++;//地面に向けて加速する
}


void Player::receive(std::string name)
{
	if (name == "block") {
		//死亡
		this->velocity.y = 0;//死亡時の異常な跳ねを阻止
		this->movement.y = 0;//死亡時の異常な跳ねを阻止
		Engine::set_gameoverFlag(true);//ゲームオーバー
		core->game->set_GameState(GameScene::GameState::RESULT);//リザルト表示を行う
		//後退しながら飛び跳ねる処理
		this->velocity.x = PlayerMovementX;
		this->set_jumppower(PlayerJumpPower);
		//衝突音を鳴らす
		Audio::stop("game");//ゲームの本編のBGM停止
		Audio::play("hit");//ヒット音を鳴らす
	}
}

void Player::set_jumppower(float jumppow)
{
	this->movement.y += jumppow;//ジャンプ力をセットする
}

Vector2 Player::get_movement()
{
	return this->movement;
}


void Player::move()
{
	//SPACEキーが押されたら
	if (KeyBoard::key_down(KEY_INPUT_SPACE)) {
		if (this->rigit->check_foot(this->rect)) {//足元が地面に触れているなら
			//ジャンプ
			Audio::play("jump");//ジャンプ音を鳴らす
			this->anime->set("player_jump");//ジャンプアニメーションをセット
			set_jumppower(PlayerJumpPower);//ジャンプ力をセットする
		}
	}
	//重力やマップとの判定関係-------------------------------------------------
	this->rigit->fall(this->velocity, this->movement.y);//Y軸の移動(落下など)
	//マップチップ内にめり込まない移動----------------------------------------
	this->rigit->check_move(this->velocity, this->rect, this->hitflag);
	//着地判定-----------------------------------------------------------------
	if (this->rigit->check_foot(this->rect)) {//地面に触れているなら
		this->movement.y = 0;//Y軸の移動量を0にする
		this->anime->set("player_run");//走りアニメーションをセット
	}
	else {//地面に触れていないなら
		//落下するための加算
		this->movement.y += 0.7f;//地面に向けて加速する
	}
}
