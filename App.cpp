#include "App.h"
#include <sstream>
#include <iomanip>

App::App()
	:
	wnd(800, 600, "MeMori Corp.")
{}

int App::Go()
{
	while (true)
	{
		if (const auto ecode = Window::ProcessMessages())
		{
			return *ecode;
		}
		DoFrame();
	}
}

//void App::DoFrame()
//{
//	const float t = timer.Peek();
//	std::ostringstream oss;
//	oss << "Time elapsed : " << std::setprecision(1) << std::fixed << t << "s";
//	wnd.SetTitle(oss.str());
//}

void App::DoFrame()
{
	/*--------------Start Blue Fun Test--------------*/
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c, c, 1.0f);
	/*--------------End Blue Fun Test--------------*/

	/*--------------Godlike Triangles!!!--------------*/
	//wnd.Gfx().DrawTestTriangle(0.0f); // Static triangles
	wnd.Gfx().DrawTestTriangle(
		timer.Peek(),
		wnd.mouse.GetPosX() / 400.0f - 1.0f,
		-wnd.mouse.GetPosY() / 300.0f + 1.0f
	); //Rotating Triangles
		
	wnd.Gfx().EndFrame();
}