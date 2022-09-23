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

#define BIT(x) (1 << x)


