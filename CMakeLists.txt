cmake_minimum_required(VERSION 3.1)

project(infrastructure)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(3rdparty)

include_directories(include)

set(LINTING_APP ${CMAKE_SOURCE_DIR}/3rdparty/utils/cpplint.py)
set(LINTING_COMMAND python ${LINTING_APP} --extensions=cpp,hpp,h,cc,c)

add_subdirectory(test)

if (CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-Wall -Wpedantic -Wextra -Werror)
endif()

add_subdirectory(src)
add_subdirectory(app)
