#pragma once
#include "PenColourTool.h"
#include "Data.h"
class BluePen :
	public PenColourTool
{
public:
	BluePen();
	~BluePen();

	void doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics);
};

inline void BluePen::doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics) {
	Data::getData()->setPenColour(EasyGraphics::clBlue);
}