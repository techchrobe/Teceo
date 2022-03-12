workspace "Teceo"
	architecture "x64"
	
	configurations {
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
project "Teceo"
	location "Teceo"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		
		defines {
			"TC_PLATFORM_WINDOWS",
			"TC_BUILD_DLL",
			"_WINDLL"
		}
		
		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/GameOver")
		}
		
	filter "configurations:Debug"
		defines "TC_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "TC_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "TC_DIST"
		optimize "On"

project "GameOver"
	location "GameOver"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs {
		"Teceo/vendor/spdlog/include",
		"Teceo/src"
	}
	
	links {
		"Teceo"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		
		defines {
			"TC_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "TC_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "TC_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "TC_DIST"
		optimize "On"