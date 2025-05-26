cmake_minimum_required(VERSION 4.0.0)

project(calc-cli VERSION 1.0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 17)

set(SOURCES
    "src/main.c"
    "src/tokenize.c"
    "src/tokenMat.c"
    "src/postfix.c"
    "src/evaluate.c"
    "src/utils/stack.c"
    "src/utils/queue.c"
    "src/utils/calcTypes.c"
)

add_executable(calc-cli ${SOURCES})
target_include_directories(calc-cli 
    PRIVATE 
        include 
        include/utils
)
if(UNIX) # including the math library for linux
    target_link_libraries(calc-cli m)
endif()