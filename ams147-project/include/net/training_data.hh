#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
class training_data
{
public:
	training_data(const std::string filename);
    bool isEof() { return training_data_file.eof(); }
	void get_topology(std::vector<unsigned int> & topology);
	unsigned int get_next_inputs(std::vector<double>&input_vals);
	unsigned int get_target_outputs(std::vector<double> &target_output_vals);
private:
	std::ifstream training_data_file;
};
