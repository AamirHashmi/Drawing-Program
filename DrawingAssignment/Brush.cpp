#include "Brush.h"



Brush::Brush(int x, int y):Shape(x, y) 
{
}


Brush::~Brush()
{
	std::for_each(points.begin(), points.end(), [](Point* point){delete point;});
}

void Brush::addPoint(int x, int y) {
	Point* newPoint = new Point{x, y};
	points.push_back(newPoint);
}

void Brush::draw(EasyGraphics* easyGraphics) {

	easyGraphics->setPenColour(colour, penWidth);
	if (points.size()) {
		Point* lastPoint = points.at(0);
		for (unsigned i = 0; i < points.size(); i++)
		{
			Point* newPoint = points[i];
			easyGraphics->drawLine(lastPoint->x, lastPoint->y, newPoint->x, newPoint->y);
			lastPoint = newPoint;
		}

	}

}

void Brush::edit(int x, int y) {

}

void Brush::move(int x, int y, int clickX, int clickY) {
	//:/
}

bool Brush::clicked(int clickX, int clickY) {
	for (unsigned i = 0; i < points.size(); i++)
	{
		if (points.at(i)->x + 5 >= clickX && points.at(i)->x - 5 <= clickX) { //5 for offset
			if (points.at(i)->y + 5 >= clickY && points.at(i)->y - 5 <= clickY) {
				return true;
			}
		}
	}
	
	return false;
}
