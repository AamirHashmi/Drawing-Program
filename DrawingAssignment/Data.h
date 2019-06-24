#pragma once
//#include "Button.h"
#include "Square.h"
#include "Circle.h"
#include "Line.h"
#include "Brush.h"
#include<fstream>
#include <algorithm>

using namespace std;

struct coordinate {
	int x;
	int y;
};

class Data 
{
public:
	~Data();
	static Data* getData();
	void drawSquare(int x, int y, int x2, int y2, EasyGraphics* easyGraphics);
	void drawCircle(int x, int y, EasyGraphics* easyGraphics);
	void drawLine(int x, int y, int x1,int y1, EasyGraphics* easyGraphics);
	void removeShape(int index);
	void moveShape(int index, int x, int y, int x2, int y2, int mouseDownX, int mouseDownY);
	void selectShape(int x, int y);

	int returnShapeIndex(int x, int);

	bool shapeClick(int x, int y);
	void setPenThickness(int thickness);

	void save();
	void load();
	void drawBrush(int x, int y, EasyGraphics* easyGraphics);


	
	void reDraw(EasyGraphics* easyGraphics);

	//void initialiseButtons(EasyGraphics* easyGraphics);
	//int returnClicked(int x, int y);
	//vector<Button*>getButtonsVector();
	Shape* getTopShape();

	void setPenColour(int colour);
	void setFillColour(int colour);

	int getFillColour();
	int getPenColour();

	void changeColour(int index);

	//bool isClicked(int x, int y);
	

private:
	Data();
	static Data* instantiation;

	//vector<Button*> buttons;
	vector<Shape*> shapes;
	int penColour;
	int fillColour;
	int penWidth;

	int saveSize;
	Shape* selectedShape;
	vector<coordinate*>brushPoints;
	
};

inline Data::Data(){
	//type = 9;
	//buttons.push_back(new Button(40, 500, 1));
	//SquareTool* s;
	//buttons.at(0)->setTool(s);
	//buttons.push_back(new Button(100, 500, 2));
	//buttons.push_back(new Button(160, 500, 3));
	penWidth = 2;
	penColour = EasyGraphics::clRed;
	fillColour = EasyGraphics::clRed;

	
}

inline Data::~Data(){
	for (std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++) {
		delete *it;
		*it = nullptr;
	}
	shapes.clear();



	for (std::vector<coordinate*>::iterator it = brushPoints.begin(); it != brushPoints.end(); it++) {
		delete *it;
		*it = nullptr;
	}

	delete selectedShape;
	delete instantiation;
	selectedShape = nullptr;
	instantiation = nullptr;
}

inline Shape* Data::getTopShape() {
	return shapes.at(shapes.size()-1);
}

inline void Data::setPenColour(int colour) {
	penColour = colour;

}

inline void Data::setFillColour(int colour) {
	fillColour = colour;
}

inline int Data::getFillColour() {
	return fillColour;
}

inline int Data::getPenColour() {
	return penColour;
}

inline void Data::setPenThickness(int thickness) {
	penWidth = thickness;
}



inline void Data::selectShape(int x, int y) {
	selectedShape = shapes.at(returnShapeIndex(x, y));
	/*if (selectedShape->isSelected()) {
		selectedShape->setSelected(false);
		//selectedShape = nullptr;
	}
	else {
		selectedShape->setSelected(true);
	}*/
	
}


