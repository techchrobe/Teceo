#pragma once

#include <memory>

#include "Core.h"
#include "spdlog//spdlog.h"

namespace Teceo {
	class TECEO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
}

// Core log macros
#define TC_CORE_ERROR(...) ::Teceo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TC_CORE_WARN(...) ::Teceo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TC_CORE_INFO(...) ::Teceo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TC_CORE_TRACE(...) ::Teceo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TC_CORE_FATAL(...) ::Teceo::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define TC_ERROR(...) ::Teceo::Log::GetClientLogger()->error(__VA_ARGS__)
#define TC_WARN(...) ::Teceo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TC_INFO(...) ::Teceo::Log::GetClientLogger()->info(__VA_ARGS__)
#define TC_TRACE(...) ::Teceo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TC_FATAL(...) ::Teceo::Log::GetClientLogger()->fatal(__VA_ARGS__)