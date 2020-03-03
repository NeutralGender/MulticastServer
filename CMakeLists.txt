cmake_minimum_required(VERSION 3.0)

project(Client)
#set (CMAKE_CXX_FLAGS "-lpqxx -lpq")

include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/Include")
include_directories(/root/Downloads/hiredis-0.14.0/)
include_directories(/usr/include/boost/)

link_directories(/root/Downloads/hiredis-0.14.0/)
link_directories(/usr/include/boost/)

#add_definitions(${CMAKE_CXX_FLAGS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lhiredis")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lboost_system")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lboost_serialization")


file(
        GLOB 
            CPP_MAIN "${PROJECT_SOURCE_DIR}/main.cpp"
            CPP_SRC "${PROJECT_SOURCE_DIR}/Src/*.cpp"
    )


add_executable( Client ${CPP_MAIN} ${CPP_SRC} )