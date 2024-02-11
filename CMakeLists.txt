cmake_minimum_required(VERSION 3.25.1)
project(c-codebase)

enable_testing()

add_library(Vector STATIC Vector/Vector2.c Vector/Vector3.c Vector/Vector4.c)
add_library(Matrix STATIC Matrix/Matrix.c)
add_library(DynamicArray STATIC DynamicArray/DynamicArray.c)
add_library(fileUtils STATIC fileUtils/fileUtils.c)
add_library(memoryUtils STATIC memoryUtils/memoryUtils.c)
add_library(stringUtils STATIC stringUtils/stringUtils.c)
add_library(BitArray STATIC BitArray/BitArray.c)

target_link_libraries(Matrix Vector)
target_link_libraries(BitArray memoryUtils)
target_link_libraries(DynamicArray memoryUtils)
target_link_libraries(fileUtils memoryUtils)
target_link_libraries(stringUtils DynamicArray memoryUtils) 
if(UNIX)
    target_link_libraries(Vector m)
    target_link_libraries(Matrix m)
endif()

include_directories(.)

add_subdirectory(tests)

