#pragma once
#include "Neuron.h"
#include<iostream>
#include<cassert>
class Net
{
public:
	Net(const std::vector<unsigned int> &topology);
	//responsible for taking inputs in and feeding them forward to the next neuron
	void feedForward(const std::vector<double> &inputVals);
	void backProp(const std::vector<double> &targetVals);
	void getResults(std::vector<double> &resultsVals)const;
	double getRecentAverageError() const;
private:
	std::vector<Layer> layers;
	double error;
	double recentAverageError;
	static double recentAverageSmoothingFactor;
};
