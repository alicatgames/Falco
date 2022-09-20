#pragma once
#ifdef FLC_PLATFORM_WINDOWS

extern Falco::Application* Falco::CreateApplication();


int main(int argc, char** argv) {

	auto app = Falco::CreateApplication();
	app->Run();
	delete app;
}

#endif
