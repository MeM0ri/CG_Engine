#pragma once
#include "Window.h"
#include "MeMoriTimer.h"
#include "ImguiManager.h"
#include "Camera.h"
#include "PointLight.h"

class App
{
public:
	App();
	int Go(); //master frame/message loop
	~App();
private:
	void DoFrame();
private:
	ImguiManager imgui;
	Window wnd;
	MeMoriTimer timer;
	std::vector<std::unique_ptr<class Drawable>> drawables;
	float speed_factor = 1.0f;
	Camera cam;
	PointLight light;
	static constexpr size_t nDrawables = 50;
};