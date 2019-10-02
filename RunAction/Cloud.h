#pragma once
#include"Object.h"

class Cloud : public Object {
	bool active;//¶‘¶ƒtƒ‰ƒO
public:
	Cloud(Rect);
	void update()override;
	void move()override;

	bool get_active();
};