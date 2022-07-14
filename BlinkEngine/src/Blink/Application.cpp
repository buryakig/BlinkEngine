#include "blinkpch.h"
#include "Application.h"
#include "Blink/Log.h"

#include "Blink/Event/Event.h"
#include "glad/glad.h"

namespace Blink
{

	Application* Application::s_Instance = nullptr;

	Blink::Application::Application()
	{
		BLINK_ASSERT(!s_Instance, "Application already exists!")
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BLINK_BIND_EVENT_FUNCTION(Application::OnEvent));
	}

	Blink::Application::~Application()
	{
	}


	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BLINK_BIND_EVENT_FUNCTION(Application::OnWindowClose));

		BLINK_CORE_TRACE("{0}", e);
		
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.m_Handled)
				break;
		}

	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::Run()	
	{
		while (m_Running)
		{
			glClearColor(0.5, 0.0, 0.0, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}