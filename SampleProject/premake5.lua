project "SampleProject"
	kind "ConsoleApp"
	language "C++"
    cppdialect "C++20"
	cdialect "C17"
	systemversion "latest"
	staticruntime "on"

	targetdir(ProjectBinDirectory)
	objdir(ProjectBinObjDirectory)

	flags {
		"MultiProcessorCompile",
	}

	includedirs {
		"Source",
		ProjectDirectories.VDGL .. "/Source"
	}

	files {
		"**.h",
		"**.cpp",
	}

	dependson {
		"VDGL"
	}

	links {
		"VDGL",
		"opengl32.lib"
	}

	filter "Debug"
        runtime "Debug"
		symbols "on"

	filter "Release"
        runtime "Release"
		optimize "speed"
		symbols "off"