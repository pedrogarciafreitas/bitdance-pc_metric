set(EXECUTABLE_TEST_PATH "${EXECUTABLE_TEST_PATH}/tests/")
function(add_library_test_open3d TEST_NAME TEST_BIN_NAME TEST_SOURCE)
        add_executable(${TEST_BIN_NAME} ${TEST_SOURCE})
        target_include_directories(${TEST_BIN_NAME} PRIVATE 
            "${INCLUDE_DIRECTORIES};${open3d_INCLUDE};${OPENCV_INCLUDE_DIR};${EIGEN3_INCLUDE_DIRS}"
        )
        target_link_libraries(${TEST_BIN_NAME} PRIVATE gtest_main)
        target_link_libraries(${TEST_BIN_NAME} PUBLIC ${OPEN3D_LIB})

        set_target_properties( ${TEST_BIN_NAME}
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${EXECUTABLE_TEST_PATH}"
        )
    add_test(${TEST_NAME} ${EXECUTABLE_TEST_PATH}/${TEST_BIN_NAME} 
                 "${CMAKE_HOME_DIRECTORY}/resources")
endfunction()
