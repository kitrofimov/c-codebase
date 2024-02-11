set(TESTS
    DynamicArrayTest
    VectorsTest
    MatrixTest
    fileUtilsTest
    stringUtilsTest
    BitArrayTest
)

foreach(TEST_NAME ${TESTS})
    add_executable(${TEST_NAME} ${TEST_NAME}.c)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()

target_link_libraries(DynamicArrayTest DynamicArray)
target_link_libraries(VectorsTest Vector)
target_link_libraries(MatrixTest Matrix Vector)
target_link_libraries(fileUtilsTest fileUtils)
target_link_libraries(stringUtilsTest stringUtils)
target_link_libraries(BitArrayTest BitArray)

file(COPY res/ DESTINATION ${CMAKE_BINARY_DIR}/tests/res)

