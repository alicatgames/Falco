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

project "Falco"
	location "Falco"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "flcpch.h"
	pchsource "Falco/src/flcpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FLC_PLATFORM_WINDOWS",
			"FLC_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "system:macosx"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FLC_PLATFORM_MACOSX",
			"FLC_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "FLC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FLC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FLC_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
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
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FLC_PLATFORM_WINDOWS",
		}

	filter "system:macosx"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FLC_PLATFORM_MACOS"
		}

	filter "configurations:Debug"
		defines "FLC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FLC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FLC_DIST"
		optimize "On"
