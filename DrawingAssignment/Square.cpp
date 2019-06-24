#include "Square.h"


Square::~Square()
{
}

void Square::draw(EasyGraphics* easyGraphics) {

	/*if (selected) {
		easyGraphics->setPenColour(EasyGraphics::clGrey, penWidth + 10);
		easyGraphics->drawRectangle(x, y, width, height, true);
	}*/
	easyGraphics->setPenColour(colour, penWidth);
	easyGraphics->selectBackColour(fillColour);
	easyGraphics->drawRectangle(x, y, width, height, true);
}

void Square::edit(int x, int y, int x2, int y2) {
	width = x2 - x;
	height = y2 - y;
}

bool Square::clicked(int clickX, int clickY) {


	if ((clickX >= getX()) && (clickX <= (getX() + getWidth())) && (clickY >= getY()) && (clickY <= (getY() + getHeight())))
	{
		return true;

	}
	else if ((width < 0) || (height < 0)) {
		if ((clickX <= x) && (clickX >= (x + width)) && (clickY >=y) && (clickY <= (y + height)))
		{
			return true;
		}
		else if ((clickX <= x) && (clickX >= (x + width)) && (clickY <= y) && (clickY >= (y + height)))
		{
			return true;
		}
		else if ((clickX >= x) && (clickX <= (x + width)) && (clickY <= y) && (clickY >= (y + height)))
		{
			return true;
		}
	}

	return false;
}