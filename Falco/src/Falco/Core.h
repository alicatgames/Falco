#pragma once

#ifdef FLC_PLATFORM_WINDOWS
	#ifdef FLC_BUILD_DLL
		#define FALCO_API __declspec(dllexport)
	#else
		#define FALCO_API __declspec(dllimport)
	#endif
#else
	#error Falco only supports windows!
#endif

#ifdef FLC_ENABLE_ASSERTS
	#define FLC_ASSERT(x, ...) { if(!(x)) { FLC_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define FLC_CORE_ASSERT(x, ...) { if(!(x)) { FLC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define FLC_ASSERT(x, ...) 
	#define FLC_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)


