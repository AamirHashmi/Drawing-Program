#pragma once
#include "EasyGraphics.h"
class Shape
{
public:
	Shape(int x, int y);
	Shape();
	~Shape();
	
	const int getX();
	const int getY();
	void setColour(int newColour);
	int getColour();
	void setX(int newX);
	void setY(int newY);
	void setFillColour(int newColour);
	int getFillColour();
	void setPenWidth(int width);
	int getPenWidth();
	void setSelected(bool selected);
	bool isSelected();
	
	virtual void draw(EasyGraphics* easyGraphics) = 0;
	virtual void edit();
	virtual bool clicked(int clickedX, int clickedY)=0;
	virtual void move(int x, int y, int clickX, int clickY) = 0;
	virtual const int getX2() = 0;
	virtual const int getY2() = 0;

protected:
	int x;
	int y;
	int colour;	
	int fillColour;
	int penWidth;
	bool selected;

};

inline Shape::Shape(int x, int y) : x(x), y(y) {
	
}

inline void Shape::edit(){}


inline Shape::Shape(){}

inline const int Shape::getX() {
	return x;
}

inline const int Shape::getY() {
	return y;
}

inline void Shape::setX(int newX) {
	x = newX;
}

inline void Shape::setY(int newY) {
	y = newY;
}

inline void Shape::setColour(int newColour) {
	colour = newColour;
}

inline int Shape::getColour() {
	return colour;
}

inline void Shape::setFillColour(int newColour) {
	fillColour = newColour;
}

inline int Shape::getFillColour() {
	return fillColour;
}

inline void Shape::setPenWidth(int width) {
	penWidth = width;
}
inline int Shape::getPenWidth() {
	return penWidth;
}

inline bool Shape::isSelected() {
	return selected;
}
inline void Shape:: setSelected(bool selected) {
	this->selected = selected;
}