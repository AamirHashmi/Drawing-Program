#pragma once
#include "EasyGraphics.h"
#include <string>
#include "Tool.h"
#include "SquareTool.h"
#include "LineTool.h"
#include "CircleTool.h"
#include "RemoveTool.h"
#include "MoveTool.h"
#include "RedFillTool.h"
#include "GreenFillTool.h"
#include "BlueFillTool.h"
#include "RedPen.h"
#include "BluePen.h"
#include "GreenPen.h"
#include "SaveTool.h"
#include "LoadTool.h"
#include "ChangeColourTool.h"
#include "PenTool.h"

using namespace std;
class Button 
{
public:
	Button(int x, int y, const wchar_t* imageFileName, Tool* tool); //1 = line  2 = square  3=...
	~Button();

	int getX();
	int getY();
	int getWidth();
	int getHeight();
	bool clicked(int clickX, int clickY);
	void drawButton(EasyGraphics* easyGraphics);
	int getTypeOfButton();
	void useTool(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics);
	bool isSelected();
	void setSelected(bool value);


	void setTool(Tool* newTool); //cahnge laytegr
	Tool* getTool();

private:
	int x;
	int y;
	int width;
	int height;
    const wchar_t* imageFileName;
	int typeOfButton;
	Tool* currentTool;
	bool selected;
	
};


inline void Button:: setTool(Tool* newTool) {
	currentTool = newTool;
}

//add to vector

inline int Button::getX() {
	return x;
}

inline int Button::getY() {
	return y;
}

inline int Button::getWidth() {
	return width;
}

inline int Button::getHeight() {
	return height;
}

inline int Button::getTypeOfButton() {
	return typeOfButton;
}


inline Tool* Button::getTool() {
	return currentTool;
}

inline bool Button::isSelected() {
	return selected;
}

inline void Button::setSelected(bool value) {
	selected = value;
}