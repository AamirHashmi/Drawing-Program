#pragma once
#include "Tool.h"
#include "Data.h"
class LoadTool :
	public Tool
{
public:
	LoadTool();
	~LoadTool();

	void doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics);
};

inline void LoadTool::doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics) {
	Data::getData()->load();
}
