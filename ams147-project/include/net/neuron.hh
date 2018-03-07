#ifndef NEURON_HH
#define NEURON_HH
#include "common.hh" //for includes
namespace zinhart
{
  class neuron;
  using Layer = std::vector<neuron>;
  class neuron
  {
	public:
	  //num of connections or outputs each neuron has
	  neuron(std::uint32_t num_outputs, std::uint32_t index);
	  void set_output_val(double val);
	  double get_output_val()const;
	  void forward_propagate(const Layer & prev_layer);
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
	  std::uint32_t my_index;
	  std::vector<Connection> output_weights;
	  double gradient;
  };
}
#endif
