#include "net/neuron.hh"

double neuron::eta = 0.2; // overall net learning rate
/*	eta
	0.0-slow learner
	0.2-medium learner
	1.0-reckless learner
*/
double neuron::alpha = 0.5; // momentum
/*	alpha-anything between 0 and 1
	0.0-no momentum
	0.5 moderate momentum
*/
void neuron::set_output_val(double val)
{
	output_val = val;
}
double neuron::get_output_val()const
{
	return output_val;
}
neuron::neuron(unsigned int numOutputs,unsigned int index)
{
	output_val = 0.0;
	for (unsigned int connection = 0; connection < numOutputs; ++connection)
	{
		output_weights.push_back(Connection());
		//set weight of connection just made to something random
		output_weights.back().weight = random_weight();
	}
	my_index = index;
}
double neuron::activation_function(double x)
{
	// using hyperbolic tangent but any continous function works
	//tanh - output range [-1.0 - 1.0]
	/* when setting training data scale the output,
	   so that the output values are in the range,
	   of what the transfer function can make
	*/
	//relu
	//return (x > 0) ? x : 0;
    return tanh(x);
}
double neuron::activation_function_derivative(double x)
{
    //derivative of relu
    return (x > 0) ? 1 : 0;
	//aproximate derivative of the relu is logistic function
    //return 1 / (1 + std::exp(-x));
    return 1.0 -(tanh(x)*tanh(x));
}
//sums inputs
void neuron::forward_propagate(const Layer & prev_layer)
{
	double sum = 0.0;
	//sum previous layers outputs which are now inputs,
	//includes the bias node for the previous layer
	for (unsigned i = 0; i < prev_layer.size(); ++i)
	{
		sum += prev_layer[i].get_output_val() * prev_layer[i].output_weights[my_index].weight;
	}
	//std::cout << "sum " << sum <<" "<<std::endl;
	output_val = neuron::activation_function(sum);
	//std::cout << "outPutVal " << output_val << " " << std::endl;
}
void neuron::calc_output_gradients(double target_val)
{
	double delta = target_val - output_val;
	gradient = delta * neuron::activation_function_derivative(output_val);
}
void neuron::update_input_weights(Layer & prev_layer)
{
	for (unsigned int i = 0; i < prev_layer.size(); ++i)
	{
		neuron & n = prev_layer[i];
		double old_delta_weight = n.output_weights[my_index].delta_weight;
		double new_delta_weight =
			//individual input, magnified by the gradient and train rate:
			eta*
			n.get_output_val()
			*gradient
			//also add momentum= a fraction of the previous delta weight
			+ alpha
			*old_delta_weight;
		n.output_weights[my_index].delta_weight = new_delta_weight;
		n.output_weights[my_index].weight += new_delta_weight;
	}
}
double neuron::sum_DOW(const Layer & next_layer)const
{
	double sum = 0.0;

	// sum out contributions of the errors at the nodes we feed,
	// not including bias neuron
	for (unsigned int i = 0; i < next_layer.size() - 1; ++i)
	{
		sum += output_weights[i].weight * next_layer[i].gradient;
	}
	return sum;
}
void neuron::calc_hidden_gradients(const Layer & next_layer)
{
	double dow = sum_DOW(next_layer);
	gradient = dow * neuron::activation_function_derivative(output_val);
}
