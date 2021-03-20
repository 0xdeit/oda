cmake_minimum_required(VERSION 3.1)
project(oda)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(include/LibPhys)
include_directories(include/LibPhys/body)
include_directories(include/LibPhys/collision)
include_directories(include/LibPhys/Math)
include_directories(include/Misc)

add_executable(oda
        src/main.cpp include/LibPhys/Math/Vector2.cpp include/LibPhys/Math/Vector2.h include/LibPhys/Math/Vector3.cpp include/LibPhys/Math/Vector3.h include/LibPhys/Math/Conversions.h include/LibPhys/Test/Vector2_test.cpp include/LibPhys/Test/Vector2_test.h include/Misc/print_utils.h include/LibPhys/Math/GeometryTypes.h include/LibPhys/Math/Constants.h include/LibPhys/Math/Measurements.h)
