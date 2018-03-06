find_package(SWIG REQUIRED)
find_package(Octave REQUIRED)
include(${SWIG_USE_FILE})
include_directories(${OCTAVE_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SRC_DIR})
set(MODULE_NAME "zinhart")
set(INTERFACE_NAME "${MODULE_NAME}.i")
set(OCTAVE_SCRIPT ${CMAKE_SOURCE_DIR}/octave-scripts/model.m)
set_property(SOURCE ${INTERFACE_NAME} PROPERTY CPLUSPLUS ON)
swig_add_module(${MODULE_NAME} octave ${INTERFACE_NAME})
swig_link_libraries(${MODULE_NAME} net )
file(COPY ${CMAKE_SOURCE_DIR}/training-data DESTINATION ${CMAKE_CURRENT_BINARY_DIR}) #putting a directory
configure_file(${OCTAVE_SCRIPT} model.m @ONLY) #putting octave file


