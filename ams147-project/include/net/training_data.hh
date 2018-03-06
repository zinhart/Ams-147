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
    bool isEof() { return trainingDataFile.eof(); }
	void getTopology(std::vector<unsigned int> & topology);
	unsigned int getNextInputs(std::vector<double>&inputVals);
	unsigned int getTargetOutputs(std::vector<double> &targetOutputVals);
private:
	std::ifstream trainingDataFile;
};
