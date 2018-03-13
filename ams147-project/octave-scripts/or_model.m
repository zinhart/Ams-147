%dependecies in order control signal communications all for randint
%[2,5,1] 2000, 1.e-15, 400
function retval = or_model(network_topology, max_iters, tolerance, validation_cases)
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
  train_output = [];
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
    train_error (end+1) = ann.get_recent_average_error();
    %if ( train_error(end) <= tolerance )
     %   break;
    %endif
  endwhile
 
  disp("finish training");
  
  inputs =  zinhart.vec_d(input_layer_size, 0);
  outputs = zinhart.vec_d(output_layer_size, 0);
  targets =  zinhart.vec_d(output_layer_size, 0); 
  
  
  correct_cases = 0;
  test_error = [];
  output_val = [];
  target_val = [];
  current_iter = 1;
  printf("beggining validation phase\n");
  while current_iter < validation_cases % validation loop
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
    output_val(end+1) = outputs(0);
    target_val(end+1) = targets(0);
    ++current_iter;
    test_error(end+1) = ann.get_recent_average_error();
    %if (test_error(current_iter) - outputs(0) <= tolerance)
     %   ++correct_cases;
    %endif
  endwhile
  
  fig1 = figure(1);
  
  axis equal;
  total_training_iterations = linspace(0, length(train_error), length(train_error) );
  plot(total_training_iterations,train_error ); %error wrt iterations
  title("Figure 1: Learning The OR Gate Training");
  xlabel("Iteration");
  ylabel("Training Error");
  printf("total_training_iterations:%i\n",length(train_error)+1);
  printf("training_error:%d\n",train_error(end));
  saveas(1, "or_training_error_plot.png" );
  
  fig2 = figure(2);
  hold on;
  accuracy = linspace(0, 1, length(target_val));
  plot(output_val, target_val);
  title("Figure 2: Learning The OR Gate Decision Boundary");
  xlabel("Model Output");
  ylabel("Target Value");
  saveas(2, "or_decision_plot.png" );
  
  hold off;
  clear zinhart; 
  clear classes;
  

  pkg unload communications;
endfunction
