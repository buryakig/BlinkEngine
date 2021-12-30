#include "Application.h"
#include <iostream>

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
		std::cout << ">>> Application::Run() is called" << std::endl;
		while (true);
	}
}