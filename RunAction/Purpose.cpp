﻿#include "Purpose.h"

Rect::Rect()
{
	x = 0;
	y = 0;
	w = 0;
	h = 0;
}

Rect::Rect(int x_, int y_, int w_, int h_)
{
	x = x_;
	y = y_;
	w = w_;
	h = h_;
}

Rect::Rect(float x_, float y_, float w_, float h_)
{
	x = (int)x_;
	y = (int)y_;
	w = (int)w_;
	h = (int)h_;
}

Rect Rect::operator<<(Rect & r_)
{
	*this = r_;
	return *this;
}

bool Rect::Hit(Rect rect_)
{
	if (this->x < rect_.x + rect_.w &&
		this->x + this->w > rect_.x &&
		this->y < rect_.y + rect_.h &&
		this->y + this->h > rect_.y) {
		return true;
	}
	return false;
}

bool Rect::Hit(int point_x, int point_y)
{
	if (this->x > point_x &&
		this->x + this->w < point_x &&
		this->y > point_y &&
		this->y + this->h < point_y) {
		return true;
	}
	return false;
}

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(int x_, int y_)
{
	x = (float)x_;
	y = (float)y_;
}

Vector2::Vector2(float x_, float y_)
{
	x = x_;
	y = y_;
}

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

Point::Point(int x_, int y_)
{
	this->x = x_;
	this->y = y_;
}

Point::Point(float x_, float y_)
{
	this->x = (int)x_;
	this->y = (int)y_;
}
