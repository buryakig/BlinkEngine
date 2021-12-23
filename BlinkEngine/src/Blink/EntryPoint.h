#pragma once
#ifdef BLINK_PLATFORM_WINDOWS

extern Blink::Application* Blink::CreateApplication();

void main(int argc, char** argv)
{
	std::cout << "Welcome to BlinkEngine!" << std::endl;
	auto app = Blink::CreateApplication();
	app->Run();

	delete app;
}

#endif // BLINK_PLATFORM_WINDOWS
