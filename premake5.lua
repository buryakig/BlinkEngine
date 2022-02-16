workspace "BlinkEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "BlinkEngine"
	location"BlinkEngine"
	kind "SharedLib"
	language "C++"

	targetdir("bin/build/" .. outputdir .. "/%{prj.name}")
	objdir("bin/int/" .. outputdir .. "/%{prj.name}")

	pchheader "blinkpch.h"
	pchsource "BlinkEngine/src/blinkpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/submodules/spdlog/include",
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"BLINK_PLATFORM_WINDOWS",
			"BLINK_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/build/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "BLINK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BLINK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BLINK_DIST"
		optimize "On"

project "Sandbox"
	location"Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/build/" .. outputdir .. "/%{prj.name}")
	objdir("bin/int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"BlinkEngine/submodules/spdlog/include",
		"BlinkEngine/src"
	}

	links
	{
		"BlinkEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"BLINK_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BLINK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BLINK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BLINK_DIST"
		optimize "On"
