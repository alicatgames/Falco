#pragma once


extern Falco::Application* Falco::CreateApplication();


int main(int argc, char** argv) 
{
	Falco::Log::Init();
	FLC_CORE_WARN("Initialized Log");
	int a = 5;
	FLC_INFO("Variable print test: Var={0}", a);

	auto app = Falco::CreateApplication();
	app->Run();
	delete app;
}

