#pragma once
#include "EasyGraphics.h"
#include "Button.h"
#include "Data.h"
#include "SquareTool.h"
#include "CircleTool.h"
#include "RemoveTool.h"
#include "RedFillTool.h"
#include "GreenFillTool.h"
#include "BlueFillTool.h"
#include "RedPen.h"
#include "BluePen.h"
#include "GreenPen.h"
#include "Slider.h"
#include "SaveTool.h"
#include "LoadTool.h"
#include "ChangeColourTool.h"
#include <algorithm>

class UserInterface : public EasyGraphics
{
public: 
	UserInterface();
	~UserInterface();
	void onDraw();
	void reDraw();
	bool isButtonClicked(int x, int y);
	void onLButtonDown(UINT nFlags, int x, int y);
	void onLButtonUp(UINT nFlags, int x, int y);
	void onMouseMove(UINT nFlags, int x, int y);
	void setBtnsFalse();

private:
	int mouseDownX;
	int mouseDownY;
	bool clicked;
	Button* selected;
	Slider* slider;
	std::vector<Button*> buttons;
}; 







