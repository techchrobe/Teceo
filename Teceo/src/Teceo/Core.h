#pragma once

#ifdef TC_PLATFORM_WINDOWS
	#ifdef TC_BUILD_DLL
		#define TECEO_API __declspec(dllexport)
	#else
		#define TECEO_API __declspec(dllimport)
	#endif
#else
	#error Teceo only supports Windows!
#endif

#define BIT(x) (1 << x)