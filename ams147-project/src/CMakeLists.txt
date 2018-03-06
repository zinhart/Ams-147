set(net_src
  Net.cpp 
  TrainingData.cpp
  Neuron.cpp  	
)

add_library(net ${LIB_TYPE} ${net_src})
install(TARGETS net LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(DIRECTORY ../include/net  DESTINATION include)
