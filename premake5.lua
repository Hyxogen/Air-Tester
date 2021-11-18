workspace "Air-Tester"
	architecture "x86_64"

	configurations {"Debug", "Release", "Distribution"}
	platforms {"osx", "Win64"}

outputdir = "%{cfg.buildcfg}/%{cfg.system}/%{cfg.architecture}/"

include "Air-Tester"
include "Sandbox"