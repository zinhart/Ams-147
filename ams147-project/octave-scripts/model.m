%dependecies in order control signal communications all for randint
function retval = model( network_topology, max_iters, tolerance, validation_cases)
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
  train_error = [];
  %karma lloyd banks
  %ja rule down as chick
  total_training_iterations = 0;
  current_iter = 1;
  while current_iter < max_iters
  %for current_iter = 1 : max_iters  %training loop begin
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
    ++current_iter;
    total_training_iterations (end+1) = current_iter;
    train_error (end+1) = ann.get_recent_average_error();
    if ( train_error(end) <= tolerance )
        break;
    endif
  endwhile
 
  disp("finish training");
  
  inputs =  zinhart.vec_d(input_layer_size, 0);
  outputs = zinhart.vec_d(output_layer_size, 0);
  targets =  zinhart.vec_d(output_layer_size, 0); 
  
  
  correct_cases = 0;
  test_error = [];
  printf("beggining validation phase\n");
  for i = 1 : validation_cases % validation loop
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
    test_error = [test_error ann.get_recent_average_error()];
    if (test_error(i) - outputs(0) <= tolerance)
        ++correct_cases;
    endif
  endfor
  printf("correct cases %i\n",correct_cases);
  printf("total training iterations %i\n", current_iter);
  x = linspace(0, 100, length(train_error) );
  plot(x,train_error);

  %graph accuracy
%}
  
 
clear zinhart; 
clear classes;
pkg unload communications;
endfunction
