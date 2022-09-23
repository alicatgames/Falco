#include "flcpch.h"
#include "Application.h"
#include "Falco/Events/ApplicationEvent.h"
#include "Falco/Log.h"

namespace Falco {

	Application::Application() 
	{

	}

	Application::~Application() 
	{

	}

	void Application::Run() 
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			FLC_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			FLC_TRACE(e);
		}
		while (true);
	}

}
