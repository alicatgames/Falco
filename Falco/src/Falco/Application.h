#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Falco {

	class Application
	{

	public:
		Application();
		virtual ~Application();

	void Run();
	};

	// To be defined in the client
	Application* CreateApplication();

}
