project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"

	files {"**.hpp", "**.cpp"}

	targetdir ("${wks.location}" .. outputdir .. "%{prj.name}")
	objdir ("${wks.location}" .. outputdir .. "%{prj.name}/int")

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