cmake_minimum_required(VERSION 3.17)
project(algorithm C)

set(CMAKE_C_STANDARD 11)

add_executable(algorithm main.c)

# 遍历项目根目录下所有的 .cpp 文件
file(GLOB_RECURSE files *.c)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable(${exe} ${file})
    message(\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()