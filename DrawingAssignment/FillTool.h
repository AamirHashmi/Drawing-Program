#pragma once
#include "Tool.h"
class FillTool :
	public Tool
{
public:
	FillTool();
	~FillTool();

	int getColour();

private:
	int colour;
};

inline int FillTool::getColour() {
	return colour;
}
