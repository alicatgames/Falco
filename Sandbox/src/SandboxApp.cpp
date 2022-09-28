#include <Falco.h>

class Sandbox : public Falco::Application
{
public:
	Sandbox() 
	{

	}

	~Sandbox() 
	{

	}
};

Falco::Application* Falco::CreateApplication()
{
	return new Sandbox();
}