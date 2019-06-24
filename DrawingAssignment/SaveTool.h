#pragma once
#include "Tool.h"
#include "Data.h"

class SaveTool :
	public Tool
{
public:
	SaveTool();
	~SaveTool();

	void doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics);
};

inline void SaveTool::doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics) {
	Data::getData()->save();
}

