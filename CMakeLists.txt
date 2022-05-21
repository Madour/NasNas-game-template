# Modar Nasser - 9/10/2020

# This CMakeLists.txt will automatically generate build
# solution for a game using NasNas framework.


###### User Configuration #####################################################
# Project Name, which is also the output binary file name
set(PROJECT_NAME "NasNas_Game_Template")
###############################################################################


cmake_minimum_required(VERSION 3.10)
project(${PROJECT_NAME})


###### Load NasNas  ###########################################################
# Comment if you want to use an existing SFML installation
set(NASNAS_BUILD_SFML TRUE CACHE BOOL "Download and build SFML as a subproject" FORCE)

# Uncomment if you want to use the static libraries of an exising SFML installation
# set(SFML_STATIC_LIBRARIES TRUE)

add_subdirectory(NasNas)

if(MSVC AND NASNAS_BUILD_SFML)
    add_compile_options(
            $<$<CONFIG:>:/MT>
            $<$<CONFIG:Debug>:/MTd>
            $<$<CONFIG:Release>:/MT>
            $<$<CONFIG:MinSizeRel>:/MT>
            $<$<CONFIG:RelWithDebInfo>:/MT>
    )
endif()
###############################################################################


###### Find Game source files #################################################
file(GLOB_RECURSE Game_Src src/*.cpp src/*.hpp)
file(GLOB_RECURSE Game_Inc include/*.hpp)
###############################################################################


###### Create the executable target and link it ################################
add_executable(${PROJECT_NAME} ${Game_Src} ${Game_Inc})
target_include_directories(${PROJECT_NAME} PRIVATE src include)
target_link_libraries(${PROJECT_NAME} NasNas::All)

set_target_properties(
        ${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        DEBUG_POSTFIX -d
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}
        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}
)
###############################################################################
