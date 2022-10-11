#include <Falco.h>
#include "imgui/imgui.h"


class ExampleLayer : public Falco::Layer
{
public:
	ExampleLayer()
		: Layer("ExampleLayer")
	{
	}

	void OnUpdate() override
	{
		if (Falco::Input::IsKeyPressed(FLC_KEY_TAB))
			FLC_TRACE("Tab key is down mofo!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Rock Me Amadeus!");
		ImGui::End();
	}

	void OnEvent(Falco::Event& event) override
	{
		if (event.GetEventType() == Falco::EventType::KeyPressed)
		{
			Falco::KeyPressedEvent& e = static_cast<Falco::KeyPressedEvent&>(event);
			if (e.GetKeyCode() == FLC_KEY_TAB)
				FLC_TRACE("Tab key is pressed (event)!");
			FLC_TRACE("{0}", (char)e.GetKeyCode());
		}
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