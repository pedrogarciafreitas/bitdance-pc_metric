cmake_minimum_required(VERSION 3.12)

include(ExternalProject)

set(LIBOPEN3D_INSTALL ${CMAKE_CURRENT_BINARY_DIR}/libopen3d/install)
set(OPEN3D_SRC_DIR ${CMAKE_CURRENT_BINARY_DIR}/thirdparty/Open3D)
set(OPEN3D_BUILD_DIR ${OPEN3D_SRC_DIR}/build)
set(OPEN_CONFIG_CMD  cd ${OPEN3D_SRC_DIR} && mkdir -p build && cd build  && cmake 
                       -DBUILD_SHARED_LIBS=ON
                       -DBUILD_EXAMPLES=OFF 
                       -DBUILD_PYTHON_MODULE=OFF
                       -DGLIBCXX_USE_CXX11_ABI=ON 
                       -DCMAKE_INSTALL_PREFIX=${LIBOPEN3D_INSTALL} .. )
set(OPEN3D_BUILD_CMD  cd ${OPEN3D_BUILD_DIR} &&  make)
#set(OPEN3D_INSTALL_CMD cd ${OPEN3D_BUILD_DIR} && make install && mv ${LIBOPEN3D_INSTALL}/lib64 ${LIBOPEN3D_INSTALL}/lib)

ExternalProject_Add(
    Open3D
    PREFIX Open3D
    GIT_REPOSITORY https://github.com/intel-isl/Open3D.git
    GIT_TAG v0.15.0
    GIT_PROGRESS 1
    SOURCE_DIR ${OPEN3D_SRC_DIR}
    UPDATE_COMMAND ""
    CONFIGURE_COMMAND "${OPEN_CONFIG_CMD}"
    BUILD_COMMAND "${OPEN3D_BUILD_CMD}"
    INSTALL_COMMAND "${OPEN3D_INSTALL_CMD}"
)

include_directories(
    "${LIBOPEN3D_INSTALL}/include"
    "${LIBOPEN3D_INSTALL}/include/open3d/3rdparty"
)

link_directories(
    "${LIBOPEN3D_INSTALL}/lib"
)

set(OPEN3D_LIB ${LIBOPEN3D_INSTALL}/lib/libOpen3D.so)
