#include "blinkpch.h"
#include "Application.h"
#include "Blink/Event/Event.h"
#include "Blink/Event/ApplicationEvent.h"
#include "Blink/Log.h"

namespace Blink
{
	Blink::Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Blink::Application::~Application()
	{
	}
	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}