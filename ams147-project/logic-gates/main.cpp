#include "net/Net.h"
#include "net/TrainingData.h"
#include <fstream>
#include <string>
#include <sstream>
#include <random>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <math.h>
void showVectorVals(std::string label, std::vector<double> &v);
void showVectorVals(std::string label, std::vector<double> &v, std::fstream &outPutFile);
int main()
{
	std::string datadir = "training-data/";
    std::string trainingOr = datadir + "out_or.txt";
	std::cout<<trainingOr<<"\n";
    std::string trainingOrResults = datadir +"resultsOrTraining.txt";
    std::string testingOrResults = datadir + "resultsOrTesting.txt";

    std::string trainingXOr = datadir + "out_xor.txt";
    std::string trainingXOrResults = datadir + "resultsXOrTraining.txt";

    std::string trainingAnd = datadir + "out_and.txt";
    std::string trainingAndResults ="resultsAndTraining.txt";

    std::string trainingNot = datadir + "out_no.txt";
    std::string trainingNotResults = datadir + "resultsNotTraining.txt";
    TrainingData trainData(trainingOr);

    // e.g., { 3, 2, 1 }
    std::vector<unsigned int> topology;
    trainData.getTopology(topology);
    std::cout<<"Topology ";
    for(unsigned i=0; i<topology.size();++i)
    {
       std::cout<<topology[i]<<" ";
    }
    std::cout<<"\n";
    Net myNet(topology);

    std::vector<double> inputVals;
    std::vector<double> targetVals;
    std::vector<double> resultVals;
    int trainingPass = 0;
    std::fstream resultFile(trainingOrResults, std::ios::out);
    while (!trainData.isEof())
    {
        ++trainingPass;
        //std::cout << std::endl << "Pass " << trainingPass;
        resultFile<< std::endl << "Pass " << trainingPass;

        // Get new input data and feed it forward:
        if (trainData.getNextInputs(inputVals) != topology[0])
        {
            break;
        }
        showVectorVals(": Inputs:", inputVals,resultFile);
        myNet.feedForward(inputVals);

        // Collect the net's actual output results:
        myNet.getResults(resultVals);
        showVectorVals("Outputs:", resultVals,resultFile);

        // Train the net what the outputs should have been:
        trainData.getTargetOutputs(targetVals);
        showVectorVals("Targets:", targetVals,resultFile);

        assert(targetVals.size() == topology.back());
        myNet.backProp(targetVals);
        //std::cout << "here2" << std::endl;
        // Report how well the training is working, average over recent samples:
        //std::cout << "Net recent average error: "<< myNet.getRecentAverageError() << std::endl;
        resultFile << "Net recent average error: "
            << myNet.getRecentAverageError() << std::endl;
    }

    //std::cout << std::endl << "Done" << std::endl;
    resultFile<< std::endl << "Done" << std::endl;
    resultFile.close();
    const int True=1.0;
    const int False=0.0;
    unsigned testCases=500;
    int result;
    int correctPredictions=0;
    std::random_device r;
    std::mt19937 mt(r());
    std::uniform_int_distribution<int>dist(1,4);
    resultFile.open(testingOrResults,std::ios::out);
    //test set for or
    for(unsigned int i=0; i<testCases;++i)
    {
        result= dist(mt);
        if(result==1)
        {
            inputVals.push_back(True);
            inputVals.push_back(True);

        }
        else if(result==2)
        {
            inputVals.push_back(True);
            inputVals.push_back(False);
        }
        else if(result==3)
        {
            inputVals.push_back(False);
            inputVals.push_back(True);

        }
        else if(result==4)
        {
            inputVals.push_back(False);
            inputVals.push_back(False);
        }
        myNet.feedForward(inputVals);
        myNet.getResults(resultVals);
        //std::cout<<"\ninput "<<inputVals[0]<<" "<<inputVals[1]<<" result "<<result<<" result val "<<resultVals[0];
        showVectorVals("Input: ",inputVals,resultFile);
        showVectorVals("Output: ",resultVals,resultFile);
        switch (result) {
        case 1:
            (std::round(resultVals[0])==True) ? (++correctPredictions,resultFile<<"Pass\n\n") : resultFile<<"Fail\n\n";
            break;
        case 2:
            (std::round(resultVals[0])==True) ? ++correctPredictions,resultFile<<"Pass\n\n" : resultFile<<"Fail\n\n";
            break;
        case 3:
            (std::round(resultVals[0])== True) ? ++correctPredictions , resultFile<<"Pass\n\n" : resultFile<<"Fail\n\n";
            break;
        case 4:
            (std::round(resultVals[0])==False) ? ++correctPredictions,resultFile<<"Pass\n\n" : resultFile<<"Fail\n\n";
            break;
        default:
            std::cout<<"wtf\n";
            break;
        }
        inputVals.clear();
    }
    std::cout<<"\nTotal Test cases "<<testCases;
    std::cout<<"\nTotal correct predictions "<<correctPredictions<<"\n";
    //make input var to test

  /*const std::string end = "`";
    std::string args="\0";
    while(args != end)
    {
        inputVals.clear();
        std::cout<<"Enter arg1\n";
        std::cin>>args;
        inputVals.push_back(std::stod(args));
        std::cout<<"Enter arg2\n";
        args.clear();
        std::cin>>args;
        inputVals.push_back(std::stod(args));
        std::cout<<"size: "<<inputVals.size()<<"\n";
        myNet.feedForward(inputVals);
        myNet.getResults(resultVals);
        showVectorVals("Input: ",inputVals);
        showVectorVals("Output: ",resultVals);
        args.clear();
    }*/
	
    return 0;
}
void showVectorVals(std::string label, std::vector<double> &v)
{
    std::cout << label << " ";
    for (unsigned int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}
void showVectorVals(std::string label, std::vector<double> &v, std::fstream &outPutFile)
{
    //std::cout << label << " ";
    outPutFile << label << " ";
    for (unsigned int i = 0; i < v.size(); ++i) {
        //std::cout << v[i] << " ";
        outPutFile << std::setprecision(10)<< v[i]<<" " ;
    }

    //std::cout << std::endl;
    outPutFile << std::endl;
}
