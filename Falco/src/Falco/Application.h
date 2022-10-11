#pragma once

#include "Core.h"
#include "Window.h"

#include "Falco/LayerStack.h"
#include "Falco/Events/Event.h"
#include "Falco/Events/ApplicationEvent.h"
#include "Falco/ImGui/ImGuiLayer.h"

namespace Falco {

	class FALCO_API Application
	{

	public:
		Application();
		virtual ~Application();

	void Run();

	void OnEvent(Event& e);

	void PushLayer(Layer* layer);

	void PushOverlay(Layer* overlay);

	inline Window& GetWindow() { return *m_Window; }

	inline static Application& Get() { return* s_Instance; }


	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		
		bool m_Running = true;
		
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};



	// To be defined in the client
	Application* CreateApplication();

}
