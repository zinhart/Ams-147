set(net_src
  net.cc
  training_data.cc
  neuron.cc  	
)

add_library(net ${LIB_TYPE} ${net_src})
install(TARGETS net LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(DIRECTORY ../include/net  DESTINATION include)
