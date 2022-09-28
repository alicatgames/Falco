#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Falco {

	class FALCO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline  static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}
// Core log macros Strip out for distribution builds
#define FLC_CORE_TRACE(...) ::Falco::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FLC_CORE_INFO(...) ::Falco::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FLC_CORE_WARN(...) ::Falco::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FLC_CORE_ERROR(...) ::Falco::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FLC_CORE_FATAL(...) ::Falco::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros Strip out for distribution builds
#define FLC_TRACE(...) ::Falco::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FLC_INFO(...) ::Falco::Log::GetClientLogger()->info(__VA_ARGS__)
#define FLC_WARN(...) ::Falco::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FLC_ERROR(...) ::Falco::Log::GetClientLogger()->error(__VA_ARGS__)
#define FLC_FATAL(...) ::Falco::Log::GetClientLogger()->fatal(__VA_ARGS__)


