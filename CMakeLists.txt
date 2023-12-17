add_library(Color STATIC Color/Color.c)
add_library(Vector STATIC Vector/Vector2.c Vector/Vector3.c Vector/Vector4.c)
add_library(Matrix STATIC Matrix/Matrix.c)
add_library(DynamicArray STATIC DynamicArray/DynamicArray.c)
add_library(fileUtils STATIC fileUtils/fileUtils.c)
add_library(memoryUtils STATIC memoryUtils/memoryUtils.c)
add_library(stringUtils STATIC stringUtils/stringUtils.c)

target_link_libraries(Matrix Vector)

target_include_directories(Color PUBLIC .)
target_include_directories(Vector PUBLIC .)
target_include_directories(Matrix PUBLIC .)
target_include_directories(DynamicArray PUBLIC .)
target_include_directories(fileUtils PUBLIC .)
target_include_directories(memoryUtils PUBLIC .)
target_include_directories(stringUtils PUBLIC .)

