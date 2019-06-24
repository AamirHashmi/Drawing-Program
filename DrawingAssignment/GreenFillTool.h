#pragma once
#include "FillTool.h"
#include "Data.h"

class GreenFillTool :
	public FillTool
{
public:
	GreenFillTool();
	~GreenFillTool();

	void doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics);
};



inline void GreenFillTool::doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics) {
	Data::getData()->setFillColour(EasyGraphics::clGreen);
}