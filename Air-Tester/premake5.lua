project "Air-Tester"
	kind "StaticLib"
	staticruntime "On"

	files {
		"src/**.hpp",
		"src/**.cpp",
		"src/**.c",
		"src/**.h",
		"include/**.hpp",
        "include/**.h"
	}

	flags {
		"FatalCompileWarnings"
	}

	includedirs {
		"include"
	}

	warnings "Extra"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "%{prj.name}")
	objdir ("%{wks.location}/bin/" .. outputdir .. "%{prj.name}/int")

	defines {
		"AIR_TRACK_MEMORY"
	}

	filter "files:**.c"
		language "C"
		cdialect "gnu17"

	filter "files:**.h"
    		language "C"
    		cdialect "gnu17"

	filter "files:**.cpp"
		language "C++"
		cppdialect "C++11"

	filter "files:**.hpp"
    		language "C++"
    		cppdialect "C++11"

	filter "configurations:Debug"
		defines {"DEBUG"}
		optimize "Debug"
		symbols "On"

	filter "configurations:Release"
		defines {"RELEASE"}
		optimize "On"
		symbols "On"

	filter "configurations:Distribution"
		defines {"DISTRIBUTION"}
		symbols "Off"
		optimize "Full"