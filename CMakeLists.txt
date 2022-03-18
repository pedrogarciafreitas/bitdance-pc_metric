cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)

project(BITDANCE)

set (BITDANCE "BitDance: Low Complexity Point Cloud Quality Assessment Metric")

# The version number.
set (BITDANCE_VERSION_MAJOR 0)
set (BITDANCE_VERSION_MINOR 1)
set (BITDANCE_VERSION_PATCH 0)



#configuring paths
set(CMAKE_MODULE_PATH "${CMAKE_HOME_DIRECTORY}/cmake;${CMAKE_MODULE_PATH}")
set(CMAKE_LIBRARY_DIR ${CMAKE_SOURCE_DIR}/bin/lib)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin/programs)
set(CMAKE_TESTS_DIR ${CMAKE_SOURCE_DIR}/bin/tests)


set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(EXECUTABLE_TEST_PATH ${CMAKE_TESTS_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_DIR})


##puts the configuration file in the binary dir
configure_file (
  "${CMAKE_HOME_DIRECTORY}/cmake/BITDANCEConfig.h.in"
  "${PROJECT_BINARY_DIR}/BITDANCEConfig.h"
  )


include_directories("${PROJECT_BINARY_DIR}")

include_directories(.)
include_directories(doc)
include_directories(source)

#configuring the compiler
include(BITDANCE_Warnings)
include(BITDANCE_CompilerOptimizations)

#including external libraries by downloading them from git..
include(ExternalGoogleTest)
include(ExternalOpen3D)


link_libraries(stdc++fs)
link_libraries(z)
link_libraries(m)

# directories here header files may be found
include_directories(source)

#setting up the doxygen documentation build
option(BUILD_DOC "Build documentation" OFF)

# # Executables
#add_subdirectory(${CMAKE_HOME_DIRECTORY}/source/)



# Testings
enable_testing()
add_subdirectory(${CMAKE_HOME_DIRECTORY}/tests/)
add_subdirectory(${CMAKE_HOME_DIRECTORY}/tests/ThirdPartyLibs/)


if(BUILD_DOC)
  find_package(Doxygen)
  if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_SOURCE_DIR}/cmake/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_SOURCE_DIR}/doc/Doxyfile)

    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Documentation build started")

    add_custom_target( doxygen ALL
      COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
      COMMENT "Generating API documentation with Doxygen"
      VERBATIM )
  else (DOXYGEN_FOUND)
    message("Doxygen must be installed to generate the documentation.")
  endif (DOXYGEN_FOUND)
endif(BUILD_DOC)
