#ifndef NEURON_HH
#define NEURON_HH
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>
class neuron;
typedef std::vector<neuron> Layer;
class neuron
{
public:
	//num of connections or outputs each neuron has
	neuron(unsigned int num_outputs,unsigned int index);
	void set_output_val(double val);
	double get_output_val()const;
	void forward_propagate(const Layer &prev_layer);
	void calc_output_gradients(double target_val);
	void calc_hidden_gradients(const Layer & next_layer);
	void update_input_weights(Layer & prev_layer);
private:
	static double eta; // {0.0 - 1.0} overall net training rate
	static double alpha; // {0.0 ... n} multiplier of last weight change (momentum)
	//also called transfer function in the books
	static double activation_function(double x);
	static double activation_function_derivative(double x);
	//returns a number between 0 and 1;
	static double random_weight() { return rand() / double(RAND_MAX); }
	double sum_DOW(const Layer & next_layer)const;
	struct Connection
	{
		double weight;
		double delta_weight;
        Connection() :weight(0.0), delta_weight(0.0) {}
	};
	double output_val;
	unsigned int my_index;
	std::vector<Connection> output_weights;
	double gradient;
};
#endif
