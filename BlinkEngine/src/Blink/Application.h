#pragma once
#include "blinkpch.h"
#include "Core.h"
#include "Window.h"

namespace Blink
{
	class BLINK_API Application
	{
	public: 
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;

		bool m_Running = true;
	};

	// To be defined in client
	Application* CreateApplication();
}
