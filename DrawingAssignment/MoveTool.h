#pragma once
#include "Tool.h"
#include "Data.h"
class MoveTool :
	public Tool
{
public:
	MoveTool();
	~MoveTool();

	void doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics);
};

inline void MoveTool::doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics) {
	
	Data::getData()->moveShape(Data::getData()->returnShapeIndex(x, y), x, y, x2, y2,  mouseDownX,  mouseDownY);
}