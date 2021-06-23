#include "Window.h"
#include <sstream>

int CALLBACK WinMain
(
	HINSTANCE	hInstance,
	HINSTANCE	hPrevInstance,
	LPSTR		lpCmdLine,
	int			nCmdShow
)
{
	try
	{
		Window wnd(800, 300, "MeM0ri Corp.");
		MSG msg;
		BOOL gResult;
		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			/*--------------Start Tests Part--------------*/
			while (!wnd.mouse.IsEmpty())
			{
				const auto e = wnd.mouse.Read();
				switch (e.GetType())
				{
				case Mouse::Event::Type::Leave:
					wnd.SetTitle("She's Gone! She's Go-o-one!");
					break;
				case Mouse::Event::Type::Move:
					{
						std::ostringstream oss;
						oss << "Mouse Position: (" << e.GetPosX() << "," << e.GetPosY() << ")";
						wnd.SetTitle(oss.str());
					}
				}
			}
			if (wnd.kbrd.KeyIsPressed(VK_MENU))
			{
				MessageBox(nullptr, "What tha...", "It's alt invaders!", MB_OK | MB_ICONEXCLAMATION);
			}
			/*--------------End Tests Part--------------*/
		}

		if (gResult == -1)
		{
			return -1;
		}

		return msg.wParam;
	}
	catch (const MeMoriException& e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, "No details avaliable", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}