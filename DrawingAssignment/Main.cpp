#include <Windows.h>
#include "UserInterface.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cpCmdLine, int show)
{

#ifdef _DEBUG
	//_CrtSetBreakAlloc(232);
	_onexit(_CrtDumpMemoryLeaks);
#endif
	UserInterface ui;
	ui.setImmediateDrawMode(false);
	ui.create(hInstance, 800, 600, 40, true);

	return 0;
}
