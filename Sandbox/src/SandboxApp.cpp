#include <Falco.h>


class ExampleLayer : public Falco::Layer
{
public:
	ExampleLayer()
		: Layer("ExampleLayer")
	{
	}

	void OnUpdate() override
	{
		FLC_INFO("ExampleLayer::Update");
	}

	void OnEvent(Falco::Event& event) override
	{
		FLC_TRACE("{0}", event);
	}
};

class Sandbox : public Falco::Application
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

Falco::Application* Falco::CreateApplication()
{
	return new Sandbox();
}