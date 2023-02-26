cmake_minimum_required(VERSION 3.21.0)
project(Assignment1 CXX)

add_subdirectory(matplotplusplus)
add_subdirectory(seqan3)

include_directories(
        ${PROJECT_SOURCE_DIR}/src
)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/src/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.hpp"
)

add_executable(as1 ${all_SRCS})
target_link_libraries(as1 PUBLIC matplot seqan3::seqan3)
