#pragma once

// Macro, that depends on wheather we build our blink dll or not
#ifdef BLINK_PLATFORM_WINDOWS
	#ifdef BLINK_BUILD_DLL
		#define BLINK_API __declspec(dllexport)
	#else
		#define BLINK_API __declspec(dllimport)
	#endif
#else
	#error Blink Engine is currently only supports Windows
#endif

#ifdef BLINK_ENABLE_ASSERTS
	#define  BLINK_ASSERT(x, ...) {if!(x){ BLINK_ERROR("Assertion Failed {0}", __VA_ARGS__); __debugbreak();}}
	#define  BLINK_CORE_ASSERT(x, ...) {if!(x){ BLINK_CORE_ERROR("Assertion Failed {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define  BLINK_ASSERT(x, ...)
	#define  BLINK_CORE_ASSERT(x, ...)
#endif

// Bit shift macro
#define BIT(x) (1 << x)

#define BLINK_BIND_EVENT_FUNCTION(fn)	std::bind(&fn, this, std::placeholders::_1)