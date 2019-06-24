#pragma once
#include "EasyGraphics.h"
#include "Data.h"

class Slider
{
public:
	Slider();
	~Slider();

	void draw(EasyGraphics* easyGraphics);
	void move(int y, int mouseDownY);
	bool clicked(int clickX, int clickY);
	void keepInBound();
	void incY(int inc);
	void setPenW();

private:
	int sliderWidth;
	int sliderHeight;

	int y;
	int x;

	int maxY;
	int minY;
	int pw;
};


inline void Slider::move(int y, int mouseDownY) {
	this->y = this->y - (mouseDownY - y);
}



inline void Slider::incY(int inc) {
	this->y += inc;
}

