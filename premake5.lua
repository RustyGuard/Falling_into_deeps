workspace "Falling-into-deeps"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Falling-into-deeps/lib/GLFW"
include "Falling-into-deeps/lib/Glad"
include "Falling-into-deeps/lib/Lua"

project "Falling-into-deeps"
	location "Falling-into-deeps"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "sgtpch.h"
	pchsource "Falling-into-deeps/src/sgtpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/lib/spdlog/include",
		"%{prj.name}/lib/GLFW/include",
		"%{prj.name}/lib/Glad/include",
		"%{prj.name}/lib/nlohman/include",
		"%{prj.name}/lib/graphics",
		"%{prj.name}/lib/Lua/src",
		"%{prj.name}/lib/luabridge/Source"
	}
	links 
	{ 
		"GLFW",
		"Glad",
		"opengl32.lib",
		"Lua"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SGT_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "SGT_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "SGT_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "SGT_DIST"
		buildoptions "/MD"
		optimize "On"