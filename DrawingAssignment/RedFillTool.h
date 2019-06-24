#pragma once
#include "FillTool.h"
#include "Data.h"
class RedFillTool :	public FillTool
{
public:
	RedFillTool();
	~RedFillTool();

	void doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics);
};

inline void RedFillTool::doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics) {
	Data::getData()->setFillColour(EasyGraphics::clRed);
}