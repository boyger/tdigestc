# 设置 C 标准为 C99
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_compile_options(-std=gnu99)

cmake_minimum_required(VERSION 3.0)
project(MyProject C)

# 包含头文件目录
include_directories(include)

# 添加库目标
add_library(tdigest_static STATIC src/tdigest.c)
add_library(tdigest SHARED src/tdigest.c)
target_link_libraries(tdigest m)

# 添加测试可执行文件
add_executable(tdigest_test test/tdigest_test.c)
add_executable(tdigest_test_serialize test/tdigest_test_serialize.c)

# 链接库到测试可执行文件
target_link_libraries(tdigest_test tdigest)
target_link_libraries(tdigest_test_serialize tdigest)