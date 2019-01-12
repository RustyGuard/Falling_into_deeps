#pragma once

#include "sgtpch.h"

#include "spdlog/spdlog.h"

namespace sgt {

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
#define SGT_CORE_TRACE(...)    ::sgt::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SGT_CORE_INFO(...)     ::sgt::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SGT_CORE_WARN(...)     ::sgt::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SGT_CORE_ERROR(...)    ::sgt::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SGT_CORE_FATAL(...)    ::sgt::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define SGT_TRACE(...)	      ::sgt::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SGT_INFO(...)	      ::sgt::Log::GetClientLogger()->info(__VA_ARGS__)
#define SGT_WARN(...)	      ::sgt::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SGT_ERROR(...)	      ::sgt::Log::GetClientLogger()->error(__VA_ARGS__)
#define SGT_FATAL(...)	      ::sgt::Log::GetClientLogger()->fatal(__VA_ARGS__)

#ifdef SGT_ENABLE_ASSERTS
	#define SGT_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SGT_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SGT_ASSERT(x, ...)
	#define SGT_CORE_ASSERT(x, ...)
#endif