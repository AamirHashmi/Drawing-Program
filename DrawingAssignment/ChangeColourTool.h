#pragma once
#include "Tool.h"
#include "Data.h"
class ChangeColourTool :
	public Tool
{
public:
	ChangeColourTool();
	~ChangeColourTool();

	void doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics);

};

inline void ChangeColourTool::doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics) {
	Data::getData()->selectShape(x, y);
	Data::getData()->changeColour(Data::getData()->returnShapeIndex(x, y));
	
}
