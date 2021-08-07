cmake_minimum_required(VERSION 3.18)
project(libmul)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# library
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE HppFiles ${PROJECT_NAME}/*.hpp)
foreach(HppFilePath ${HppFiles})
	target_sources(${PROJECT_NAME} INTERFACE ${HppFilePath})
endforeach()
#source_group(TREE ${PROJECT_SOURCE_DIR}/${PROJECT_NAME} PREFIX ${PROJECT_NAME}/Core FILES ${HppFiles})


# unit tests
file(GLOB_RECURSE TestSources libmul/*.test.cpp)
foreach(SourceFilePath ${TestSources})
	get_filename_component(BaseName ${SourceFilePath} NAME_WE)
	add_executable(Test${BaseName} ${SourceFilePath})
	target_link_libraries(Test${BaseName} PUBLIC ${PROJECT_NAME})
endforeach()