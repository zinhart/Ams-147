#include "net/net.hh"
namespace zinhart
{
  double net::recent_average_smoothing_factor = 50.0; // Number of training samples to average over
  net::net()
  {
	recent_average_error = 0;
  }
  net::net(const std::vector<std::uint32_t> & topology, std::string training_data, std::string training_results)
  {
	set_training_data(training_data);
	set_training_results(training_results);
	recent_average_error = 0;
	std::uint32_t numLayers = topology.size();
	//make layers (outer loop)
	for (std::uint32_t layer_num = 0; layer_num < numLayers; ++layer_num)
	{
  	  layers.push_back(Layer());
		/*ternary expression: if the layer_num is the output layer then it has 0 outputs,
		  otherwise the number of outputs is whatever is in topology for the next layer over
		*/
	  std::uint32_t num_outputs = layer_num == topology.size() - 1 ? 0 : topology[layer_num + 1];
		//fill layers with Neurons (inner loop)
		//the <= add a bias neuron
	  for (std::uint32_t neuron_num = 0; neuron_num <= topology[layer_num]; ++neuron_num)
  	  {
		layers.back().push_back(neuron(num_outputs, neuron_num));
	  }
	}
	
	//set bias output
	layers.back().back().set_output_val(1.0);
  }
  void net::train(std::uint32_t max_iter, double epsilon)
  {
	assert(topology.size() > 0);
	std::vector<double> input_vals;
	std::vector<double> target_vals;
	std::vector<double> result_vals;
	std::uint32_t training_pass;
	for(std::uint32_t i = 0, training_pass = 0; i < max_iter; ++i, ++training_pass)
	{
	  forward_propagate(input_vals);
	  get_results(result_vals);
	}
  }
  void net::forward_propagate(const std::vector<double> &input_vals)
  {
	//check to see that the number of elements in input vals is the same as the number of elements in the input layer
	assert(input_vals.size() == layers[0].size() - 1);
	
	//assign input vals to input neurons
	for (std::uint32_t i = 0; i < input_vals.size(); ++i)
	{
  	  layers[0][i].set_output_val(input_vals[i]);
	}
	//forward propagate
	for (std::uint32_t layer_num = 1; layer_num < layers.size(); ++layer_num)
	{
	  Layer & prev_layer = layers[layer_num - 1];
	  for (std::uint32_t i = 0; i < layers[layer_num].size()-1; ++i)
	  {
		layers[layer_num][i].forward_propagate(prev_layer);
	  }
	}
  }
  void net::backward_propagate(const std::vector<double> &target_vals)
  {
	//responsibilities of backward_propagate
	/*
        1. calculate overall net error (for this will use mean square error (rms))
		2. calculate output layer gradients 
		3. calculate gradients on hidden layers
		4. for all layers from ouputs to first hidden layer, update connection weights
	*/

	// 1 
	Layer & output_layer = layers.back();
	error = 0.0;
	for (std::uint32_t i = 0; i < output_layer.size() - 1; ++i)
	{
	  double delta = target_vals[i] - output_layer[i].get_output_val();
	  error += delta*delta;
	}
	error /= output_layer.size() - 1;
	//error = sqrt(error);//rms

	// a recent average measurement
	recent_average_error = (recent_average_error * recent_average_smoothing_factor + error) / (recent_average_smoothing_factor + 1.0);
	//2
	for (std::uint32_t i = 0; i < output_layer.size() - 1; ++i)
	{
  	  output_layer[i].calc_output_gradients(target_vals[i]);
	}
	//3
	for (std::uint32_t i = layers.size()-2; i >0; --i)
	{
	  Layer & hidden_layer = layers[i];
	  Layer & next_layer = layers[i + 1];
	  for (std::uint32_t j = 0; j < hidden_layer.size(); ++j)
	  {
		hidden_layer[j].calc_hidden_gradients(next_layer);
	  }
	}
	//4
	for (std::uint32_t i = layers.size() - 1; i > 0; --i)
	{
	  Layer & layer = layers[i];
	  Layer & prev_layer = layers[i - 1];
	  for (std::uint32_t j = 0; j < layer.size()-1; ++j)
	  {
		layer[j].update_input_weights(prev_layer);
	  }
	}
  }
  double net::get_recent_average_error() const 
  { 
	return recent_average_error; 
  }
  void net::get_results(std::vector<double> &results_vals)const
  {
	results_vals.clear();
	for (std::uint32_t i = 0; i < layers.back().size() - 1; ++i)
	{
	  results_vals.push_back(layers.back()[i].get_output_val());
	}
  }
  void net::set_training_data(std::string training_data)
  {
	assert(training_data.size() != 0);
	this->training_data = training_data;
  }
  void net::set_training_results(std::string training_results)
  {
	assert(training_results.size() != 0);
	this->training_results = training_results;
  }
  std::string net::get_training_data_file()const
  {
	return this->training_data;
  }
  std::string net::get_testing_data_file()const
  {
	return this->training_results;
  }
}

