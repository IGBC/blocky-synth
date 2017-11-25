cmake_minimum_required(VERSION 3.5)
project(blocky-synth)

# Kill Microsoft Visual C++ compiler
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    message(FATAL_ERROR "Compiler not supported") # Die
endif()

# Set Flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic -std=c11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -std=c++14")

# Set Debug Options
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")

# Set Deployment Options
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_RELEASE} -O2")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")


#################
# Include Paths #
#################
set(INCLUDE_DIRS "${INCLUDE_DIRS};${CMAKE_CURRENT_SOURCE_DIR}/include")

# Sacrifice goat here

########################
# Set Libraries to Use #
########################
set(PROJECT_LIBS ${PROJECT_LIBS};) # Linux


###################
# Add main Target #
###################
set(MAIN_SRC
	main.cpp

	A440.c
	musical_utils.c

	audiosink.cpp
	streaming_interface.cpp

	blocks/ossilator.cpp
)

message("PROJECT_LIBS: ${PROJECT_LIBS}")
message("INCLUDE_DIRS: ${INCLUDE_DIRS}")
message("PROJECT_SRCS: ${MAIN_SRC}")

add_executable(main ${MAIN_SRC})
target_link_libraries(main ${PROJECT_LIBS})
target_include_directories(main PRIVATE ${INCLUDE_DIRS})
