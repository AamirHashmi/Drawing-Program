#pragma once
#include "PenColourTool.h"
#include "Data.h"
class GreenPen :
	public PenColourTool
{
public:
	GreenPen();
	~GreenPen();

	void doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics);
};

inline void GreenPen::doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics) {
	Data::getData()->setPenColour(EasyGraphics::clGreen);
}