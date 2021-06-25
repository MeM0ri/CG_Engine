#pragma once
#include "Window.h"
#include "MeMoriTimer.h"

class App
{
public:
	App();
	int Go(); //master frame/message loop
	~App();
private:
	void DoFrame();
private:
	Window wnd;
	MeMoriTimer timer;
	std::vector<std::unique_ptr<class Drawable>> drawables;
	static constexpr size_t nDrawables = 180;
};