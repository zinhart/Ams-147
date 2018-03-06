find_package(SWIG REQUIRED)
find_package(Octave REQUIRED)
include(${SWIG_USE_FILE})
include_directories(${OCTAVE_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SRC_DIR})
set_property(SOURCE net.i PROPERTY CPLUSPLUS ON)
swig_add_module(Net octave net.i)
swig_link_libraries(Net net )
file(COPY ${CMAKE_SOURCE_DIR}/training-data DESTINATION ${CMAKE_CURRENT_BINARY_DIR}) #putting a directory

