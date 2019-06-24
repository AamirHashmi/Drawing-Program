#pragma once
#include "Tool.h"
class PenColourTool : public Tool
{
public:
	PenColourTool();
	~PenColourTool();

	int getColour();

private:
	int colour;
};

inline int PenColourTool::getColour() {
	return colour;
}