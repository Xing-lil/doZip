# 声明要求的 cmake 最低版本
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(doZip VERSION 1.0)

# 设置编译模式
set(CMAKE_BUILD_TYPE "Debug")

# 设置生成的可执行文件存放目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# 设置头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)

# 在目录中查找所有源文件
aux_source_directory(src DIR_SRCS)

# 将指定的源文件生成链接文件
add_library(doZip ${DIR_SRCS})
target_link_libraries(doZip pthread)

add_executable(test "${PROJECT_SOURCE_DIR}/test/test.c")
target_link_libraries(test doZip)


