set(net_src
  Net.cpp 
  TrainingData.cpp
  Neuron.cpp  	
)

add_library(net ${net_src})
#target_link_libraries(net net_src)

install(TARGETS net LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(DIRECTORY ../include/net DESTINATION include)
