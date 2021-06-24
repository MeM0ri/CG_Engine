#pragma once
#include "Window.h"
#include "MeMoriTimer.h"

class App
{
public:
	App();
	int Go(); //master frame/message loop
private:
	void DoFrame();
private:
	Window wnd;
	MeMoriTimer timer;
};