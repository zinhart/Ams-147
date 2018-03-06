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
	//responsible for taking inputs in and feeding them forward to the next neuron
	void feedForward(const std::vector<double> &inputVals);
	void backProp(const std::vector<double> &targetVals);
	void getResults(std::vector<double> &resultsVals)const;
	double getRecentAverageError() const;
	void setTrainingData(std::string file);
	void setTrainingResults(std::string file);
	std::string getTrainingDataFile()const;
	std::string getTestingDataFile()const;
private:
	std::vector<Layer> layers;
	double error;
	double recentAverageError;
	static double recentAverageSmoothingFactor;
	std::string training_data;
	std::string training_results;
};
#endif
