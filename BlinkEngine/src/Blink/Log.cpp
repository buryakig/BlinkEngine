#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Blink
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClentLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("BLINK");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClentLogger = spdlog::stdout_color_mt("APP");
		s_CoreLogger->set_level(spdlog::level::trace);
	}

}