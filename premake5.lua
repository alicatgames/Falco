workspace "Falco"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Struct/table of include directories relative to root
IncludeDir = {}
IncludeDir["GLFW"] = "Falco/vendor/GLFW/include"
IncludeDir["glad"] = "Falco/vendor/glad/include"
IncludeDir["ImGui"] = "Falco/vendor/imgui"

group "Dependencies"
	include "Falco/vendor/GLFW"
	include "Falco/vendor/glad"
	include "Falco/vendor/imgui"

group ""

project "Falco"
	location "Falco"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "flcpch.h"
	pchsource "Falco/src/flcpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"FLC_PLATFORM_WINDOWS",
			"FLC_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}


	filter "configurations:Debug"
		defines "FLC_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "FLC_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "FLC_DIST"
		runtime "Release"
		optimize "on"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Falco/vendor/spdlog/include",
		"Falco/src"
	}

	links
	{
		"Falco"
	}

	filter "system:windows"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"FLC_PLATFORM_WINDOWS",
		}


	filter "configurations:Debug"
		defines "FLC_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "FLC_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "FLC_DIST"
		runtime "Release"
		optimize "on"
