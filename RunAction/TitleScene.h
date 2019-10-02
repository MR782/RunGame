#pragma once
#include"Purpose.h"
#include"BasicUI.h"
#include"Cloud.h"
#include"CloudCreater.h"

class TitleScene {
	int back_graph;//”wŒi‰æ‘œ
	int cloud_graoh;//”wŒi‚Ì‰_‚Ì‰æ‘œ
	Text title_logo;//ƒ^ƒCƒgƒ‹ƒƒS
	Text control_guide;//à–¾—pƒeƒLƒXƒg

	std::unique_ptr<CloudCreater> cloud_creater;//‰_‚Ì¶¬‘•’u
public:
	TitleScene();
	~TitleScene();
	void initialize();
	void finalize();
	void update();
	void draw();
};

extern std::unique_ptr<std::vector<std::unique_ptr<Cloud>>> clouds;