cmake_minimum_required(VERSION 3.20)
project(Anime_Archive_Z LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============ 主程序 ============
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

# ============ 单元测试 ============
# 第 1 行：告诉 CMake"这个工程有测试"，启用 ctest 支持
enable_testing()

# 第 2 块：unit_tests 是【另一个独立可执行文件】，和主程序平级：
#   test_main.cpp    → 提供 main（doctest 自动生成的测试入口）
#   test_anime.cpp   → 测试用例本体
#   Anime.cpp / AnimeStore.cpp → 被测的真实代码（重新编译一份给测试用）
# 注意：没有 src/main.cpp！它俩抢 main 会链接冲突
add_executable(unit_tests
    tests/test_main.cpp
    tests/test_anime.cpp
    src/Anime.cpp
    src/AnimeStore.cpp
)

# 第 3 行：测试程序要找两处头文件：
#   include/ → Anime.h、AnimeStore.h
#   tests/   → doctest.h
target_include_directories(unit_tests PRIVATE include tests)

# 第 4 行：和主程序一样，中文源码按 UTF-8 读
if(MSVC)
    target_compile_options(unit_tests PRIVATE /utf-8)
endif()

# 第 5 行：注册给 ctest —— 之后敲 ctest 就能批量跑测试
add_test(NAME unit_tests COMMAND unit_tests)