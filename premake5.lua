workspace "Air-Tester"
	architecture "x86_64"

	configurations {"Debug", "Release", "Distribution"}
	platforms {"Win64", "OSX"}

outputdir = "%{cfg.buildcfg}/%{cfg.system}/%{cfg.architecture}/"

include "Air-Tester"
include "Sandbox"