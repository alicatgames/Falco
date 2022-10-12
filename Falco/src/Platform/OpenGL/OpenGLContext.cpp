#include "flcpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <gl/GL.h>

namespace Falco {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle)
	{
		FLC_CORE_ASSERT(windowHandle, "!Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		FLC_CORE_ASSERT(status, "!Failed to initialise glad!");

		FLC_CORE_INFO("OpenGL Info:");
		FLC_CORE_INFO("Vendor: {0}", glGetString(GL_VENDOR));
		FLC_CORE_INFO("Renderer: {0}", glGetString(GL_RENDERER));
		FLC_CORE_INFO("Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}

