
cmake_minimum_required (VERSION 3.10)


if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_STANDARD 20)
project (MyEngine LANGUAGES CXX C)

# 将源代码添加到此项目的可执行文件。


file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE headers CONFIGURE_DEPENDS include/*.h include/*.hpp)
add_executable(MyEngine ${sources} ${headers} "src/OBJ.cpp")
target_include_directories(MyEngine PUBLIC include)



add_subdirectory(glm)
target_link_libraries(MyEngine PUBLIC glm)
add_subdirectory(glfw)
target_link_libraries(MyEngine PUBLIC glfw)
add_subdirectory(glad)
target_link_libraries(MyEngine PUBLIC glad)
