project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"

	files {"**.hpp", "**.cpp"}

	dependson {
		"Air-Tester"
	}

	links {
		"Air-Tester"
	}

	includedirs {
		"%{wks.location}/Air-Tester/include"
	}

	targetdir ("%{wks.location}/bin/" .. outputdir .. "%{prj.name}")
	objdir ("%{wks.location}/bin/" .. outputdir .. "%{prj.name}/int")

	filter "configurations:Debug"
		defines {"AIR_TESTER_DEBUG"}
		optimize "Debug"
		symbols "On"

	filter "configurations:Release"
		defines {"AIR_TESTER_RELEASE"}
		optimize "On"
		symbols "On"

	filter "configurations:Distribution"
		defines {"AIR_TESTER_DISTRIBUTION"}
		symbols "Off"
		optimize "Full"