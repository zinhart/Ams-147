include_directories(.)
set(logic_gate_src main.cpp)
add_executable(logic_gate ${logic_gate_src})
target_link_libraries(logic_gate net)
