cmake_minimum_required(VERSION 3.12)

#setting up the compiler warnings... 
if(CMAKE_COMPILER_IS_GNUCXX)
	#appending gcc flags
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -Wno-error=maybe-uninitialized -fPIC -fopenmp -Wall  -Wno-deprecated-declarations -Wno-unused-result")
	add_definitions(-Wfatal-errors)
else()
	message("The compiler is not gcc. Configure cmake/TPCQMWarnings.cmake")
endif()
