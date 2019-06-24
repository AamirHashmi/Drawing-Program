#include "Line.h"

Line::~Line()
{
}

void Line::draw(EasyGraphics* easyGraphics) {

	/*if (selected) {
		easyGraphics->setPenColour(EasyGraphics::clGrey, penWidth + 10);
		easyGraphics->drawLine(getX(), getY(), x2, y2);
	}*/
	easyGraphics->setPenColour(colour, penWidth);
	easyGraphics->selectBackColour(fillColour);
	easyGraphics->drawLine(getX(), getY(), x2, y2);
}

bool Line::clicked(int clickX, int clickY) {
	double differenceY = y2 - y;
	double differenceX = x2 - x;
	double gradient = (differenceY) / differenceX;

	if (clickX != x2) {
		double yInt = gradient * (clickX - x) + y;
		if (((yInt - 10) <= clickY) && (clickY <= (yInt + 10))) {
			return true;
		}
	}
	else if (((x - 10) <= clickX) && (clickX <= (x + 10))) {
		return true;
	}
	return false;

}

void Line::move(int x, int y, int clickX, int clickY) {

	this->x = x;
	this->y = y;

	this->x2 = clickX;
	this->y2 = clickY;
}

void Line::edit(int x, int y) {
	x2 = x;
	y2 = y;
}


