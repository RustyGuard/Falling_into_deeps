workspace "Falling-into-deeps"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Falling-into-deeps"
	location "Falling-into-deeps"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/lib/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SGT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SGT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SGT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SGT_DIST"
		optimize "On"