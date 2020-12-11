cmake_minimum_required(VERSION 3.17)
project(University C)

set(CMAKE_C_STANDARD 11)

file(GLOB APP_SOURCES RELATIVE ${PROJECT_SOURCE_DIR}
        pr1/*.c
        pr2/*.c
        pr3/*.c
        lab1/*.c
        final/*.c)
foreach (sourcefile ${APP_SOURCES})
    message(${sourcefile})
    string(REPLACE ".c" "" name ${sourcefile})
    string(REPLACE "/" "-" name ${name})
    add_executable(${name} ${sourcefile})
    target_include_directories(${name} PUBLIC ./)
endforeach (sourcefile ${APP_SOURCES})