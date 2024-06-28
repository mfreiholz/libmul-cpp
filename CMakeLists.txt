cmake_minimum_required(VERSION 3.22)
project(libmul)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# library
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

set(
	HppFiles

	"libmul/Parsing/LineParsing.hpp"
	
	"libmul/System/Process.hpp"

	"libmul/Unit/Angle.hpp"
	"libmul/Unit/AngleUnit.hpp"
	"libmul/Unit/Distance.hpp"
	"libmul/Unit/DistanceUnit.hpp"
	"libmul/Unit/Unit.hpp"
	"libmul/Unit/Velocity.hpp"

	"libmul/BufferedLineReader.hpp"
	"libmul/Defines.hpp"
	"libmul/Version.hpp"
)

target_sources(${PROJECT_NAME} INTERFACE ${HppFiles})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "Source" FILES ${HppFiles})

# unit tests
if(TRUE)

	file(GLOB_RECURSE TestSources libmul/*.test.cpp)
	foreach(SourceFilePath ${TestSources})
		get_filename_component(BaseName ${SourceFilePath} NAME_WE)
		add_executable(Test${BaseName} ${SourceFilePath})
		target_link_libraries(Test${BaseName} PUBLIC ${PROJECT_NAME})
	endforeach()

endif()