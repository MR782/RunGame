﻿#pragma once
#include<iostream>
#include"json11.hpp"

//音楽ファイルの読み込みや再生を行う

class AudioObject {
	friend class Audio;
	bool exist;//読み込んで膝窩のフラグ
	std::vector<std::string> scopes;//読み込み時の名前

	bool exist_scope(std::string);
	void set_default();//値が入っていない場合デフォルトで入力
public:
	bool loop;//ループ再生するかのフラグ
	std::string  name;//再生又は停止時にどれか判断する識別子
	std::string  path;//音楽ファイルまでのパス
	int handle;//音楽ハンドル
};

class Audio {
private:
	static std::vector<std::shared_ptr<AudioObject>> audioobj;
	static void register_audio(AudioObject&);
public:
	static void init();
	static void play(std::string name);
	static int load(std::string name);
	static void stop(std::string name);
	static bool check_play(std::string);//特定のBGMが再生中か調べる
	static void finalize();
};