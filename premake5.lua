workspace "VDGL"
	architecture "x64"
	startproject "VDGL"

	configurations {
		"Debug",
		"Release"
	}

RootDirectory = "%{wks.location}"
BinDirectory = RootDirectory .. "/bin/%{cfg.buildcfg}"
BinObjDirectory = RootDirectory .. "/bin-obj/%{cfg.buildcfg}"
ProjectName = "%{prj.name}"
ProjectBinDirectory = BinDirectory .. "/" .. ProjectName
ProjectBinObjDirectory = BinObjDirectory .. "/" .. ProjectName

ProjectDirectories = {}
ProjectDirectories["VDGL"] = RootDirectory .. "/VDGL"

include "VDGL"
include "SampleProject"