cmake_minimum_required(VERSION 3.12)


message(STATUS "Generating bitdance")


function(build_executable BUILDED_NAME BUILDED_SOURCE)
    message(STATUS "Building ${BUILDED_NAME}")

    add_executable(
        ${BUILDED_NAME}
        ${BUILDED_SOURCE}
        ColorSpace/ColorSpace.cpp
        ColorSpace/Comparison.cpp
        ColorSpace/Conversion.cpp
    )

    target_link_libraries(${BUILDED_NAME} PUBLIC ${OPEN3D_LIB})
endfunction()


#### main metric binary rules####
build_executable(bitdance_pcqa bitdance_pcqa.cpp)

build_executable(create_normals create_normals.cpp)

build_executable(optimize_voxel_size optimize_voxel_size.cpp)

