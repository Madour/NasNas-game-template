# Modar Nasser - 9/10/2020

# This CMakeLists.txt will automatically generate build
# solution for a NasNas game. 

# Note: Everytime you add a new file to the project or 
#       update an asset, be sure to rerun `cmake ..`
#       to update the cache.



###### User Configuration #####################################################
# Project Name, which is also the ouput binary file name
set(PROJECT_NAME "NasNas_Game_Template")
# Assets directory path, will be copied in bin when cmake is called
set(ASSETS_DIR_NAME "")

# Select the modules you want to build
# The following variables can be set to FALSE to exclude the associated module
set(NASNAS_BUILD_RESLIB         TRUE)
set(NASNAS_BUILD_ECS            TRUE)
set(NASNAS_BUILD_TILEMAPPING    TRUE)
set(NASNAS_BUILD_UI             TRUE)
###############################################################################


cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

project(${PROJECT_NAME})


###### Find SFML library ######################################################
if (WIN32)
    set(SFML_DIR C:/SFML)               # specify here the install location of SFML
    set(SFML_STATIC_LIBRARIES TRUE)     # set to false if you want to use DLLs
    find_package(SFML COMPONENTS graphics audio PATHS ${SFML_DIR}/lib/cmake/ )
else()
    find_package(SFML COMPONENTS graphics audio )
endif()
###############################################################################


###### Load NasNas cmake modules ##############################################
set(NASNAS_PATH "NasNas")
include(NasNas/cmake/NasNas.cmake)
###############################################################################


###### Find Game source files #################################################
file(GLOB_RECURSE Game_Src src/*.cpp src/*.hpp)
file(GLOB_RECURSE Game_Inc include/*.hpp)
# copy assets directory near binary output
if (ASSETS_DIR_NAME)
    file(COPY ${ASSETS_DIR_NAME} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endif()
###############################################################################


###### Create the executabe target and link it ################################
add_executable(${PROJECT_NAME}
    # framework source files here
    NasNas/include/NasNas.h ${NasNas_Src} ${NasNas_Inc}

    # user source files here
    ${Game_Src} ${Game_Inc}
    main.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE src include NasNas/include)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
###############################################################################
