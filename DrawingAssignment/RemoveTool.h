#pragma once
#include "Tool.h"
#include "Data.h"

class RemoveTool : public Tool
{
public:
	RemoveTool();
	~RemoveTool();

	void doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics);
};

inline void RemoveTool::doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics) {
	Data::getData()->removeShape(Data::getData()->returnShapeIndex(x , y));
}
