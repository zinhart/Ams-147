#ifndef NET_HH
#define NET_HH
#include "neuron.hh"
#include <iostream>
#include <cassert>
class net
{
public:
    net();
	net(const std::vector<unsigned int> &topology, std::string training_data, std::string training_results);
	void forward_propagate(const std::vector<double> & input_vals);
	void backward_propagate(const std::vector<double> & target_vals);
	void get_results(std::vector<double> &results_vals)const;
	double get_recent_average_error() const;
	void train(unsigned int max_iter, double epsilon);
	void set_training_data(std::string file);
	void set_training_results(std::string file);
	std::string get_training_data_file()const;
	std::string get_testing_data_file()const;
private:
	std::vector<Layer> layers;
	double error;
	double recent_average_error;
	static double recent_average_smoothing_factor;
	std::string training_data;
	std::string training_results;
};
#endif
