#include "Button.h"

Button::Button(int x, int y, const wchar_t* imageFileName, Tool* tool) : x(x), y(y), imageFileName(imageFileName), currentTool(tool) {
	width = 55;
	height = 55;
	selected = false;
}

Button::~Button()
{
	delete currentTool;
}

void Button::useTool(int x, int y, int x2, int y2, int mouseDownX, int mouseDownY, EasyGraphics* easyGraphics) {
	currentTool->doAction(x, y, x2, y2, mouseDownX, mouseDownY, easyGraphics);
}

void Button::drawButton(EasyGraphics* easyGraphics) {
	if (selected) {
		easyGraphics->setPenColour(EasyGraphics::clYellow, 10);
		easyGraphics->drawRectangle(x, y, width, height, true);
	}
	easyGraphics->setPenColour(EasyGraphics::clWhite, 2);
	//easyGraphics->drawRectangle(x, y, width, height, true);
	easyGraphics->drawBitmap(imageFileName, x, y, width, height, 1);
}

bool Button::clicked(int clickX, int clickY) {
	if (clickX >= x && clickX <= (x + width) && clickY >= y && clickY <= (y + height)) {
		return true;
	}
	else {
		return false;
	}
}