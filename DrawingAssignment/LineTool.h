#pragma once
#include "Tool.h"
#include "Data.h"


class LineTool : public Tool
{
public:
	LineTool();
	~LineTool();

	void doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics);
};

inline void LineTool::doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics) {

	Data::getData()->drawLine(x, y, x2, y2, easyGraphics);

}