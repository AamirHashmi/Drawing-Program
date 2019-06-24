#pragma once
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(int x, int y, double radius);
	~Circle();
	
	void draw(EasyGraphics* easyGraphics);
	void edit(int x, int y, int x2, int y2);
	bool clicked(int clickX, int clickY);
	void move(int mx, int my, int clickX, int clickY);
	const int getX2();
	const int getY2();
	const double getRadius();

private:
	double radius;

};

inline Circle::Circle(int x, int y, double radius) : Shape(x,y), radius(radius){}


inline const int Circle::getX2() {
	return 0;
}

inline const int Circle::getY2() {
	return 0;
}

inline const double Circle::getRadius() {
	return radius;
}