#pragma once
#include "PenColourTool.h"
#include "Data.h"
class RedPen :
	public PenColourTool
{
public:
	RedPen();
	~RedPen();

	void doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics);
};

inline void RedPen::doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics) {
	Data::getData()->setPenColour(EasyGraphics::clRed);
}