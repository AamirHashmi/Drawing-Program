#pragma once
#include "Shape.h"

class Square : public Shape
{
public:
	Square(int x, int y, int height, int width);
	~Square();

	const int getWidth();
	const int getHeight();
	void setWidth(int newWidth);
	void setHeight(int newHeight);
	void draw(EasyGraphics* easyGraphics);
	void edit(int x, int y, int x2, int y2);
	bool clicked(int clickedX, int clickedY);
	void move(int mx, int my, int clickX, int clickY);
	const int getX2();
	const int getY2();

private:
	int width;
	int height;
};

inline Square::Square(int x, int y, int height, int width) : Shape(x, y), height(height), width(width) {} //change to constrictor initialisation list and add colour

inline void Square::setWidth(int newWidth) {
	width = newWidth;
}

inline void Square::setHeight(int newHeight) {
	height = newHeight;
}

inline const int Square::getWidth() {
	return width;
}

inline const int Square::getHeight() {
	return height;
}

inline void Square::move(int mx, int my, int clickX, int clickY) {
	x = mx;
	y = my;
}

inline const int Square::getX2() {
	return 0;
}

inline const int Square::getY2() {
	return 0;
}