cmake_minimum_required(VERSION 3.12)

#setting up the compiler warnings... 
if(CMAKE_COMPILER_IS_GNUCXX)
	#appending gcc flags
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
else()
	message("The compiler is not gcc. Please configure PC_METRIC_CompilerOptimizations.cmake")
endif()
