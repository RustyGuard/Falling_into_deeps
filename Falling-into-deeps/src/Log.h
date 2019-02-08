#pragma once

#include "gearpch.h"

#include "spdlog/spdlog.h"

namespace Gear {

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define GEAR_CORE_TRACE(...)    ::Gear::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GEAR_CORE_INFO(...)     ::Gear::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GEAR_CORE_WARN(...)     ::Gear::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GEAR_CORE_ERROR(...)    ::Gear::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GEAR_CORE_FATAL(...)    ::Gear::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define GEAR_TRACE(...)	      ::Gear::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GEAR_INFO(...)	      ::Gear::Log::GetClientLogger()->info(__VA_ARGS__)
#define GEAR_WARN(...)	      ::Gear::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GEAR_ERROR(...)	      ::Gear::Log::GetClientLogger()->error(__VA_ARGS__)
#define GEAR_FATAL(...)	      ::Gear::Log::GetClientLogger()->fatal(__VA_ARGS__)

#ifdef GEAR_ENABLE_ASSERTS
	#define GEAR_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define GEAR_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define GEAR_ASSERT(x, ...)
	#define GEAR_CORE_ASSERT(x, ...)
#endif