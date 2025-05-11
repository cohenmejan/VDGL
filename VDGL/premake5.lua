project "VDGL"
	kind "StaticLib"
	language "C++"
    cppdialect "C++20"
	cdialect "C17"
	systemversion "latest"
	staticruntime "on"

	targetdir "%{wks.location}/bin/%{cfg.buildcfg}"
	objdir "%{wks.location}/bin-obj/%{cfg.buildcfg}"

	flags {
		"MultiProcessorCompile",
	}

	includedirs {
		"Source"
	}

	files {
		"**.h",
		"**.cpp",
	}

	links {
		"opengl32.lib"
	}

	filter "Debug"
        runtime "Debug"
		symbols "on"

	filter "Release"
        runtime "Release"
		optimize "speed"
		symbols "off"