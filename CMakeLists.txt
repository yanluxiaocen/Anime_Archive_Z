cmake_minimum_required(VERSION 3.20)
project(Anime_Archive_Z LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Anime_Archive_Z
    src/main.cpp
    src/Anime.cpp
    src/AnimeStore.cpp
    src/UI.cpp
)

target_include_directories(Anime_Archive_Z PRIVATE include)

# MSVC 对无 BOM 源码默认按系统编码(GBK)读，中文会乱；统一按 UTF-8 读
if(MSVC)
    target_compile_options(Anime_Archive_Z PRIVATE /utf-8)
endif()