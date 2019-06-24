#include "Slider.h"

Slider::Slider() {
	sliderWidth = 40;
	sliderHeight = 10;
	x = 730;
	y = 45;
	maxY = 40;
	minY = 100;
}

void Slider::draw(EasyGraphics* easyGraphics) {
	easyGraphics->setPenColour(EasyGraphics::clBlack, 3);
	easyGraphics->drawLine(750, minY, 750, maxY);
	easyGraphics->drawRectangle(x, y, sliderWidth, sliderHeight, true);

}

Slider::~Slider(){

}

void Slider::setPenW() {

	if (y>40 && y < 50) {
		pw = 2;
	}

	if (y>50 && y < 60) {
		pw = 5;
	}


	if (y>60 && y < 70) {
		pw = 10;
	}

	if (y>70 && y < 80) {
		pw = 15;
	}

	if(y>70 && y < 80) {
		pw = 20;
	}

	if (y>80 && y < 90) {
		pw = 25;
	}

	if (y>90 && y < 100) {
		pw = 30;
	}

	Data::getData()->setPenThickness(pw);
}

bool Slider::clicked(int clickX, int clickY) {
	if (clickX >= x && clickX <= (x + sliderWidth) && clickY >= y && clickY <= (y + sliderHeight)) {
		return true;
	}
	else {
		return false;
	}
}

void Slider::keepInBound() {


	if (y <= minY) {
		y += 10;
	}
	if (y >= maxY) {
		y -= 10;
	}
}