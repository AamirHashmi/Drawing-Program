#include "Circle.h"


Circle::~Circle()
{
}

void Circle::draw(EasyGraphics* easyGraphics) {
/*	if (selected) {
		easyGraphics->setPenColour(EasyGraphics::clGrey, penWidth + 10);
		easyGraphics->drawCircle(x, y, radius, true);
	}*/
	easyGraphics->setPenColour(colour, penWidth);
	easyGraphics->selectBackColour(fillColour);
	easyGraphics->drawCircle(x, y, radius, true);
}

void Circle::edit(int x, int y, int x2, int y2) {
	double a = pow((x - x2), 2);
	double b = pow((y - y2), 2);
	radius = sqrt(a + b);
}

bool Circle::clicked(int clickX, int clickY) {
	double a = pow((clickX - x), 2);
	double b = pow((clickY - y), 2);
	double distance = (sqrt(a + b));
	if (distance <= radius) {

		return true;
	}

	return false;

}

void Circle::move(int mx, int my, int clickX, int clickY) {
	x = mx;
	y = my;
}