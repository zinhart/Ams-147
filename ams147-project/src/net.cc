#include "net/net.hh"
double net::recentAverageSmoothingFactor = 50.0; // Number of training samples to average over
net::net()
{
}
net::net(const std::vector<unsigned int> &topology, std::string training_data, std::string training_results)
{
    setTrainingData(training_data);
	setTrainingResults(training_results);
    recentAverageError=0;
	unsigned int numLayers = topology.size();
	//make layers (outer loop)
	for (unsigned int layerNum = 0; layerNum < numLayers; ++layerNum)
	{
		layers.push_back(Layer());
		/*ternary expression: if the layerNum is the output layer then it has 0 outputs,
		  otherwise the number of outputs is whatever is in topology for the next layer over
		*/
		unsigned int numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];
		//fill layers with Neurons (inner loop)
		//the <= add a bias neuron
		for (unsigned int neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum)
		{
			layers.back().push_back(neuron(numOutputs,neuronNum));
		}
	}
	
	//set bias output
	layers.back().back().setOutputVal(1.0);
}
void net::feedForward(const std::vector<double> &inputVals)
{
	//check to see that the number of elements in input vals is the same as the number of elements in the input layer
	assert(inputVals.size() == layers[0].size() - 1);
	
	//assign input vals to input neurons
	for (unsigned int i = 0; i < inputVals.size(); ++i)
	{
		layers[0][i].setOutputVal(inputVals[i]);
	}
	//forward propagate
	for (unsigned int layerNum = 1; layerNum < layers.size(); ++layerNum)
	{
		Layer &prevLayer = layers[layerNum - 1];
		for (unsigned int i = 0; i < layers[layerNum].size()-1; ++i)
		{
			layers[layerNum][i].feedForward(prevLayer);
		}
	}
}
void net::backProp(const std::vector<double> &targetVals)
{
	//responsibilities of backProp
	/*
        1. calculate overall net error (for this will use mean square error (rms))
		2. calculate output layer gradients 
		3. calculate gradients on hidden layers
		4. for all layers from ouputs to first hidden layer, update connection weights
	*/

	// 1 
	Layer & outputLayer = layers.back();
	error = 0.0;
	for (unsigned int i = 0; i < outputLayer.size() - 1; ++i)
	{
		double delta = targetVals[i] - outputLayer[i].getOutputVal();
		error += delta*delta;
	}
	error /= outputLayer.size() - 1;
	//error = sqrt(error);//rms

	// a recent average measurement
	recentAverageError = (recentAverageError*recentAverageSmoothingFactor + error) / (recentAverageSmoothingFactor + 1.0);
	//2
	for (unsigned int i = 0; i < outputLayer.size() - 1; ++i)
	{
		outputLayer[i].calcOutputGradients(targetVals[i]);
	}
	//3
	for (unsigned int i = layers.size()-2; i >0; --i)
	{
		Layer & hiddenLayer = layers[i];
		Layer & nextLayer = layers[i + 1];
		for (unsigned int j = 0; j < hiddenLayer.size(); ++j)
		{
			hiddenLayer[j].calcHiddenGradients(nextLayer);
		}
		
	}
	//4
	for (unsigned int i = layers.size() - 1; i > 0; --i)
	{
		Layer & layer = layers[i];
		Layer & prevLayer = layers[i - 1];
		for (unsigned int j = 0; j < layer.size()-1; ++j)
		{
			layer[j].updateInputWeights(prevLayer);
		}
	}
}
double net::getRecentAverageError() const 
{ 
	return recentAverageError; 
}
void net::getResults(std::vector<double> &resultsVals)const
{
	resultsVals.clear();
	for (unsigned int i = 0; i < layers.back().size() - 1; ++i)
	{
		resultsVals.push_back(layers.back()[i].getOutputVal());
	}
}

void net::setTrainingData(std::string training_data)
{
  assert(training_data.size() != 0);
  this->training_data = training_data;
}
void net::setTrainingResults(std::string training_results)
{
  assert(training_results.size() != 0);
  this->training_results = training_results;
}
std::string net::getTrainingDataFile()const
{
  return this->training_data;
}
std::string net::getTestingDataFile()const
{
  return this->training_results;
}
