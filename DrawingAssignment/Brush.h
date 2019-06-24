#pragma once
#include "Shape.h"
#include <algorithm>

struct Point {
	int x;
	int y;
};
class Brush :
	public Shape
{
public:
	Brush(int x, int y);
	void addPoint(int x, int y);
	void draw(EasyGraphics* easyGraphics);
	~Brush();
	void edit(int x, int y);
	bool clicked(int clickX, int clickY);
	void move(int x, int y, int clickX, int clickY);
	const int getX2();
	const int getY2();

private:
	std::vector<Point*>points;
};

inline const int Brush::getX2() {
	return 0;
}

inline const int Brush::getY2() {
	return 0;
}

