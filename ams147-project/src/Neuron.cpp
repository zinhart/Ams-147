#include "net/Neuron.h"

double Neuron::eta = 0.2; // overall net learning rate
/*	eta
	0.0-slow learner
	0.2-medium learner
	1.0-reckless learner
*/
double Neuron::alpha = 0.5; // momentum
/*	alpha-anything between 0 and 1
	0.0-no momentum
	0.5 moderate momentum
*/
void Neuron::setOutputVal(double val)
{
	outputVal = val;
}
double Neuron::getOutputVal()const
{
	return outputVal;
}
Neuron::Neuron(unsigned int numOutputs,unsigned int index)
{
	outputVal = 0.0;
	for (unsigned int connection = 0; connection < numOutputs; ++connection)
	{
		outputWeights.push_back(Connection());
		//set weight of connection just made to something random
		outputWeights.back().weight = randomWeight();
	}
	myIndex = index;
}
double Neuron::activationFunction(double x)
{
	// using hyperbolic tangent but any continous function works
	//tanh - output range [-1.0 - 1.0]
	/* when setting training data scale the output,
	   so that the output values are in the range,
	   of what the transfer function can make
	*/
	//relu
	//return (x > 0) ? x : 0;
    return tanh(x);
}
double Neuron::activationFunctionDerivative(double x)
{
    //derivative of relu
    return (x > 0) ? 1 : 0;
	//aproximate derivative of the relu is logistic function
    //return 1 / (1 + std::exp(-x));
    return 1.0 -(tanh(x)*tanh(x));
}
//sums inputs
void Neuron::feedForward(const Layer &prevLayer)
{
	double sum = 0.0;
	//sum previous layers outputs which are now inputs,
	//includes the bias node for the previous layer
	for (unsigned i = 0; i < prevLayer.size(); ++i)
	{
		sum += prevLayer[i].getOutputVal()*prevLayer[i].outputWeights[myIndex].weight;
	}
	//std::cout << "sum " << sum <<" "<<std::endl;
	outputVal = Neuron::activationFunction(sum);
	//std::cout << "outPutVal " << outputVal << " " << std::endl;
}
void Neuron::calcOutputGradients(double targetVal)
{
	double delta = targetVal - outputVal;
	gradient = delta*Neuron::activationFunctionDerivative(outputVal);
}
void Neuron::updateInputWeights(Layer & prevLayer)
{
	for (unsigned int i = 0; i < prevLayer.size(); ++i)
	{
		Neuron & neuron = prevLayer[i];
		double oldDeltaweight = neuron.outputWeights[myIndex].deltaWeight;
		double newDeltaWeight =
			//individual input, magnified by the gradient and train rate:
			eta*
			neuron.getOutputVal()
			*gradient
			//also add momentum= a fraction of the previous delta weight
			+ alpha
			*oldDeltaweight;
		neuron.outputWeights[myIndex].deltaWeight = newDeltaWeight;
		neuron.outputWeights[myIndex].weight += newDeltaWeight;
	}
}
double Neuron::sumDOW(const Layer & nextLayer)const
{
	double sum = 0.0;

	// sum out contributions of the errors at the nodes we feed,
	// not including bias neuron
	for (unsigned int i = 0; i < nextLayer.size() - 1; ++i)
	{
		sum += outputWeights[i].weight * nextLayer[i].gradient;
	}
	return sum;
}
void Neuron::calcHiddenGradients(const Layer & nextLayer)
{
	double dow = sumDOW(nextLayer);
	gradient = dow * Neuron::activationFunctionDerivative(outputVal);

}
