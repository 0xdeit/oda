cmake_minimum_required(VERSION 3.1)
project(oda)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(include/libphys)
include_directories(include/libphys/body)
include_directories(include/libphys/collision)
include_directories(include/libphys/math)
include_directories(include/utils)

add_executable(oda
        src/main.cpp include/libphys/math/Vector2.cpp include/libphys/math/Vector2.h include/libphys/math/Vector3.cpp include/libphys/math/Vector3.h include/libphys/math/Scalar2.h include/libphys/math/Scalar3.h include/libphys/math/math_helper.h include/libphys/test/Vector2_test.cpp include/libphys/test/Vector2_test.h include/utils/print_utils.h)
