#pragma once
#include "FillTool.h"
#include "Data.h"
class BlueFillTool :
	public FillTool
{
public:
	BlueFillTool();
	~BlueFillTool();

	void doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics);
};


inline void BlueFillTool::doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics) {
	Data::getData()->setFillColour(EasyGraphics::clBlue);
}
