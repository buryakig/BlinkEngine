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