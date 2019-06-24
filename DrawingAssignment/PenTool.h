#pragma once
#include "Tool.h"
#include "Data.h"
class PenTool :
	public Tool
{
public:
	PenTool();
	~PenTool();
	void doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics);
};

inline void PenTool::doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics) {
	//Data::getData()->addPoint(x, y);
	Data::getData()->drawBrush( x, y, easyGraphics);
}