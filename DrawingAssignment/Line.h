#pragma once
#include "Shape.h"

class Line : public Shape
{
public:
	Line(int x, int y, int x2, int y2);
	~Line();

	void draw(EasyGraphics* easyGraphics);
	void edit(int x, int y);
	bool clicked(int clickX, int clickY);
	void move(int x, int y, int clickX, int clickY);
	const int getX2();
	const int getY2();

private:
	int x2, y2; 
};

inline Line::Line(int x, int y, int x2, int y2): Shape(x,y), x2(x2),y2(y2) {}




inline const int Line::getX2() {
	return x2;
}


inline const int Line::getY2() {
	return y2;
}