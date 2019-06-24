#pragma once
#include "Tool.h"
#include "Data.h"


class CircleTool : public Tool
{
public:
	CircleTool();
	~CircleTool();

	void doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics);

};

inline void CircleTool::doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics) {

	Data::getData()->drawCircle(x, y, easyGraphics);
}