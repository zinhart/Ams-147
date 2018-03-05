#include "net/TrainingData.h"

void TrainingData::getTopology(std::vector<unsigned int> &topology)
{
	std::string line;
	std::string label;

	std::getline(trainingDataFile, line);
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

TrainingData::TrainingData(const std::string filename)
{
	trainingDataFile.open(filename.c_str());
}

unsigned int TrainingData::getNextInputs(std::vector<double> &inputVals)
{
	inputVals.clear();

	std::string line;
	std::getline(trainingDataFile, line);
	std::stringstream ss(line);

	std::string label;
	ss >> label;
	if (label.compare("in:") == 0) {
		double oneValue;
		while (ss >> oneValue) {
			inputVals.push_back(oneValue);
		}
	}

	return inputVals.size();
}

unsigned int TrainingData::getTargetOutputs(std::vector<double> &targetOutputVals)
{
	targetOutputVals.clear();

	std::string line;
	std::getline(trainingDataFile, line);
	std::stringstream ss(line);

	std::string label;
	ss >> label;
	if (label.compare("out:") == 0) {
		double oneValue;
		while (ss >> oneValue) {
			targetOutputVals.push_back(oneValue);
		}
	}

	return targetOutputVals.size();
}
