%dependecies in order control signal communications all for randint
function retval = model( network_topology, max_iters, epsilon)
  zinhart; % load module
  pkg load communications;% for randint
  total_layers = length(network_topology);
  input_layer_size = network_topology(1);
  output_layer_size = network_topology(end);
  topology = zinhart.vec_ui();  % c++ std vector

  for i = 1: total_layers
    topology.append( network_topology(i) );
  endfor
%{
  for i = 0 : total_layers - 1
     disp(topology(i));
  endfor
  %}

  training_data = zinhart.zstring("training_data/out_or.txt"); 
  training_results = zinhart.zstring("training_data/resultOrTraining.txt");
  ann = zinhart.net(topology,training_data,training_results); % artificial neural net
  inputs =  zinhart.vec_d(input_layer_size, 0);
  outputs = zinhart.vec_d(output_layer_size, 0);
  targets =  zinhart.vec_d(output_layer_size, 0);  
  error = [];
  %karma lloyd banks
  %ja rule down as chick
  for current_iter = 1 : max_iters  %training loop begin
    input_t = [];
    for ith_input = 0 : input_layer_size - 1
      inputs(ith_input) = randint(1); %get random inputs in the input domain
      input_t = [input_t inputs(ith_input)];
    endfor
    for ith_target = 1: output_layer_size
      targets(ith_target .- 1) = logical_or(input_t); %get target for specific input
    endfor
    ann.forward_propagate(inputs);% trial with current weights
    ann.get_results(outputs);
    ann.backward_propagate(targets);% update weight
    error = [error ann.get_recent_average_error()];
    
    %disp(inputs(0));
    %disp(inputs(1));
    disp(input_t);
    disp(targets(0));
    disp(outputs(0));
    disp(error);
  endfor
  
%{
  %calc accuracy etc

  %graph accuracy
%}
  
  testing_results = zinhart.zstring("training_data/resultOrTesting.txt");  
  %disp(ann.get_training_data_file());
  %disp(ann.get_testing_data_file());
%done 
   bagel = zinhart.vec_d([1,2,3]);
  # bagel = [1,2,3];

clear zinhart; 
clear classes;
pkg unload communications;
endfunction
