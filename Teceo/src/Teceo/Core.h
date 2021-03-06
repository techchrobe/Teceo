#pragma once

#ifdef TC_PLATFORM_WINDOWS
	#ifdef TC_BUILD_DLL
		#define TECEO_API __declspec(dllexport)
	#else
		#define TECEO_API __declspec(dllimport)
	#endif // TC_BUILD_DLL
#else
	#error Teceo only supports Windows!
#endif // TC_PLATFORM_WINDOWS

#ifdef TC_ENABLE_ASSERTS
	#define TC_ASSERT(x, ...) { if(!x)) {TC_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define TC_CORE_ASSERT(x, ...) { if(!x)) {TC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define TC_ASSERT(x, ...)
	#define TC_CORE_ASSERT(x, ...)
#endif // TC_ENABLE_ASSERTS


#define BIT(x) (1 << x)