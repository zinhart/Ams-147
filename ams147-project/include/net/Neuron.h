#pragma once
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>
class Neuron;
typedef std::vector<Neuron> Layer;
class Neuron
{
public:
	//num of connections or outputs each neuron has
	Neuron(unsigned int numOutputs,unsigned int index);
	void setOutputVal(double val);
	double getOutputVal()const;
	void feedForward(const Layer &prevLayer);
	void calcOutputGradients(double targetVal);
	void calcHiddenGradients(const Layer & nextLayer);
	void updateInputWeights(Layer & prevLayer);
private:
	static double eta; // {0.0 - 1.0} overall net training rate
	static double alpha; // {0.0 ... n} multiplier of last weight change (momentum)
	//also called transfer function in the books
	static double activationFunction(double x);
	static double activationFunctionDerivative(double x);
	//returns a number between 0 and 1;
	static double randomWeight() { return rand() / double(RAND_MAX); }
	double sumDOW(const Layer & nextLayer)const;
	struct Connection
	{
		double weight;
		double deltaWeight;
        Connection() :weight(0.0), deltaWeight(0.0) {}
	};
	double outputVal;
	unsigned int myIndex;
	std::vector<Connection> outputWeights;
	double gradient;
};
