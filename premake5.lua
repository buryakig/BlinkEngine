workspace "BlinkEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "BlinkEngine/submodules/GLFW/include"
IncludeDir["Glad"] = "BlinkEngine/submodules/Glad/include"
IncludeDir["ImGui"] = "BlinkEngine/submodules/imgui"

include "BlinkEngine/submodules/GLFW"
include "BlinkEngine/submodules/Glad"
include "BlinkEngine/submodules/imgui"

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
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"BLINK_PLATFORM_WINDOWS",
			"BLINK_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/build/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "BLINK_DEBUG"
		buildoptions "/MDp"
		symbols "On"

	filter "configurations:Release"
		defines "BLINK_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "BLINK_DIST"
		buildoptions "/MD"
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
		buildoptions "/MDp"
		symbols "On"

	filter "configurations:Release"
		defines "BLINK_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "BLINK_DIST"
		buildoptions "/MD"
		optimize "On"
