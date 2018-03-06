include_directories(${CMAKE_CURRENT_SRC_DIR})
set(logic_gate_src main.cpp)
add_executable(logic_gate ${logic_gate_src})
target_link_libraries(logic_gate net)
#configure_file(main.cpp main.cpp.x @ONLY) #putting one file
file(COPY ${CMAKE_SOURCE_DIR}/training-data DESTINATION ${CMAKE_CURRENT_BINARY_DIR}) #putting a directory

