#include "BlinkEngine.h"

class ExampleLayer : public Blink::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{
	}

	void OnUpdate()
	{
		BLINK_CLIENT_TRACE("ExampleLayer::Update");
	}

	void OnEvent(Blink::Event& event) override
	{
		BLINK_CLIENT_TRACE("{0}", event);
	}
};

class Sandbox : public Blink::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{

	}
};

Blink::Application* Blink::CreateApplication()
{
	return new Sandbox();
}