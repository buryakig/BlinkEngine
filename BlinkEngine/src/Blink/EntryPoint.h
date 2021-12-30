#pragma once
#ifdef BLINK_PLATFORM_WINDOWS

extern Blink::Application* Blink::CreateApplication();

void main(int argc, char** argv)
{
	Blink::Log::Init();
	BLINK_CORE_WARN("Hello Core Logger Warning");
	int a = 5;
	BLINK_CLIENT_INFO("Hello Client Logger Warning V = {0}", a);

	std::cout << "Welcome to BlinkEngine!" << std::endl;
	auto app = Blink::CreateApplication();
	app->Run();

	delete app;
}

#endif // BLINK_PLATFORM_WINDOWS
