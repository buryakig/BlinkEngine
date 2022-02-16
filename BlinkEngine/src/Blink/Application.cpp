#include "blinkpch.h"
#include "Application.h"
#include "Blink/Event/Event.h"
#include "Blink/Event/ApplicationEvent.h"
#include "Blink/Log.h"

namespace Blink
{
	Blink::Application::Application()
	{
	}

	Blink::Application::~Application()
	{
	}
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		BLINK_CORE_TRACE(e);
		std::cout << ">>> Application::Run() is called" << std::endl;
		while (true);
	}
}