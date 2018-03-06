#include "net/training_data.hh"

void training_data::get_topology(std::vector<unsigned int> &topology)
{
	std::string line;
	std::string label;

	std::getline(training_data_file, line);
	std::stringstream ss(line);
	ss >> label;
	std::cout<<line<<"\n";
	if (this->isEof() || label.compare("topology:") != 0) 
	{
	    std::cout<<"Gotcha!\n";
		std::abort();
	}

	while (!ss.eof()) {
		unsigned int n;
		ss >> n;
		topology.push_back(n);
	}
	return;
}

training_data::training_data(const std::string filename)
{
	training_data_file.open(filename.c_str());
}

unsigned int training_data::get_next_inputs(std::vector<double> &input_vals)
{
	input_vals.clear();

	std::string line;
	std::getline(training_data_file, line);
	std::stringstream ss(line);

	std::string label;
	ss >> label;
	if (label.compare("in:") == 0) {
		double one_value;
		while (ss >> one_value) {
			input_vals.push_back(one_value);
		}
	}

	return input_vals.size();
}

unsigned int training_data::get_target_outputs(std::vector<double> &target_output_vals)
{
	target_output_vals.clear();

	std::string line;
	std::getline(training_data_file, line);
	std::stringstream ss(line);

	std::string label;
	ss >> label;
	if (label.compare("out:") == 0) {
		double one_value;
		while (ss >> one_value) {
			target_output_vals.push_back(one_value);
		}
	}

	return target_output_vals.size();
}
