include_directories(${OCTAVE_INCLUDE_DIRS})

set(CMAKE_SWIG_FLAGS "")
set (INTERFACE_LOCATION ${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME}/${PROJECT_NAME}.i)
set_source_files_properties(${INTERFACE_LOCATION} PROPERTIES CPLUSPLUS ON)
#include_directories(../..)

#add swig module
set(mynet ${net})
swig_add_module(mynet octave ${INTERFACE_LOCATION})
swig_link_libraries(mynet ${PROJECT_NAME} ${OCTAVE_LINK_LIBRARIES})

#maybe more
set(OCTAVE_INSTALL_FILES ${CMAKE_CURRENT_BINARY_DIR}/libnet.a)
