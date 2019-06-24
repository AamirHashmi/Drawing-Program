#pragma once
#include "Tool.h"
#include "Data.h"


class SquareTool : public Tool
{
public:
	SquareTool();
	~SquareTool();

	void doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics);
};

inline void SquareTool::doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics) {
	
	Data::getData()->drawSquare(x, y, x2, y2, easyGraphics);
}