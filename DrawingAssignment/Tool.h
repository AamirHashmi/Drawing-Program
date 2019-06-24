#pragma once
#include "EasyGraphics.h"

class Tool
{
public:
	Tool();
	~Tool();

	virtual void doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics) = 0;


};

inline void Tool::doAction(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics) {

}